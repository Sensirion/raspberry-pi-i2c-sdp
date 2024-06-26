/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * I2C-Generator: 0.2.0
 * Yaml Version: 0.1.0
 * Template Version: 0.7.0-34-gb715f31
 */
/*
 * Copyright (c) 2021, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SDP_I2C_H
#define SDP_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sensirion_config.h"

#define SDP8XX_I2C_ADDRESS_0 0x25
#define SDP8XX_I2C_ADDRESS_1 0x26
#define SDP3X_I2C_ADDRESS_0 0x21
#define SDP3X_I2C_ADDRESS_1 0x22
#define SDP3X_I2C_ADDRESS_2 0x23

#define SDP_I2C_ADDRESS SDP8XX_I2C_ADDRESS_0

/**
 * sdp_start_continuous_measurement_with_mass_flow_t_comp_and_averaging() - This
 * command starts continuous measurements with mass flow temperature
 * compensation and the average till read feature.
 *
 * @note The measurement command must only be sent once, if acknowledged. The
 * command must not be resent or other commands must not be sent until the stop
 * measurement command has been issued. After the start measurement command is
 * sent, the first measurement result is available after 8ms. Small accuracy
 * deviations (few % of reading) can occur during the next 12ms. The measured
 * values are updated every 0.5ms and can be read using the read measurement
 * interface.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t
sdp_start_continuous_measurement_with_mass_flow_t_comp_and_averaging(void);

/**
 * sdp_start_continuous_measurement_with_mass_flow_t_comp() - This command
 * starts continuous measurements with mass flow temperature compensation.
 *
 * @note The measurement command must only be sent once, if acknowledged. The
 * command must not be resent or other commands must not be sent until the stop
 * measurement command has been issued. After the start measurement command is
 * sent, the first measurement result is available after 8ms. Small accuracy
 * deviations (few % of reading) can occur during the next 12ms. The measured
 * values are updated every 0.5ms and can be read using the read measurement
 * interface.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sdp_start_continuous_measurement_with_mass_flow_t_comp(void);

/**
 * sdp_start_continuous_measurement_with_diff_pressure_t_comp_and_averaging() -
 * This command starts continuous measurements with differential pressure
 * temperature compensation and the average till read feature.
 *
 * @note The measurement command must only be sent once, if acknowledged. The
 * command must not be resent or other commands must not be sent until the stop
 * measurement command has been issued. After the start measurement command is
 * sent, the first measurement result is available after 8ms. Small accuracy
 * deviations (few % of reading) can occur during the next 12ms. The measured
 * values are updated every 0.5ms and can be read using the read measurement
 * interface.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t
sdp_start_continuous_measurement_with_diff_pressure_t_comp_and_averaging(void);

/**
 * sdp_start_continuous_measurement_with_diff_pressure_t_comp() - This command
 * starts continuous measurements with differential pressure temperature
 * compensation.
 *
 * @note The measurement command must only be sent once, if acknowledged. The
 * command must not be resent or other commands must not be sent until the stop
 * measurement command has been issued. After the start measurement command is
 * sent, the first measurement result is available after 8ms. Small accuracy
 * deviations (few % of reading) can occur during the next 12ms. The measured
 * values are updated every 0.5ms and can be read using the read measurement
 * interface.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sdp_start_continuous_measurement_with_diff_pressure_t_comp(void);

/**
 * sdp_stop_continuous_measurement() - This command stops the continuous
 * measurement and puts the sensor in idle mode. It powers off the heater and
 * makes the sensor receptive to another command after 500us. The Stop command
 * is also required when switching between different continuous measurement
 * commands.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sdp_stop_continuous_measurement(void);

/**
 * sdp_trigger_measurement_with_mass_flow_t_comp_and_averaging() - This command
 * triggers a single shot measurement with mass flow temperature compensation.
 *
 * @note During a triggered measurement the sensor measures both differential
 * pressure and temperature. The measurement starts directly after the command
 * has been sent. The command needs to be repeated with every measurement.
 * During the 45ms that the sensor is measuring, no command can be sent to the
 * sensor. After the 45ms the result can be read out and any command can be sent
 * to the sensor.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sdp_trigger_measurement_with_mass_flow_t_comp_and_averaging(void);

/**
 * sdp_trigger_measurement_with_diff_pressure_t_comp() - This command triggers a
 * single shot measurement with differential pressure temperature compensation.
 *
 * @note During a triggered measurement the sensor measures both differential
 * pressure and temperature. The measurement starts directly after the command
 * has been sent. The command needs to be repeated with every measurement.
 * During the 45ms that the sensor is measuring, no command can be sent to the
 * sensor. After the 45ms the result can be read out and any command can be sent
 * to the sensor.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sdp_trigger_measurement_with_diff_pressure_t_comp(void);

/**
 * sdp_read_measurement_raw() - After a start continuous measurement commands,
 * the measurement results can be read out at most every 0.5ms. After a
 * triggered measurement command, the results can be read out when the sensor is
 * finished with the measurement. This method returns raw sensor values.
 * The temperature and scale factor don’t need to be read out (every time).
 * The read sequence can be aborted by a NACK and a
 * STOP condition. The scale factor is for differential pressure in Pascal.
 *
 * @param differential_pressure The digital calibrated differential pressure
 * signal read from the sensor is a signed integer number (two's complement
 * number). The integer value can be converted to the physical value by dividing
 * it by the scale factor. differential pressure in Pascal = sensor output /
 * scale factor
 *
 * @param temperature The digital calibrated temperature signal read from the
 * sensor is a signed integer number (two's complement number). The integer
 * value can be converted to the physical value by dividing it by a scale factor
 * of 200. temperature in °C = sensor output / 200
 *
 * @param scaling_factor Scaling factor differential pressure
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sdp_read_measurement_raw(int16_t* differential_pressure,
                                 int16_t* temperature, int16_t* scaling_factor);

/**
 * sdp_read_measurement() - After a start continuous measurement commands, the
 * measurement results can be read out at most every 0.5ms. After a triggered
 * measurement command, the results can be read out when the sensor is finished
 * with the measurement. This method returns the measurement values in physical
 * units.
 *
 * @param differential_pressure measurement value for differential pressure in
 * Pascal
 *
 * @param temperature measurement value for temperature in °C
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sdp_read_measurement(float* differential_pressure, float* temperature);

/**
 * sdp_enter_sleep_mode() - In sleep mode the sensor uses the minimum amount of
 * current. The mode can only be entered from idle mode, i.e. when the sensor is
 * not measuring. This mode is particularly useful for battery operated devices.
 * To minimize the current in this mode, the complexity of the sleep mode
 * circuit has been reduced as much as possible, which is mainly reflected by
 * the way the sensor exits the sleep mode. In sleep mode the sensor cannot be
 * soft reset.
 *
 * @note Triggered mode: the sleep command can be sent after the result have
 * been read out and the sensor is in idle mode. Continuous mode: the sleep
 * command can be sent after a stop continuous measurement command has been
 * issued and the sensor is in idle mode.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sdp_enter_sleep_mode(void);

/**
 * sdp_exit_sleep_mode() - Exit sleep mode. See the data sheet for more detailed
 * information
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sdp_exit_sleep_mode(void);

/**
 * sdp_prepare_product_identifier() - Prepare for reading the product identifier
 * and sensor serial number.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sdp_prepare_product_identifier(void);

/**
 * sdp_read_product_identifier() - Read the product identifier and serial number
 * of the sensor.
 *
 * @note Make sure to call 'prepare product identifier' immediately before.
 *
 * @param product_number 32 bit unique product and revision number. The number
 * is listed in the datasheet. Note that the last 8 bits are the revision number
 * and can be subject to change.
 *
 * @param serial_number 64-bit unique serial number
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sdp_read_product_identifier(uint32_t* product_number,
                                    uint8_t* serial_number,
                                    uint8_t serial_number_size);

#ifdef __cplusplus
}
#endif

#endif /* SDP_I2C_H */
