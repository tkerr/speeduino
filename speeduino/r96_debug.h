/******************************************************************************
 * r96_debug.h
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
 * System debug function, data and object definitions for the 
 * R96 Speeduino project.
 */

#ifndef _R96_DEBUG_H
#define _R96_DEBUG_H

/******************************************************************************
 * System include files.
 ******************************************************************************/
#include "table.h"


/******************************************************************************
 * Local include files.
 ******************************************************************************/


/******************************************************************************
 * Public definitions.
 ******************************************************************************/

// Uncomment the following definition to enable system debug.
#define USE_R96_DEBUG

#define R96_DEBUG_BAUD (115200)  //!< The debug serial port baud rate


/******************************************************************************
 * Global objects and data.
 ******************************************************************************/
 
#ifdef USE_R96_DEBUG

#include "LogMessage.h"
extern LogMessage r96_logger;

#endif // USE_R96_DEBUG


/******************************************************************************
 * Public functions.
 ******************************************************************************/

/**
 * @brief Initialize the R96 debug module.
 *
 * Call this before calling any other debugger function.
 */
void r96_debug_init();

/**
 * @brief Print the number of EEPROM bytes used.
 */
void r96_debug_eeprom_use();

/**
 * @brief Print interesting configuration parameters.
 */
void r96_debug_print_config();

/**
 * @brief Print a 2D table.
 *
 * @param pTable Pointer to the 2D table to print.
 *
 * @param name Optional table name to print.
 */
void r96_debug_print_table2D(const struct table2D* pTable, const char* name = "");

/**
 * @brief Print a 3D table.
 *
 * @param pTable Pointer to the 3D table to print.
 *
 * @param name Optional table name to print.
 */
void r96_debug_print_table3D(const struct table3D* pTable, const char* name = "");

#endif // _R96_DEBUG_H
