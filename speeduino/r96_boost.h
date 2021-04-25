/******************************************************************************
 * r96_boost.h
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
 * Boost control function and data definitions for the R96 Speeduino project.
 */

#ifndef _R96_BOOST_H
#define _R96_BOOST_H

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


/******************************************************************************
 * Global objects and data.
 ******************************************************************************/


/******************************************************************************
 * Public functions.
 ******************************************************************************/

/**
 * @brief Choose a boost table based on configuration settings and the current 
 * gear.
 *
 * Returns the primary boost table if boost by gear is disabled, or a boost 
 * table for the current gear if enabled.
 *
 * @return A pointer to the boost table to use for the boost control algorithm.
 */
struct table3D* r96_getBoostTable();


#endif // _R96_BOOST_H
