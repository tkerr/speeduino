/******************************************************************************
 * r96_boost.cpp
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
 * Boost control function and data implementation for the R96 Speeduino project.
 */
 
/******************************************************************************
 * System include files.
 ******************************************************************************/


/******************************************************************************
 * Local include files.
 ******************************************************************************/
#include "globals.h"


/******************************************************************************
 * Forward references.
 ******************************************************************************/


/******************************************************************************
 * Local definitions.
 ******************************************************************************/


/******************************************************************************
 * Global objects and data.
 ******************************************************************************/


/******************************************************************************
 * Local data.
 ******************************************************************************/


/******************************************************************************
 * Public methods and functions.
 ******************************************************************************/

/**************************************
 * r96_getBoostTable()
 **************************************/
struct table3D* r96_getBoostTable()
{
    struct table3D* pTable = &boostTable;  // Initialize to primary boost table

    if (configPage2.boostByGear == 1)
    {
        switch (currentStatus.gear)
        {
            case 0:  // getGear() could return zero if gear is unknown
            case 1:
                pTable = &boostTable;
                break;
            case 2:
                pTable = &boostTable2;
                break;
            case 3:
                pTable = &boostTable3;
                break;
            case 4:
                pTable = &boostTable4;
                break;
            case 5:
                pTable = &boostTable5;
                break;
            case 6:
            default:  // Just in case gear > 6 somehow
                pTable = &boostTable6;
                break;
        }
    }
    return pTable;
}


/*****************************************************************************
 * Private methods and functions.
 ******************************************************************************/


// End of file.
