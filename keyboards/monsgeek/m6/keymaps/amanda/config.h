/* Copyright (C) 2023 jonylee@hfd
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

#define NKRO_DEFAULT_ON true

#define TAPPING_TERM 180
#define TAPPING_TOGGLE 2

// If you press a Mod Tap key, tap another key (press and release) and then
// release the Mod Tap key, all within the tapping term, it will output the
// tapping function for both keys.
#define PERMISSIVE_HOLD

// Time between cursor movements in milliseconds.
// #undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16 // set to monitor refresh rate: (1 / 60Hz)

// Pressing the Shift key continues Caps Word and inverts the shift state.
#define CAPS_WORD_INVERT_ON_SHIFT

// Turn off RGB after boot
// #define RGB_DISABLE_TIMEOUT 1

// Disable all auto effects at startup
// #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_NONE
// #define RGB_MATRIX_STARTUP_HUE 0
// #define RGB_MATRIX_STARTUP_SAT 0
// #define RGB_MATRIX_STARTUP_VAL 0
// #define RGB_MATRIX_STARTUP_SPD 0
