/**
 * Library for reading the SCD41 CO2 sensor on the Twomes room sensor node
 *
 * Author: Sjors
 * Date: July 2021
 */

#ifndef _TWOMES_CO2SENSOR_H
#define _TWOMES_CO2SENSOR_H

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#include "driver/i2c.h"
#include "driver/gpio.h"
#include <i2c_hal_port_1.h>

#define SCD41_INIT_DELAY_MS 1000        // milliseconds
#define SCD41_WAIT_MS 2                 // milliseconds
#define SCD41_SINGLE_SHOT_DELAY_MS 5000 // ms

#define SCD41_ADDR 0x62



void co2_init(uint8_t address);

/** Temperature offset for single shots every 10 minutes (factory 4 °C; measured 2.5 °C too low on 18-11-2026). */
#define SCD41_TEMPERATURE_OFFSET_C 1.5f

/** Set the temperature offset (°C) the sensor subtracts; also corrects the relative humidity it computes. */
void co2_set_temperature_offset(uint8_t address, float celsius);

/**
 * CRC8 code taken from Sensirion SCD41 Datasheet: https://nl.mouser.com/datasheet/2/682/Sensirion_CO2_Sensors_SCD4x_Datasheet-2321195.pdf
 * @brief calculate the CRC for an SCD41 I2C message
 *
 * @param data pointer to the received i2c data
 * @param count size of the buffer
 *
 * @return calculated CRC8
 */
uint8_t scd41_crc8(const uint8_t *data, uint16_t count);

/**
 * @brief read the serial number of the CO2 sensor
 *
 * @param address i2c address of the device
 *
 * @return the serial number
 */
uint64_t co2_get_serial(uint8_t address);

/**
 * @brief disable the SCD41 ASC (Automatic Self Calibration)
 * Device performs a read immeadiately after to check for disable success
 * @param address i2c address of the device
 *
 * @return value of ASC after write (0 == success)
 */
uint8_t co2_disable_asc(uint8_t address);

/**
 * @brief Forced recalibration (FRC) to target_ppm. Before: periodic mode for at least 3 minutes at that concentration,
 * then co2_stop_periodic. correction is the change the sensor applied, in ppm.
 */
esp_err_t co2_force_recalibration_to(uint8_t address, uint16_t target_ppm, int16_t *correction);

/** Start periodic measurement (a new value every 5 s). */
esp_err_t co2_start_periodic(uint8_t address);

/** Stop periodic measurement; waits the 500 ms the sensor needs. */
esp_err_t co2_stop_periodic(uint8_t address);

/** Read the latest measurement (CO2, T, RH raw) without starting one (periodic mode). */
esp_err_t co2_read_measurement(uint8_t address, uint16_t *buffer);

/**
 * send singleshot command, sleep for the conversion time and read the output \n
 * SLEEPS FOR 5 SECONDS IN LIGHT SLEEP MODE \n
 *
 * @param address i2c address
 * @param buffer buffer to hold the read data in (uint16_t[3])
 * 
 * @returns ESP error.
 */
esp_err_t co2_read(uint8_t address, uint16_t *buffer);

/**
 * @brief convert raw temp value to degrees Celsius
 *
 * @param raw the raw temperature value
 *
 * @return temperature in degrees Celsius
 */
float scd41_temp_raw_to_celsius(uint16_t);

/**
 * @brief convert raw RH value to humidity percentage
 *
 * @param raw the raw RH value
 *
 * @return Humidity in percent
 */
float scd41_rh_raw_to_fraction(uint16_t raw);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_TWOMES_CO2SENSOR_H
