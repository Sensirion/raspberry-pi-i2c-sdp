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

#include "sdp_i2c.h"
#include "sensirion_common.h"
#include "sensirion_i2c.h"
#include "sensirion_i2c_hal.h"

#define TEMPERATURE_DIVISION_FACTOR 200

static float convert_temperature_raw_to_celsius(int16_t temperature_raw) {
    return (float)temperature_raw / TEMPERATURE_DIVISION_FACTOR;
}

int16_t
sdp_start_continuous_measurement_with_mass_flow_t_comp_and_averaging(void) {
    int16_t error;
    uint8_t buffer[2];
    uint16_t offset = 0;
    offset = sensirion_i2c_add_command_to_buffer(&buffer[0], offset, 0x3603);

    error = sensirion_i2c_write_data(SDP_I2C_ADDRESS, &buffer[0], offset);
    if (error) {
        return error;
    }
    sensirion_i2c_hal_sleep_usec(10000);
    return NO_ERROR;
}

int16_t sdp_start_continuous_measurement_with_mass_flow_t_comp(void) {
    int16_t error;
    uint8_t buffer[2];
    uint16_t offset = 0;
    offset = sensirion_i2c_add_command_to_buffer(&buffer[0], offset, 0x3608);

    error = sensirion_i2c_write_data(SDP_I2C_ADDRESS, &buffer[0], offset);
    if (error) {
        return error;
    }
    sensirion_i2c_hal_sleep_usec(10000);
    return NO_ERROR;
}

int16_t
sdp_start_continuous_measurement_with_diff_pressure_t_comp_and_averaging(void) {
    int16_t error;
    uint8_t buffer[2];
    uint16_t offset = 0;
    offset = sensirion_i2c_add_command_to_buffer(&buffer[0], offset, 0x3615);

    error = sensirion_i2c_write_data(SDP_I2C_ADDRESS, &buffer[0], offset);
    if (error) {
        return error;
    }
    sensirion_i2c_hal_sleep_usec(10000);
    return NO_ERROR;
}

int16_t sdp_start_continuous_measurement_with_diff_pressure_t_comp(void) {
    int16_t error;
    uint8_t buffer[2];
    uint16_t offset = 0;
    offset = sensirion_i2c_add_command_to_buffer(&buffer[0], offset, 0x361E);

    error = sensirion_i2c_write_data(SDP_I2C_ADDRESS, &buffer[0], offset);
    if (error) {
        return error;
    }
    sensirion_i2c_hal_sleep_usec(10000);
    return NO_ERROR;
}

int16_t sdp_stop_continuous_measurement(void) {
    int16_t error;
    uint8_t buffer[2];
    uint16_t offset = 0;
    offset = sensirion_i2c_add_command_to_buffer(&buffer[0], offset, 0x3FF9);

    error = sensirion_i2c_write_data(SDP_I2C_ADDRESS, &buffer[0], offset);
    if (error) {
        return error;
    }
    sensirion_i2c_hal_sleep_usec(500);
    return NO_ERROR;
}

int16_t sdp_trigger_measurement_with_mass_flow_t_comp_and_averaging(void) {
    int16_t error;
    uint8_t buffer[2];
    uint16_t offset = 0;
    offset = sensirion_i2c_add_command_to_buffer(&buffer[0], offset, 0x3624);

    error = sensirion_i2c_write_data(SDP_I2C_ADDRESS, &buffer[0], offset);
    if (error) {
        return error;
    }
    sensirion_i2c_hal_sleep_usec(45000);
    return NO_ERROR;
}

int16_t sdp_trigger_measurement_with_diff_pressure_t_comp(void) {
    int16_t error;
    uint8_t buffer[2];
    uint16_t offset = 0;
    offset = sensirion_i2c_add_command_to_buffer(&buffer[0], offset, 0x362F);

    error = sensirion_i2c_write_data(SDP_I2C_ADDRESS, &buffer[0], offset);
    if (error) {
        return error;
    }
    sensirion_i2c_hal_sleep_usec(45000);
    return NO_ERROR;
}

int16_t sdp_read_measurement_raw(int16_t* differential_pressure,
                                 int16_t* temperature,
                                 int16_t* scaling_factor) {
    int16_t error;
    uint8_t buffer[9];

    error = sensirion_i2c_read_data_inplace(SDP_I2C_ADDRESS, &buffer[0], 6);
    if (error) {
        return error;
    }
    *differential_pressure = sensirion_common_bytes_to_int16_t(&buffer[0]);
    *temperature = sensirion_common_bytes_to_int16_t(&buffer[2]);
    *scaling_factor = sensirion_common_bytes_to_int16_t(&buffer[4]);
    return NO_ERROR;
}

int16_t sdp_read_measurement(float* differential_pressure, float* temperature) {
    int16_t error;
    int16_t differential_pressure_raw;
    int16_t temperature_raw;
    int16_t scaling_factor;

    error = sdp_read_measurement_raw(&differential_pressure_raw,
                                     &temperature_raw, &scaling_factor);
    if (error) {
        return error;
    }

    *differential_pressure = (float)differential_pressure_raw / scaling_factor;
    *temperature = convert_temperature_raw_to_celsius(temperature_raw);
    return NO_ERROR;
}

int16_t sdp_enter_sleep_mode(void) {
    uint8_t buffer[2];
    uint16_t offset = 0;
    offset = sensirion_i2c_add_command_to_buffer(&buffer[0], offset, 0x3677);

    return sensirion_i2c_write_data(SDP_I2C_ADDRESS, &buffer[0], offset);
}

int16_t sdp_exit_sleep_mode(void) {
    uint8_t buffer[2];
    uint16_t offset = 0;

    sensirion_i2c_write_data(SDP_I2C_ADDRESS, &buffer[0], offset);
    // ignore error, as wakeup is not acknowledged
    sensirion_i2c_hal_sleep_usec(2000);
    return NO_ERROR;
}

int16_t sdp_prepare_product_identifier(void) {
    uint8_t buffer[2];
    uint16_t offset = 0;
    offset = sensirion_i2c_add_command_to_buffer(&buffer[0], offset, 0x367C);

    return sensirion_i2c_write_data(SDP_I2C_ADDRESS, &buffer[0], offset);
}

int16_t sdp_read_product_identifier(uint32_t* product_number,
                                    uint8_t* serial_number,
                                    uint8_t serial_number_size) {
    int16_t error;
    uint8_t buffer[18];
    uint16_t offset = 0;
    offset = sensirion_i2c_add_command_to_buffer(&buffer[0], offset, 0xE102);

    error = sensirion_i2c_write_data(SDP_I2C_ADDRESS, &buffer[0], offset);
    if (error) {
        return error;
    }

    sensirion_i2c_hal_sleep_usec(1000);

    error = sensirion_i2c_read_data_inplace(SDP_I2C_ADDRESS, &buffer[0], 12);
    if (error) {
        return error;
    }
    *product_number = sensirion_common_bytes_to_uint32_t(&buffer[0]);
    sensirion_common_copy_bytes(&buffer[4], serial_number, serial_number_size);
    return NO_ERROR;
}
