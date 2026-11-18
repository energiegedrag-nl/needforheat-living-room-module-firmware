#include <generic_esp_32.hpp>
#include <generic_tasks.hpp>
#include <scheduler.hpp>
#include <scd41_task.hpp>
#include <presence_detection.hpp>
#include <scd41.h>
#include <util/buttons.hpp>
#include <util/buzzer.hpp>

constexpr const char *DEVICE_TYPE_NAME = "twomes-co2-occupancy-scd41-m5coreink-firmware";

// CO2 calibration is no longer on a button: a long press "up" (GPIO 37) clashed with "up" in the presence menu, and a
// forced recalibration indoors (by accident) shifts the sensor by hundreds of ppm for good. A deliberate calibration
// before provisioning is being designed (TODO.md, co2cal).

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
	GenericESP32Firmware::Initialize(DEVICE_TYPE_NAME);

	// Start the scheduler.
	Scheduler::Start();
}
