// Copyright 2023 rik (@6ooker)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define MATRIX_COL_PINS { GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP19, GP20, GP18 }
#define MATRIX_ROW_PINS { GP29, GP28, GP27, GP26 }

#define DIODE_DIRECTION COL2ROW

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
