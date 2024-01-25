#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// #define PREVENT_STUCK_MODIFIERS

// TAPPING_TERM defines how long a TAP vs HOLD is
#undef TAPPING_TERM
#define TAPPING_TERM 180
#define TAPPING_TOGGLE 2

// If you press a Mod Tap key, tap another key (press and release) and then
// release the Mod Tap key, all within the tapping term, it will output the
// tapping function for both keys.
// #define PERMISSIVE_HOLD

// This is specific to how I plug in my keyb?...
//  So I could plug it in to the right side if I wanted to.
#define MASTER_LEFT
// #define MASTER_RIGHT

// #define EE_HANDS
//  Rows are doubled-up

// Direct Copy
#define USE_SERIAL