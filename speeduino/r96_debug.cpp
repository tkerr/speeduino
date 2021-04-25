/******************************************************************************
 * r96_debug.cpp
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
 * System debug function, data and object implementation for the 
 * R96 Speeduino project.
 */
 
/******************************************************************************
 * System include files.
 ******************************************************************************/
#include "Arduino.h"
#include "LogMessage.h"


/******************************************************************************
 * Local include files.
 ******************************************************************************/
#include "globals.h"
#include "storage.h"
#include "r96_debug.h"


/******************************************************************************
 * Forward references.
 ******************************************************************************/


/******************************************************************************
 * Local definitions.
 ******************************************************************************/


/******************************************************************************
 * Global objects and data.
 ******************************************************************************/


#ifdef USE_R96_DEBUG

LogMessage r96_logger(&Serial1);  //!< Global object used for debug message logging.

#endif // USE_R96_DEBUG


/******************************************************************************
 * Local data.
 ******************************************************************************/


/******************************************************************************
 * Public methods and functions.
 ******************************************************************************/


/**************************************
 * r96_debug_init()
 **************************************/ 
void r96_debug_init()
{
    #ifdef USE_R96_DEBUG
    r96_logger.begin(R96_DEBUG_BAUD);
    delay(500);
    #endif // USE_R96_DEBUG
}


/**************************************
 * r96_debug_eeprom_use()
 **************************************/ 
void r96_debug_eeprom_use()
{
    #ifdef USE_R96_DEBUG
    r96_logger.log("EEPROM usage", EEPROM_END);
    #endif // USE_R96_DEBUG
}


/**************************************
 * r96_debug_print_config()
 **************************************/ 
void r96_debug_print_config()
{
    #ifdef USE_R96_DEBUG
    r96_logger.log("R96 configuration:");
    r96_logger.timestamps(false);
    r96_logger.log("Board ID", configPage2.pinMapping);
    r96_logger.log("Num cylinders", configPage2.nCylinders);
    r96_logger.log("Num injectors", configPage2.nInjectors);
    r96_logger.log("Injector type", configPage2.injType);
    r96_logger.log("Injector layout", configPage2.injLayout);
    r96_logger.log("Boost enabled", configPage6.boostEnabled);
    r96_logger.log("Boost by gear", configPage2.boostByGear);
    r96_logger.timestamps(true);
    #endif // USE_R96_DEBUG
}


/**************************************
 * r96_debug_print_table2D()
 **************************************/ 
void r96_debug_print_table2D(const struct table2D* pTable, const char* name)
{
    #ifdef USE_R96_DEBUG

    // Print table title.
    if (strlen(name) > 0)
    {
        r96_logger.log("Table", name);
    }
    else
    {
        r96_logger.log("Table:");
    }
    
    // Print the table values.
    for (byte x = 0; x < pTable->xSize; x++)
    {
        if(pTable->valueSize == SIZE_INT)
        {
            r96_logger.print(((int16_t*)pTable->values)[x]);
        }
        else
        {
            r96_logger.print(((uint8_t*)pTable->values)[x]);
        }
        r96_logger.print(' ');
    }
    r96_logger.println();
    
    // Print the X-axis values.
    for (byte x = 0; x < pTable->xSize; x++)
    {
        if(pTable->axisSize == SIZE_INT)
        {
            r96_logger.print(((int16_t*)pTable->axisX)[x]);
        }
        else
        {
            r96_logger.print(((uint8_t*)pTable->axisX)[x]);
        }
        r96_logger.print(' ');
    }
    r96_logger.println();
    
    #endif // USE_R96_DEBUG
}


/**************************************
 * r96_debug_print_table3D()
 **************************************/ 
void r96_debug_print_table3D(const struct table3D* pTable, const char* name)
{
    #ifdef USE_R96_DEBUG

    // Print table title.
    if (strlen(name) > 0)
    {
        r96_logger.log("Table", name);
    }
    else
    {
        r96_logger.log("Table:");
    }
    
    // Print the table.
    for (int y = 0; y < pTable->ySize; y++)
    {
        r96_logger.print(pTable->axisY[y]); r96_logger.print(' ');  // Y-axis value
        for (int x = 0; x < pTable->xSize; x++)
        {
            r96_logger.print(pTable->values[y][x]); r96_logger.print(' ');  // Table value
        }
        r96_logger.println();
    }
    
    // Print the X-axis.
    for (int x = 0; x < pTable->xSize; x++)
    {
        r96_logger.print(pTable->axisX[x]); r96_logger.print(' ');
    }
    r96_logger.println();

    #endif // USE_R96_DEBUG
}

/*****************************************************************************
 * Private methods and functions.
 ******************************************************************************/


// End of file.
