/* Copyright 2025 6ooker <erik@katzenberger.cloud>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3
#define I2C_DRIVER I2CD1

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define IS31FL3737_I2C_ADDRESS_1 IS31FL3737_I2C_ADDRESS_GND
#define IS31FL3737_I2C_ADDRESS_2 IS31FL3737_I2C_ADDRESS_VCC

#undef TAPPING_TERM
#define TAPPING_TERM 220

#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT
#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 350

#ifdef RGB_MATRIX_ENABLE
#    define USB_SUSPEND_WAKEUP_DELAY 5000
#endif

#ifdef MANUFACTURER
#    undef MANUFACTURER
#endif
#define MANUFACTURER "6ooker"

#ifdef PRODUCT
#    undef PRODUCT
#endif
#define PRODUCT "Tofu65 2.0"

#ifdef DEVICE_VER
#    undef DEVICE_VER
#endif
#define DEVICE_VER 0x0100

#define EXTRA_SHORT_COMBOS
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
