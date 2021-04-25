/******************************************************************************
 * r96_globals.h
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
 * Global object definitions for the R96 Speeduino project.
 */

#ifndef _R96_GLOBALS_H
#define _R96_GLOBALS_H

/******************************************************************************
 * System include files.
 ******************************************************************************/


/******************************************************************************
 * Local include files.
 ******************************************************************************/
#include "table.h"


/******************************************************************************
 * Public definitions.
 ******************************************************************************/

#define BOOST_BY_GEAR_ENA_BIT 4  //!< Boost by gear enable bit position


/******************************************************************************
 * Global objects and data.
 ******************************************************************************/
 
// R96 custom I/O.
extern byte pinClutch;              //!< Clutch digital input

// R96 custom tables.
extern struct table3D boostTable2;  //!< 8x8 boost map for boost by gear (gear 2)
extern struct table3D boostTable3;  //!< 8x8 boost map for boost by gear (gear 3)
extern struct table3D boostTable4;  //!< 8x8 boost map for boost by gear (gear 4)
extern struct table3D boostTable5;  //!< 8x8 boost map for boost by gear (gear 5)
extern struct table3D boostTable6;  //!< 8x8 boost map for boost by gear (gear 6)


/******************************************************************************
 * Public functions.
 ******************************************************************************/


#endif // _R96_GLOBALS_H
