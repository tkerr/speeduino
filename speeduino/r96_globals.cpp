/******************************************************************************
 * r96_globals.cpp
 * Copyright (c) 2021 Thomas Kerr AB3GY
 *
 * Developed for the R96 Speeduino project.
 *
 * Released under the GNU General Public License version 2
 * SPDX short identifier: GPL-2.0
 * See https://opensource.org/licenses/gpl-2.0.php
 *  
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,la
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 ******************************************************************************/

/**
 * @file
 * @brief
 * Global object implementation for the R96 Speeduino project.
 */
 
/******************************************************************************
 * System include files.
 ******************************************************************************/
#include "Arduino.h"


/******************************************************************************
 * Local include files.
 ******************************************************************************/
#include "r96_globals.h"


/******************************************************************************
 * Forward references.
 ******************************************************************************/


/******************************************************************************
 * Local definitions.
 ******************************************************************************/


/******************************************************************************
 * Global objects and data.
 ******************************************************************************/

// R96 custom I/O.
byte pinClutch = 0;          // Clutch digital input

// R96 custom tables.
struct table3D boostTable2;  // 8x8 boost map for boost by gear (gear 2)
struct table3D boostTable3;  // 8x8 boost map for boost by gear (gear 3)
struct table3D boostTable4;  // 8x8 boost map for boost by gear (gear 4)
struct table3D boostTable5;  // 8x8 boost map for boost by gear (gear 5)
struct table3D boostTable6;  // 8x8 boost map for boost by gear (gear 6)


/******************************************************************************
 * Local data.
 ******************************************************************************/


/******************************************************************************
 * Public methods and functions.
 ******************************************************************************/


/*****************************************************************************
 * Private methods and functions.
 ******************************************************************************/


// End of file.
