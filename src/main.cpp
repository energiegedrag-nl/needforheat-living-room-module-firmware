#include <generic_esp_32.hpp>
#include <generic_tasks.hpp>
#include <scheduler.hpp>
#include <scd41_task.hpp>
#include <presence_detection.hpp>
#include <scd41.h>
#include <util/buttons.hpp>
#include <util/buzzer.hpp>
#include <util/nvs.hpp>

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

constexpr const char *DEVICE_TYPE_NAME = "twomes-co2-occupancy-scd41-m5coreink-firmware";

// CO2 calibration: a deliberate action before provisioning (GenericESP32Firmware::SetPreProvisioningAction), once per
// flash, on battery, outdoors. Not on a button any more: a long press "up" (GPIO 37) clashed with the presence menu,
// and a forced recalibration indoors by accident shifts the sensor by hundreds of ppm for good.
#ifdef M5STACK_COREINK // the calibration uses the screen and the battery monitor of the CoreInk
namespace
{
	constexpr const char *CAL_NVS = "lrm";
	constexpr const char *CAL_KEY = "co2cal"; // correction in ppm of the last calibration; present: done
	constexpr uint16_t OUTDOOR_PPM = 420;	  // outdoor air in 2026 (global mean ~425, background stations ~420)
	constexpr int READ_S = 5;				  // the sensor gives a new value every 5 s in periodic mode
	constexpr int WARMUP_S = 5 * 60;		  // settle (sensor and box) before judging
	constexpr int WINDOW_S = 3 * 60;		  // stable for 3 minutes, as the datasheet asks before a forced recalibration
	constexpr int MAX_S = 30 * 60;
	constexpr int STABLE_PPM = 30;			  // max - min within the window
	constexpr int PLAUSIBLE_MIN = 370, PLAUSIBLE_MAX = 520; // outdoors; indoors is usually higher

	std::string Signed(int value) { return (value > 0 ? "+" : "") + std::to_string(value); }

	std::string Clock(int seconds)
	{
		char text[8];
		snprintf(text, sizeof(text), "%d:%02d", seconds / 60, seconds % 60);
		return text;
	}

	void Show(const std::string &title, std::vector<std::string> lines, const std::string &footer, int holdSeconds = 0)
	{
		GenericESP32Firmware::DisplayMessage(title, lines, footer);
		if (holdSeconds > 0)
			vTaskDelay(pdMS_TO_TICKS(holdSeconds * 1000));
	}

	void CalibrateOutdoors()
	{
		const char *title = "CO₂ kalibreren";
		std::string done;
		if (NVS::Get(CAL_NVS, CAL_KEY, done) == ESP_OK)
		{
			Show(title, {"Al gekalibreerd (correctie " + done + " ppm).", "Opnieuw kan na volledig wissen en flashen."}, "", 20);
			return;
		}

		co2_init(SCD41_ADDR); // also keeps the automatic self-calibration (ASC) off
		co2_start_periodic(SCD41_ADDR);
		Buzzer::Buzz(200);

		std::vector<int> window;
		int seconds = 0, last = 0;
		bool stable = false;
		for (; seconds <= MAX_S; seconds += READ_S)
		{
			vTaskDelay(pdMS_TO_TICKS(READ_S * 1000));
			uint16_t values[3] = {};
			if (co2_read_measurement(SCD41_ADDR, values) != ESP_OK)
				continue; // no new value yet or a CRC error: try again
			last = values[0];
			window.push_back(last);
			if (window.size() > WINDOW_S / READ_S)
				window.erase(window.begin());
			if (seconds % 30 == 0)
				Show(title, {"Blijf buiten liggen.", "Nu " + std::to_string(last) + " ppm."}, Clock(seconds));
			if (seconds >= WARMUP_S && window.size() == WINDOW_S / READ_S)
			{
				auto [lo, hi] = std::minmax_element(window.begin(), window.end());
				int mean = 0;
				for (int v : window)
					mean += v;
				mean /= static_cast<int>(window.size());
				if (*hi - *lo <= STABLE_PPM && mean >= PLAUSIBLE_MIN && mean <= PLAUSIBLE_MAX)
				{
					stable = true;
					break;
				}
			}
		}

		co2_stop_periodic(SCD41_ADDR);
		if (!stable)
		{
			Buzzer::Buzz(1000, 3);
			Show(title, {"Mislukt: niet stabiel of niet buiten (" + std::to_string(last) + " ppm).", "Er is niets aangepast."}, "", 60);
			return;
		}

		int16_t correction = 0;
		if (co2_force_recalibration_to(SCD41_ADDR, OUTDOOR_PPM, &correction) != ESP_OK)
		{
			Buzzer::Buzz(1000, 3);
			Show(title, {"Mislukt: de sensor weigerde.", "Er is niets aangepast."}, "", 60);
			return;
		}
		NVS::Set(CAL_NVS, CAL_KEY, Signed(correction));
		Buzzer::Buzz(200, 2);
		Show(title, {"Gekalibreerd op " + std::to_string(OUTDOOR_PPM) + " ppm.", "Correctie " + Signed(correction) + " ppm."}, Clock(seconds), 60);
	}
} // namespace
#endif // M5STACK_COREINK

extern "C" void app_main(void)
{
	// Configure the buzzer.
	Buzzer::Configure();

	// Add the SCD41 task to the scheduler.
	Scheduler::AddTask(SCD41Task, "SCD41 task", 4096, nullptr, 1, Scheduler::Interval::MINUTES_10);

	// Add the generic tasks to the scheduler,
	// heartbeat, timesync and optionally presence detection and OTA updates.
	GenericTasks::AddTasksToScheduler();

	// Initialize generic firmware.
	// Short name for people on the provisioning screen (a box can hold several CoreInks).
	GenericESP32Firmware::SetShortName("Woonkamer"); // as in needforheat-manuals short_names.json
#ifdef M5STACK_COREINK
	GenericESP32Firmware::SetPreProvisioningAction("CO₂ kalibreren", "Ligt de module buiten, in de open lucht?", CalibrateOutdoors);
#endif
	GenericESP32Firmware::Initialize(DEVICE_TYPE_NAME);

	// Start the scheduler.
	Scheduler::Start();
}
