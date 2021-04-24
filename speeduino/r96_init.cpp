/******************************************************************************
 * r96_init.cpp
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
 * System initialization function, data and object implementation for the 
 * R96 Speeduino project.
 */
 
/******************************************************************************
 * System include files.
 ******************************************************************************/
#include "Arduino.h"


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
 * r96_setPinMapping()
 **************************************/ 
void r96_setPinMapping()
{
    #if defined(CORE_TEENSY)
    // Pin 0 is Serial1 RX (RX1)
    // Pin 1 is Serial1 TX (TX1)
    // Pin 3 is CAN0TX
    // Pin 4 is CAN0RX

    pinInjector1 = 2;
    pinInjector2 = 3;
    pinInjector3 = 4;
    pinInjector4 = 5;
    pinInjector5 = 6;
    pinInjector6 = 7;
    pinInjector7 = 8;
    pinInjector8 = 9;

    pinCoil1 = 10;
    pinCoil2 = 11;
    pinCoil3 = 12;
    pinCoil4 = 24;
    pinCoil5 = 25;
    pinCoil6 = 26;
    pinCoil7 = 27;
    pinCoil8 = 28;

    pinTrigger  = 29;  // Crank
    pinTrigger2 = 30;  // Cam

    pinBat  = A0;
    pinO2   = A3;
    pinIAT  = A12;
    pinCLT  = A13;
    pinTPS  = A14;
    pinMAP  = A15;
    pinFlex = A20;

    pinFan      = 15;
    pinTachOut  = 16;
    pinFuelPump = 18;
    pinIdle1    = 36;
    pinBoost    = 38;

    // High current PWM outputs.
    pinSpareHOut1 = 37;
    pinSpareHOut2 = 35;

    // Clutch digital input.
    // Introduced with the R96 board.
    pinClutch = 19;
    pinMode(pinClutch, INPUT);

    injectorOutputControl = OUTPUT_CONTROL_DIRECT;
    ignitionOutputControl = OUTPUT_CONTROL_DIRECT;
    
    #else
        #error "No pin mappings for R96 hardware"
    #endif  // defined(CORE_TEENSY)

    // Unused TunerStudio selectable pins.
    // Set to an invalid pin number.
    // Do not set to zero in order to avoid confilct with Serial1 RX1.
    pinBaro         = BOARD_MAX_IO_PINS + 1;
    pinEMAP         = BOARD_MAX_IO_PINS + 1;
    pinFuel2Input   = BOARD_MAX_IO_PINS + 1;
    pinFuelPressure = BOARD_MAX_IO_PINS + 1;
    pinIgnBypass    = BOARD_MAX_IO_PINS + 1;
    pinLaunch       = BOARD_MAX_IO_PINS + 1;
    pinOilPressure  = BOARD_MAX_IO_PINS + 1;
    pinSpark2Input  = BOARD_MAX_IO_PINS + 1;
    pinVSS          = BOARD_MAX_IO_PINS + 1;
    pinVVT_1        = BOARD_MAX_IO_PINS + 1;
    pinVVT_2        = BOARD_MAX_IO_PINS + 1;
    pinWMIEmpty     = BOARD_MAX_IO_PINS + 1;
    pinWMIEnabled   = BOARD_MAX_IO_PINS + 1;
    pinWMIIndicator = BOARD_MAX_IO_PINS + 1;

    // Other unused pins.
    // Set to an invalid pin number.
    // Do not set to zero in order to avoid confilct with Serial1 RX1.
    pinCTPS          = BOARD_MAX_IO_PINS + 1;
    pinDisplayReset  = BOARD_MAX_IO_PINS + 1;
    pinIdle2         = BOARD_MAX_IO_PINS + 1;
    pinIdleUp        = BOARD_MAX_IO_PINS + 1;
    pinIdleUpOutput  = BOARD_MAX_IO_PINS + 1;
    pinMAP2          = BOARD_MAX_IO_PINS + 1;
    pinMC33810_1_CS  = BOARD_MAX_IO_PINS + 1;
    pinMC33810_2_CS  = BOARD_MAX_IO_PINS + 1;
    pinO2_2          = BOARD_MAX_IO_PINS + 1;
    pinResetControl  = BOARD_MAX_IO_PINS + 1;
    pinStepperDir    = BOARD_MAX_IO_PINS + 1;
    pinStepperEnable = BOARD_MAX_IO_PINS + 1;
    pinStepperStep   = BOARD_MAX_IO_PINS + 1;
    pinTrigger3      = BOARD_MAX_IO_PINS + 1;

    pinSpareTemp1 = BOARD_MAX_IO_PINS + 1;
    pinSpareTemp2 = BOARD_MAX_IO_PINS + 1;
    pinSpareOut1  = BOARD_MAX_IO_PINS + 1;
    pinSpareOut2  = BOARD_MAX_IO_PINS + 1;
    pinSpareOut3  = BOARD_MAX_IO_PINS + 1;
    pinSpareOut4  = BOARD_MAX_IO_PINS + 1;
    pinSpareOut5  = BOARD_MAX_IO_PINS + 1;
    pinSpareOut6  = BOARD_MAX_IO_PINS + 1;
    pinSpareLOut1 = BOARD_MAX_IO_PINS + 1;
    pinSpareLOut2 = BOARD_MAX_IO_PINS + 1;
    pinSpareLOut3 = BOARD_MAX_IO_PINS + 1;
    pinSpareLOut4 = BOARD_MAX_IO_PINS + 1;
    pinSpareLOut5 = BOARD_MAX_IO_PINS + 1;
}


/*****************************************************************************
 * Private methods and functions.
 ******************************************************************************/


// End of file.
