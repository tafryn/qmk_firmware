#pragma once

// Configure the global tapping term (default: 200ms)
#undef TAPPING_TERM
#define TAPPING_TERM 256

// Prevent normal rollover on alphas from accidentally triggering mods
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Adjust the number of taps to toggle (default: 5)
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

