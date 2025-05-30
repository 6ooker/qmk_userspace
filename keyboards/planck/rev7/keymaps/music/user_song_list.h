/* Any song or sound without a license explicitly stated is:
 *
 * Copyright 2025 6ooker
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

#include "musical_notes.h"

#undef E1M1_DOOM
#define E1M1_DOOM Q__NOTE(_E3 ), Q__NOTE(_E3 ), Q__NOTE(_E4 ), Q__NOTE(_E3 ), Q__NOTE(_E3 ), Q__NOTE(_D4 ), Q__NOTE(_E3 ), Q__NOTE(_E3 ), Q__NOTE(_C4 ), Q__NOTE(_E3 ), Q__NOTE(_E3 ), Q__NOTE(_BF3), Q__NOTE(_E3 ), Q__NOTE(_E3 ), Q__NOTE(_B3 ), Q__NOTE(_C4 ), Q__NOTE(_E3 ), Q__NOTE(_E3 ), Q__NOTE(_E4 ), Q__NOTE(_E3 ), Q__NOTE(_E3 ), Q__NOTE(_D4 ), Q__NOTE(_E3 ), Q__NOTE(_E3 ), Q__NOTE(_C4 ), Q__NOTE(_E3 ), Q__NOTE(_E3 ), H__NOTE(_BF3),

#undef OLD_SPICE
#define OLD_SPICE Q__NOTE(_A4 ), Q__NOTE(_A4 ), H__NOTE(_B4 ), H__NOTE(_D5 ), H__NOTE(_CS5), Q__NOTE(_E5 ), H__NOTE(_FS5), H__NOTE(_D5 )

#undef IMPERIAL_MARCH
#define IMPERIAL_MARCH HD_NOTE(_A4), HD_NOTE(_A4), HD_NOTE(_A4), QD_NOTE(_F4), QD_NOTE(_C5), HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4), HD_NOTE(_E5), HD_NOTE(_E5), HD_NOTE(_E5), QD_NOTE(_F5), QD_NOTE(_C5), HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4)

#undef BASKET_CASE
#define BASKET_CASE QD_NOTE(_G3), E__NOTE(_F3), E__NOTE(_E3), Q__NOTE(_F3), M__NOTE(_G3, 8+32), Q__NOTE(_REST), Q__NOTE(_B4), Q__NOTE(_C4), Q__NOTE(_B4), E__NOTE(_A4), Q__NOTE(_G3), M__NOTE(_G3, 8+32), Q__NOTE(_REST), Q__NOTE(_B4), Q__NOTE(_C4), Q__NOTE(_B4), E__NOTE(_A4), Q__NOTE(_G3), Q__NOTE(_G3), Q__NOTE(_G3), Q__NOTE(_G3), E__NOTE(_A4), E__NOTE(_C4), QD_NOTE(_B4), HD_NOTE(_B4)

#undef COIN_SOUND
#define COIN_SOUND E__NOTE(_A5  ), HD_NOTE(_E6  ),

#undef ONE_UP_SOUND
#define ONE_UP_SOUND Q__NOTE(_E6  ), Q__NOTE(_G6  ), Q__NOTE(_E7  ), Q__NOTE(_C7  ), Q__NOTE(_D7  ), Q__NOTE(_G7  ),

#undef SONIC_RING
#define SONIC_RING E__NOTE(_E6), E__NOTE(_G6), HD_NOTE(_C7),
 
/* #define ZELDA_PUZZLE 
*     Q__NOTE(_G5),     \
*     Q__NOTE(_FS5),    \
*     Q__NOTE(_DS5),     \
*     Q__NOTE(_A4),    \
*     Q__NOTE(_GS4),     \
*     Q__NOTE(_E5),     \
*     Q__NOTE(_GS5),     \
*     HD_NOTE(_C6),
* 
* #define ZELDA_TREASURE \
*     Q__NOTE(_A4 ), \
*     Q__NOTE(_AS4), \
*     Q__NOTE(_B4 ), \
*     HD_NOTE(_C5 ), \
* 
* #define MARIO_THEME \
*     Q__NOTE(_E5), \
*     H__NOTE(_E5), \
*     H__NOTE(_E5), \
*     Q__NOTE(_C5), \
*     H__NOTE(_E5), \
*     W__NOTE(_G5), \
*     Q__NOTE(_G4),
* 
* #define MARIO_GAMEOVER \
*     HD_NOTE(_C5 ), \
*     HD_NOTE(_G4 ), \
*     H__NOTE(_E4 ), \
*     H__NOTE(_A4 ), \
*     H__NOTE(_B4 ), \
*     H__NOTE(_A4 ), \
*     H__NOTE(_AF4), \
*     H__NOTE(_BF4), \
*     H__NOTE(_AF4), \
*     WD_NOTE(_G4 ),
*/

#undef MARIO_MUSHROOM
#define MARIO_MUSHROOM S__NOTE(_C5 ), S__NOTE(_G4 ), S__NOTE(_C5 ), S__NOTE(_E5 ), S__NOTE(_G5 ), S__NOTE(_C6 ), S__NOTE(_G5 ), S__NOTE(_GS4), S__NOTE(_C5 ), S__NOTE(_DS5), S__NOTE(_GS5), S__NOTE(_DS5), S__NOTE(_GS5), S__NOTE(_C6 ), S__NOTE(_DS6), S__NOTE(_GS6), S__NOTE(_DS6), S__NOTE(_AS4), S__NOTE(_D5 ), S__NOTE(_F5 ), S__NOTE(_AS5), S__NOTE(_D6 ), S__NOTE(_F6 ), S__NOTE(_AS6), S__NOTE(_F6 )
 
/* #define NUMBER_ONE \
*     HD_NOTE(_F4 ), \
*     Q__NOTE(_C5 ), \
*     E__NOTE(_B4 ), \
*     E__NOTE(_C5 ), \
*     E__NOTE(_B4 ), \
*     E__NOTE(_C5 ), \
*     Q__NOTE(_B4 ), \
*     Q__NOTE(_C5 ), \
*     H__NOTE(_AF4), \
*     HD_NOTE(_F4 ), \
*     Q__NOTE(_F4 ), \
*     Q__NOTE(_AF4), \
*     Q__NOTE(_C5 ), \
*     H__NOTE(_DF5), \
*     H__NOTE(_AF4), \
*     H__NOTE(_DF5), \
*     H__NOTE(_EF5), \
*     Q__NOTE(_C5 ), \
*     Q__NOTE(_DF5), \
*     Q__NOTE(_C5 ), \
*     Q__NOTE(_DF5), \
*     H__NOTE(_C5 ),
* 
* #define VICTORY_FANFARE_SHORT \
*     ED_NOTE(_C6), \
*     ED_NOTE(_C6), \
*     ED_NOTE(_C6), \
*     ED_NOTE(_C6), \
*     W__NOTE(_REST), \
*     QD_NOTE(_GS5), \
*     QD_NOTE(_AS5), \
*     Q__NOTE(_C6), \
*     Q__NOTE(_AS5), \
*     Q__NOTE(_C6), \
* 
* #define ALL_STAR \
*     H__NOTE(_AS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), H__NOTE(_FS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), \
*     H__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_FS4), QD_NOTE(_AS4), \
*     H__NOTE(_AS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), H__NOTE(_FS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), \
*     H__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_AS4), H__NOTE(_REST),\
*     W__NOTE(_AS4), W__NOTE(_CS5), H__NOTE(_B4),  H__NOTE(_CS5), H__NOTE(_DS5), W__NOTE(_FS5), \
*     H__NOTE(_GS5), W__NOTE(_GS5), H__NOTE(_FS4), H__NOTE(_FS4), H__NOTE(_GS4), H__NOTE(_FS4), \
*     H__NOTE(_AS4), W__NOTE(_GS4), W__NOTE(_GS4), W__NOTE(_FS4), W__NOTE(_GS4), \
*     H__NOTE(_AS4), WD_NOTE(_DS4)
* 
* #define RICK_ROLL      \
*     Q__NOTE(_F4),      \
*     Q__NOTE(_G4),      \
*     Q__NOTE(_BF4),     \
*     Q__NOTE(_G4),      \
*     HD_NOTE(_D5),      \
*     HD_NOTE(_D5),      \
*     W__NOTE(_C5),      \
*     S__NOTE(_REST),    \
*     Q__NOTE(_F4),      \
*     Q__NOTE(_G4),      \
*     Q__NOTE(_BF4),     \
*     Q__NOTE(_G4),      \
*     HD_NOTE(_C5),      \
*     HD_NOTE(_C5),      \
*     W__NOTE(_BF4),     \
*     S__NOTE(_REST),    \
*     Q__NOTE(_F4),      \
*     Q__NOTE(_G4),      \
*     Q__NOTE(_BF4),     \
*     Q__NOTE(_G4),      \
*     W__NOTE(_BF4),     \
*     H__NOTE(_C5),      \
*     H__NOTE(_A4),      \
*     H__NOTE(_A4),      \
*     H__NOTE(_G4),      \
*     H__NOTE(_F4),      \
*     H__NOTE(_F4),      \
*     W__NOTE(_C5),      \
*     W__NOTE(_BF4),
*/
