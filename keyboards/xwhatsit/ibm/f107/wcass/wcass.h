/* Copyright 2020 Purdea Andrei
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

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT_102key_ansi( \
    k_3_1, k_3_2,   k_2_3, k_1_3, k_1_4, k_2_5, k_1_5, k_2_6, k_1_6, k_2_7, k_1_7, k_2_8, k_1_8, k_2_9, k_1_9, k_1_10,        k_1_11, k_2_12, k_1_12,     k_1_13, k_1_14, k_2_15, k_1_15, \
    k_4_1, k_4_2,   k_3_3,     k_2_4, k_3_4, k_4_5, k_3_5, k_4_6, k_3_6, k_4_7, k_3_7, k_4_8, k_3_8, k_3_9, k_3_10, k_4_10,   k_3_11, k_4_12, k_3_12,     k_3_13, k_3_14, k_2_14, k_3_15, \
    k_5_1, k_5_2,   k_4_3,       k_4_4, k_5_4, k_6_5, k_5_5, k_6_6, k_5_6, k_5_7, k_6_7, k_6_8, k_5_8, k_5_9, k_5_10,         k_5_11, k_4_11, k_5_12,     k_5_13, k_4_14, k_5_14, \
    k_6_1, k_6_2,   k_5_3,           k_7_4, k_6_4, k_7_5, k_8_5, k_7_6, k_7_7, k_8_7, k_8_8, k_7_8, k_6_9, k_7_10,            k_6_11, k_6_12, k_7_12,     k_7_13, k_6_13, k_6_14, k_7_15, \
    k_7_1, k_7_2,   k_8_3,       k_7_3,  k_8_4,                     k_8_6,                      k_8_9, k_7_9, k_8_10,         k_8_11, k_7_11, k_8_12,     k_8_14        , k_7_14 \
) \
{ \
    { k_6_1,  k_6_2,  KC_NO,  k_6_4,  k_6_5,  k_6_6,  k_6_7,  k_6_8,  k_6_9,  KC_NO, k_6_11, k_6_12, k_6_13, k_6_14,  KC_NO}, \
    { k_7_1,  k_7_2,  k_7_3,  k_7_4,  k_7_5,  k_7_6,  k_7_7,  k_7_8,  k_7_9, k_7_10, k_7_11, k_7_12, k_7_13, k_7_14, k_7_15}, \
    { k_5_1,  k_5_2,  k_5_3,  k_5_4,  k_5_5,  k_5_6,  k_5_7,  k_5_8,  k_5_9, k_5_10, k_5_11, k_5_12, k_5_13, k_5_14,  KC_NO}, \
    { KC_NO,  KC_NO,  k_8_3,  k_8_4,  k_8_5,  k_8_6,  k_8_7,  k_8_8,  k_8_9, k_8_10, k_8_11, k_8_12,  KC_NO, k_8_14,  KC_NO}, \
    { KC_NO,  KC_NO,  k_2_3,  k_2_4,  k_2_5,  k_2_6,  k_2_7,  k_2_8,  k_2_9,  KC_NO,  KC_NO, k_2_12,  KC_NO, k_2_14, k_2_15}, \
    { k_3_1,  k_3_2,  k_3_3,  k_3_4,  k_3_5,  k_3_6,  k_3_7,  k_3_8,  k_3_9, k_3_10, k_3_11, k_3_12, k_3_13, k_3_14, k_3_15}, \
    { KC_NO,  KC_NO,  k_1_3,  k_1_4,  k_1_5,  k_1_6,  k_1_7,  k_1_8,  k_1_9, k_1_10, k_1_11, k_1_12, k_1_13, k_1_14, k_1_15}, \
    { k_4_1,  k_4_2,  k_4_3,  k_4_4,  k_4_5,  k_4_6,  k_4_7,  k_4_8,  KC_NO, k_4_10, k_4_11, k_4_12,  KC_NO, k_4_14,  KC_NO}  \
}

// Note:
// There are a couple of hidden pads, not mentioned in LAYOUT_102key_ansi() or LAYOUT_107key():
// There is one next to the left shift, on row 3. (columns in probably 3)
// There is one to the left of the backspace key, on row 5 (column is probably 10 (or 11? but less likely))
// There is one to the left of the enter key, on row 8 (column is probably 9)
// There is one to the left of right-shift key, row 3 (column is probably 10)
// There is one under the + key, on row 1 (column is probably 15)
// There is one under the kp enter key, on row 4 (column is probably 15)
// There is one to the right of the kp 0 key, on row 4 (column is probably 14)

// assuming the above notes are true:
#define LAYOUT_all( \
    k_3_1, k_3_2,   k_2_3, k_1_3, k_1_4, k_2_5, k_1_5, k_2_6, k_1_6, k_2_7, k_1_7, k_2_8, k_1_8, k_2_9, k_1_9, k_2_10, k_1_10, k_1_11, k_2_12, k_1_12,     k_1_13, k_1_14, k_2_15, k_1_15, \
    k_4_1, k_4_2,   k_3_3,     k_2_4, k_3_4, k_4_5, k_3_5, k_4_6, k_3_6, k_4_7, k_3_7, k_4_8, k_3_8, k_3_9, k_3_10, k_4_10,    k_3_11, k_4_12, k_3_12,     k_3_13, k_3_14, k_2_14, k_3_15, \
    k_5_1, k_5_2,   k_4_3,       k_4_4, k_5_4, k_6_5, k_5_5, k_6_6, k_5_6, k_5_7, k_6_7, k_6_8, k_5_8, k_5_9, k_4_9, k_5_10,   k_5_11, k_4_11, k_5_12,     k_5_13, k_4_14, k_5_14, k_5_15, \
    k_6_1, k_6_2,   k_5_3,    k_6_3, k_7_4, k_6_4, k_7_5, k_8_5, k_7_6, k_7_7, k_8_7, k_8_8, k_7_8, k_6_9, k_6_10, k_7_10,     k_6_11, k_6_12, k_7_12,     k_7_13, k_6_13, k_6_14, k_7_15, \
    k_7_1, k_7_2,   k_8_3,       k_7_3,  k_8_4,                     k_8_6,                      k_8_9, k_7_9, k_8_10,          k_8_11, k_7_11, k_8_12,     k_8_13, k_8_14, k_7_14, k_8_15  \
) \
{ \
    { k_6_1,  k_6_2,  k_6_3,  k_6_4,  k_6_5,  k_6_6,  k_6_7,  k_6_8,  k_6_9, k_6_10, k_6_11, k_6_12, k_6_13, k_6_14,  KC_NO}, \
    { k_7_1,  k_7_2,  k_7_3,  k_7_4,  k_7_5,  k_7_6,  k_7_7,  k_7_8,  k_7_9, k_7_10, k_7_11, k_7_12, k_7_13, k_7_14, k_7_15}, \
    { k_5_1,  k_5_2,  k_5_3,  k_5_4,  k_5_5,  k_5_6,  k_5_7,  k_5_8,  k_5_9, k_5_10, k_5_11, k_5_12, k_5_13, k_5_14, k_5_15}, \
    { KC_NO,  KC_NO,  k_8_3,  k_8_4,  k_8_5,  k_8_6,  k_8_7,  k_8_8,  k_8_9, k_8_10, k_8_11, k_8_12, k_8_13, k_8_14, k_8_15}, \
    { KC_NO,  KC_NO,  k_2_3,  k_2_4,  k_2_5,  k_2_6,  k_2_7,  k_2_8,  k_2_9, k_2_10,  KC_NO, k_2_12,  KC_NO, k_2_14, k_2_15}, \
    { k_3_1,  k_3_2,  k_3_3,  k_3_4,  k_3_5,  k_3_6,  k_3_7,  k_3_8,  k_3_9, k_3_10, k_3_11, k_3_12, k_3_13, k_3_14, k_3_15}, \
    { KC_NO,  KC_NO,  k_1_3,  k_1_4,  k_1_5,  k_1_6,  k_1_7,  k_1_8,  k_1_9, k_1_10, k_1_11, k_1_12, k_1_13, k_1_14, k_1_15}, \
    { k_4_1,  k_4_2,  k_4_3,  k_4_4,  k_4_5,  k_4_6,  k_4_7,  k_4_8,  k_4_9, k_4_10, k_4_11, k_4_12,  KC_NO, k_4_14,  KC_NO}  \
}

// layout 107key, is in the configuration shown by kishy.ca, the difference from _all, is that the backspace, and right shift are not split.
#define LAYOUT_107key( \
    k_3_1, k_3_2,   k_2_3, k_1_3, k_1_4, k_2_5, k_1_5, k_2_6, k_1_6, k_2_7, k_1_7, k_2_8, k_1_8, k_2_9, k_1_9,         k_1_10, k_1_11, k_2_12, k_1_12,     k_1_13, k_1_14, k_2_15, k_1_15, \
    k_4_1, k_4_2,   k_3_3,     k_2_4, k_3_4, k_4_5, k_3_5, k_4_6, k_3_6, k_4_7, k_3_7, k_4_8, k_3_8, k_3_9, k_3_10, k_4_10,    k_3_11, k_4_12, k_3_12,     k_3_13, k_3_14, k_2_14, k_3_15, \
    k_5_1, k_5_2,   k_4_3,       k_4_4, k_5_4, k_6_5, k_5_5, k_6_6, k_5_6, k_5_7, k_6_7, k_6_8, k_5_8, k_5_9, k_4_9, k_5_10,   k_5_11, k_4_11, k_5_12,     k_5_13, k_4_14, k_5_14, k_5_15, \
    k_6_1, k_6_2,   k_5_3,    k_6_3, k_7_4, k_6_4, k_7_5, k_8_5, k_7_6, k_7_7, k_8_7, k_8_8, k_7_8, k_6_9,         k_7_10,     k_6_11, k_6_12, k_7_12,     k_7_13, k_6_13, k_6_14, k_7_15, \
    k_7_1, k_7_2,   k_8_3,       k_7_3,  k_8_4,                     k_8_6,                      k_8_9, k_7_9, k_8_10,          k_8_11, k_7_11, k_8_12,     k_8_13, k_8_14, k_7_14, k_8_15  \
) \
LAYOUT_all( \
    k_3_1, k_3_2,   k_2_3, k_1_3, k_1_4, k_2_5, k_1_5, k_2_6, k_1_6, k_2_7, k_1_7, k_2_8, k_1_8, k_2_9, k_1_9, KC_NO,  k_1_10, k_1_11, k_2_12, k_1_12,     k_1_13, k_1_14, k_2_15, k_1_15, \
    k_4_1, k_4_2,   k_3_3,     k_2_4, k_3_4, k_4_5, k_3_5, k_4_6, k_3_6, k_4_7, k_3_7, k_4_8, k_3_8, k_3_9, k_3_10, k_4_10,    k_3_11, k_4_12, k_3_12,     k_3_13, k_3_14, k_2_14, k_3_15, \
    k_5_1, k_5_2,   k_4_3,       k_4_4, k_5_4, k_6_5, k_5_5, k_6_6, k_5_6, k_5_7, k_6_7, k_6_8, k_5_8, k_5_9, k_4_9, k_5_10,   k_5_11, k_4_11, k_5_12,     k_5_13, k_4_14, k_5_14, k_5_15, \
    k_6_1, k_6_2,   k_5_3,    k_6_3, k_7_4, k_6_4, k_7_5, k_8_5, k_7_6, k_7_7, k_8_7, k_8_8, k_7_8, k_6_9, KC_NO , k_7_10,     k_6_11, k_6_12, k_7_12,     k_7_13, k_6_13, k_6_14, k_7_15, \
    k_7_1, k_7_2,   k_8_3,       k_7_3,  k_8_4,                     k_8_6,                      k_8_9, k_7_9, k_8_10,          k_8_11, k_7_11, k_8_12,     k_8_13, k_8_14, k_7_14, k_8_15  \
)
