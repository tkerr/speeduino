/******************************************************************************
 * r96_init.h
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
 * System initialization function, data and object definitions for the 
 * R96 Speeduino project.
 */

#ifndef _R96_INIT_H
#define _R96_INIT_H

/******************************************************************************
 * System include files.
 ******************************************************************************/


/******************************************************************************
 * Local include files.
 ******************************************************************************/


/******************************************************************************
 * Public definitions.
 ******************************************************************************/


/**
 * @brief The R96 hardware board ID.
 *
 * Used without coordination with the parent Speeduino project.  
 * Make sure no conflict exists with this value.
 * If there is a conflict, then compilation of init.ino will probably fail
 * due to conflicting case statements in setPinMapping().
 */
#define R96_BOARD_ID (57)


/******************************************************************************
 * Global objects and data.
 ******************************************************************************/


/******************************************************************************
 * Public functions.
 ******************************************************************************/

/**
 * @brief Set the pin mappings for the R96 hardware.
 */
void r96_setPinMapping();


#endif // _R96_INIT_H
