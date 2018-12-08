/*
 * HomeKit Custom Characteristics
 * 
 * Copyright 2018 José A. Jiménez (@RavenSystem)
 *  
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __HOMEKIT_CUSTOM_CHARACTERISTICS__
#define __HOMEKIT_CUSTOM_CHARACTERISTICS__

#define HOMEKIT_CUSTOM_UUID(value) (value "-03a1-4971-92bf-af2b7d833922")

#define HOMEKIT_SERVICE_CUSTOM_SETUP HOMEKIT_CUSTOM_UUID("F00000FF")

#define HOMEKIT_CHARACTERISTIC_CUSTOM_SHOW_SETUP HOMEKIT_CUSTOM_UUID("00000001")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_SHOW_SETUP(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_SHOW_SETUP, \
    .description = "Show Setup", \
    .format = homekit_format_bool, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .value = HOMEKIT_BOOL_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_REBOOT_DEVICE HOMEKIT_CUSTOM_UUID("00000002")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_REBOOT_DEVICE(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_REBOOT_DEVICE, \
    .description = "Reboot", \
    .format = homekit_format_bool, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .value = HOMEKIT_BOOL_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_OTA_UPDATE HOMEKIT_CUSTOM_UUID("F0000101")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_OTA_UPDATE(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_OTA_UPDATE, \
    .description = "Firmware Update", \
    .format = homekit_format_bool, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .value = HOMEKIT_BOOL_(_value), \
    ##__VA_ARGS__

/* Device Types
 1. Switch Basic
 2. Switch Dual
 3. Socket + Button
 4. Switch 4ch
 5. Thermostat
 6. Switch Basic + TH Sensor
 7. Water Valve
 8. Garage Door
 9. Socket + Button + TH Sensor
 10. ESP01 Switch + Button
 11. Switch 3ch
 */
#define HOMEKIT_CHARACTERISTIC_CUSTOM_DEVICE_TYPE HOMEKIT_CUSTOM_UUID("F0000102")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_DEVICE_TYPE(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_DEVICE_TYPE, \
    .description = "Device Type", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .min_value = (float[]) {1}, \
    .max_value = (float[]) {12}, \
    .min_step = (float[]) {1}, \
    .valid_values = { \
    .count = 12, \
    .values = (uint8_t[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, \
    }, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_DEVICE_TYPE_NAME HOMEKIT_CUSTOM_UUID("F0000103")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_DEVICE_TYPE_NAME(revision, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_DEVICE_TYPE_NAME, \
    .description = "Device Type", \
    .format = homekit_format_string, \
    .permissions = homekit_permissions_paired_read, \
    .value = HOMEKIT_STRING_(revision), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_GPIO14_TOGGLE HOMEKIT_CUSTOM_UUID("F0000104")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_GPIO14_TOGGLE(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_GPIO14_TOGGLE, \
    .description = "GPIO14 Toggle", \
    .format = homekit_format_bool, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .value = HOMEKIT_BOOL_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_DHT_SENSOR_TYPE HOMEKIT_CUSTOM_UUID("F0000105")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_DHT_SENSOR_TYPE(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_DHT_SENSOR_TYPE, \
    .description = "Sensor Type", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .min_value = (float[]) {1}, \
    .max_value = (float[]) {3}, \
    .min_step = (float[]) {1}, \
    .valid_values = { \
    .count = 3, \
    .values = (uint8_t[]) {1, 2, 3}, \
    }, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_VALVE_TYPE HOMEKIT_CUSTOM_UUID("F0000106")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_VALVE_TYPE(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_VALVE_TYPE, \
    .description = "Valve Type", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {3}, \
    .min_step = (float[]) {1}, \
    .valid_values = { \
    .count = 4, \
    .values = (uint8_t[]) {0, 1, 2, 3}, \
    }, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_TH_PERIOD HOMEKIT_CUSTOM_UUID("F0000107")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_TH_PERIOD(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_TH_PERIOD, \
    .description = "TH Period", \
    .format = homekit_format_uint8, \
    .unit = homekit_unit_seconds, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .min_value = (float[]) {3}, \
    .max_value = (float[]) {60}, \
    .min_step = (float[]) {1}, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_GARAGEDOOR_HAS_STOP HOMEKIT_CUSTOM_UUID("F0000110")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_GARAGEDOOR_HAS_STOP(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_GARAGEDOOR_HAS_STOP, \
    .description = "Has stop step", \
    .format = homekit_format_bool, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .value = HOMEKIT_BOOL_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_GARAGEDOOR_SENSOR_CLOSE_NC HOMEKIT_CUSTOM_UUID("F0000111")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_GARAGEDOOR_SENSOR_CLOSE_NC(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_GARAGEDOOR_SENSOR_CLOSE_NC, \
    .description = "Sensor Close NC", \
    .format = homekit_format_bool, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .value = HOMEKIT_BOOL_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_GARAGEDOOR_SENSOR_OPEN_NC HOMEKIT_CUSTOM_UUID("F0000112")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_GARAGEDOOR_SENSOR_OPEN_NC(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_GARAGEDOOR_SENSOR_OPEN_NC, \
    .description = "Sensor Open NC", \
    .format = homekit_format_bool, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .value = HOMEKIT_BOOL_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_GARAGEDOOR_HAS_SENSOR_OPEN HOMEKIT_CUSTOM_UUID("F0000113")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_GARAGEDOOR_HAS_SENSOR_OPEN(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_GARAGEDOOR_HAS_SENSOR_OPEN, \
    .description = "Has Opened Sensor", \
    .format = homekit_format_bool, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .value = HOMEKIT_BOOL_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_GARAGEDOOR_WORKINGTIME HOMEKIT_CUSTOM_UUID("F0000114")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_GARAGEDOOR_WORKINGTIME(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_GARAGEDOOR_WORKINGTIME, \
    .description = "Working time", \
    .format = homekit_format_uint8, \
    .unit = homekit_unit_seconds, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .min_value = (float[]) {3}, \
    .max_value = (float[]) {90}, \
    .min_step = (float[]) {1}, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_GARAGEDOOR_CONTROL_WITH_BUTTON HOMEKIT_CUSTOM_UUID("F0000115")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_GARAGEDOOR_CONTROL_WITH_BUTTON(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_GARAGEDOOR_CONTROL_WITH_BUTTON, \
    .description = "With Button-Control", \
    .format = homekit_format_bool, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .value = HOMEKIT_BOOL_(_value), \
    ##__VA_ARGS__

/* Switch Initial State
 0. ON
 1. OFF
 2. Last state
 3. Opposite to last state
 */
#define HOMEKIT_CHARACTERISTIC_CUSTOM_INIT_STATE_SW1 HOMEKIT_CUSTOM_UUID("F0000501")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_INIT_STATE_SW1(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_INIT_STATE_SW1, \
    .description = "Init State SW1", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {3}, \
    .min_step = (float[]) {1}, \
    .valid_values = { \
    .count = 4, \
    .values = (uint8_t[]) {0, 1, 2, 3}, \
    }, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_INIT_STATE_SW2 HOMEKIT_CUSTOM_UUID("F0000502")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_INIT_STATE_SW2(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_INIT_STATE_SW2, \
    .description = "Init State SW2", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {3}, \
    .min_step = (float[]) {1}, \
    .valid_values = { \
    .count = 4, \
    .values = (uint8_t[]) {0, 1, 2, 3}, \
    }, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_INIT_STATE_SW3 HOMEKIT_CUSTOM_UUID("F0000503")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_INIT_STATE_SW3(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_INIT_STATE_SW3, \
    .description = "Init State SW3", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {3}, \
    .min_step = (float[]) {1}, \
    .valid_values = { \
    .count = 4, \
    .values = (uint8_t[]) {0, 1, 2, 3}, \
    }, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_INIT_STATE_SW4 HOMEKIT_CUSTOM_UUID("F0000504")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_INIT_STATE_SW4(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_INIT_STATE_SW4, \
    .description = "Init State SW4", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {3}, \
    .min_step = (float[]) {1}, \
    .valid_values = { \
    .count = 4, \
    .values = (uint8_t[]) {0, 1, 2, 3}, \
    }, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

/* Thermostat Initial State
 0. OFF
 1. Heat
 2. Cool
 3. Last State
 */
#define HOMEKIT_CHARACTERISTIC_CUSTOM_INIT_STATE_TH HOMEKIT_CUSTOM_UUID("F0000510")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_INIT_STATE_TH(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_INIT_STATE_TH, \
    .description = "Init State TH", \
    .format = homekit_format_uint8, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {3}, \
    .min_step = (float[]) {1}, \
    .valid_values = { \
    .count = 4, \
    .values = (uint8_t[]) {0, 1, 2, 3}, \
    }, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

// ---------------------

#define HOMEKIT_CHARACTERISTIC_CUSTOM_PING_CHECK HOMEKIT_CUSTOM_UUID("F0000201")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_PING_CHECK(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_PING_CHECK, \
    .description = "Ping check", \
    .format = homekit_format_bool, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .value = HOMEKIT_BOOL_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_PING_IP HOMEKIT_CUSTOM_UUID("F0000202")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_PING_IP(text, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_PING_IP, \
    .description = "Ping IP Address", \
    .format = homekit_format_string, \
    .permissions = homekit_permissions_paired_read \
    .value = HOMEKIT_STRING_(text), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_PING_IP_SET HOMEKIT_CUSTOM_UUID("F0000203")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_PING_IP_SET(text, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_PING_IP_SET, \
    .description = "Set Ping IP", \
    .format = homekit_format_string, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .value = HOMEKIT_STRING_(text), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_BOOLTEST HOMEKIT_CUSTOM_UUID("A0000001")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_BOOLTEST(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_BOOLTEST, \
    .description = "Bool Test", \
    .format = homekit_format_bool, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .value = HOMEKIT_BOOL_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_FLOATTEST HOMEKIT_CUSTOM_UUID("A00000003")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_FLOATTEST(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_FLOATTEST, \
    .description = "Float Test", \
    .format = homekit_format_float, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {25}, \
    .min_step = (float[]) {0.1}, \
    .value = HOMEKIT_FLOAT_(_value), \
    ##__VA_ARGS__

#define HOMEKIT_CHARACTERISTIC_CUSTOM_STRINGTEST HOMEKIT_CUSTOM_UUID("A00000004")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_STRINGTEST(revision, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_STRINGTEST, \
    .description = "String Test", \
    .format = homekit_format_string, \
    .permissions = homekit_permissions_paired_read, \
    .value = HOMEKIT_STRING_(revision), \
    ##__VA_ARGS__


#define HOMEKIT_CHARACTERISTIC_CUSTOM_POWDELAY HOMEKIT_CUSTOM_UUID("A0000005")
#define HOMEKIT_DECLARE_CHARACTERISTIC_CUSTOM_POWDELAY(_value, ...) \
    .type = HOMEKIT_CHARACTERISTIC_CUSTOM_POWDELAY, \
    .description = "POW Delay (0 disabled)", \
    .format = homekit_format_uint8, \
    .unit = homekit_unit_seconds, \
    .permissions = homekit_permissions_paired_read \
    | homekit_permissions_paired_write \
    | homekit_permissions_notify, \
    .min_value = (float[]) {0}, \
    .max_value = (float[]) {60}, \
    .min_step = (float[]) {5}, \
    .value = HOMEKIT_UINT8_(_value), \
    ##__VA_ARGS__

#endif
