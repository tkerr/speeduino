/******************************************************************************
 * r96_eeprom_map.h
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
 * EEPROM memory map defintions for the R96 Speeduino project.
 */

#ifndef _R96_EEPROM_MAP_H
#define _R96_EEPROM_MAP_H

/******************************************************************************
 * System include files.
 ******************************************************************************/


/******************************************************************************
 * Local include files.
 ******************************************************************************/


/******************************************************************************
 * Public definitions.
 ******************************************************************************/

#define R96_EEPROM_SIZE (4096)

/****
 * NOTE: Config pages 1 and 2 were swapped in Feb 2019.
 * The 'algorithm' field must be declared in the TunerStudio ini before it is 
 * used in the fuel table.
 * The veSetPage (general settings) is config page 1 in TunerStudio and config page 2 in speeduino.
 * The veMapPage (fuel table) is config page 2 in TunerStudio and config page 1 in speeduino.
 * Config page 1 size here represents the size of config page 1 in TunerStudio (speeduino page 2).
 * Config page 2 size here represents the size of config page 2 in TunerStudio (speeduino page 1).
 ****/
 
// Configuration page size definitions.
#define CONFIG_NUM_PAGES    (14)
#define CONFIG_PAGE1_SIZE  (128)  // Size must match TunerStudio definition for page 1 (veSetPage)
#define CONFIG_PAGE2_SIZE  (288)  // Size must match TunerStudio definition for page 2 (veMapPage)
#define CONFIG_PAGE3_SIZE  (288)
#define CONFIG_PAGE4_SIZE  (128)
#define CONFIG_PAGE5_SIZE  (288)
#define CONFIG_PAGE6_SIZE  (128)
#define CONFIG_PAGE7_SIZE  (640)
#define CONFIG_PAGE8_SIZE  (384)
#define CONFIG_PAGE9_SIZE  (192)
#define CONFIG_PAGE10_SIZE (192)
#define CONFIG_PAGE11_SIZE (288)
#define CONFIG_PAGE12_SIZE (192)
#define CONFIG_PAGE13_SIZE (128)
#define CONFIG_PAGE14_SIZE (288)

// Data table size definitions.
#define TABLE4x4_MAP_SIZE     (16)  // 4x4 table data storage size in bytes
#define TABLE4x4_BINS_SIZE     (4)  // 4x4 table axis storage size in bytes

#define TABLE6x6_MAP_SIZE     (36)  // 6x6 table data storage size in bytes
#define TABLE6x6_BINS_SIZE     (6)  // 6x6 table axis storage size in bytes

#define TABLE8x8_MAP_SIZE     (64)  // 8x8 table data storage size in bytes
#define TABLE8x8_BINS_SIZE     (8)  // 8x8 table axis storage size in bytes

#define TABLE16x16_MAP_SIZE  (256)  // 16x16 table data storage size in bytes
#define TABLE16x16_BINS_SIZE  (16)  // 16x16 table axis storage size in bytes


// EEPROM memory map for processor internal EEPROM.
// All definitions starting with EEPROM_ from this point forward represent an address.

// Address of the data version
#define EEPROM_DATA_VERSION   (0)

// Config page 1 fuel table - veMapPage
// Speeduino page 1 = TunerStudio page 2
#define EEPROM_CONFIG1_START  (EEPROM_DATA_VERSION + 1)
#define EEPROM_CONFIG1_XSIZE  (EEPROM_CONFIG1_START)
#define EEPROM_CONFIG1_YSIZE  (EEPROM_CONFIG1_XSIZE + 1)
#define EEPROM_CONFIG1_MAP    (EEPROM_CONFIG1_YSIZE + 1)
#define EEPROM_CONFIG1_XBINS  (EEPROM_CONFIG1_MAP + TABLE16x16_MAP_SIZE)
#define EEPROM_CONFIG1_YBINS  (EEPROM_CONFIG1_XBINS + TABLE16x16_BINS_SIZE)
#define EEPROM_CONFIG1_END    (EEPROM_CONFIG1_YBINS + TABLE16x16_BINS_SIZE)

// Config page 2 - veSetPage
// Speeduino page 2 = TunerStudio page 1
// This is confusing, but we must use CONFIG_PAGE1_SIZE here as the correct size
#define EEPROM_CONFIG2_START  (EEPROM_CONFIG1_END)
#define EEPROM_CONFIG2_END    (EEPROM_CONFIG2_START + CONFIG_PAGE1_SIZE)

// Config page 3 ignition table - ignMapPage
#define EEPROM_CONFIG3_START  (EEPROM_CONFIG2_END)
#define EEPROM_CONFIG3_XSIZE  (EEPROM_CONFIG3_START)
#define EEPROM_CONFIG3_YSIZE  (EEPROM_CONFIG3_XSIZE + 1)
#define EEPROM_CONFIG3_MAP    (EEPROM_CONFIG3_YSIZE + 1)
#define EEPROM_CONFIG3_XBINS  (EEPROM_CONFIG3_MAP + TABLE16x16_MAP_SIZE)
#define EEPROM_CONFIG3_YBINS  (EEPROM_CONFIG3_XBINS + TABLE16x16_BINS_SIZE)
#define EEPROM_CONFIG3_END    (EEPROM_CONFIG3_YBINS + TABLE16x16_BINS_SIZE)

// Config page 4 - ignSetPage
#define EEPROM_CONFIG4_START  (EEPROM_CONFIG3_END)
#define EEPROM_CONFIG4_END    (EEPROM_CONFIG4_START + CONFIG_PAGE4_SIZE)

// Config page 5 AFR table - afrMapPage
#define EEPROM_CONFIG5_START  (EEPROM_CONFIG4_END)
#define EEPROM_CONFIG5_XSIZE  (EEPROM_CONFIG5_START)
#define EEPROM_CONFIG5_YSIZE  (EEPROM_CONFIG5_XSIZE + 1)
#define EEPROM_CONFIG5_MAP    (EEPROM_CONFIG5_YSIZE + 1)
#define EEPROM_CONFIG5_XBINS  (EEPROM_CONFIG5_MAP + TABLE16x16_MAP_SIZE)
#define EEPROM_CONFIG5_YBINS  (EEPROM_CONFIG5_XBINS + TABLE16x16_BINS_SIZE)
#define EEPROM_CONFIG5_END    (EEPROM_CONFIG5_YBINS + TABLE16x16_BINS_SIZE)

// Config page 6 - afrSetPage
#define EEPROM_CONFIG6_START  (EEPROM_CONFIG5_END)
#define EEPROM_CONFIG6_END    (EEPROM_CONFIG6_START + CONFIG_PAGE6_SIZE)

// Config page 7 boost and VVT tables - boostvvtPage
// Boost table 1 is here, boost tables 2 - 6 are out of order, see below
#define EEPROM_CONFIG7_START  (EEPROM_CONFIG6_END)
#define EEPROM_CONFIG7_XSIZE1 (EEPROM_CONFIG7_START)                       // Boost table 1
#define EEPROM_CONFIG7_YSIZE1 (EEPROM_CONFIG7_XSIZE1 + 1)
#define EEPROM_CONFIG7_MAP1   (EEPROM_CONFIG7_YSIZE1 + 1)
#define EEPROM_CONFIG7_XBINS1 (EEPROM_CONFIG7_MAP1 + TABLE8x8_MAP_SIZE)
#define EEPROM_CONFIG7_YBINS1 (EEPROM_CONFIG7_XBINS1 + TABLE8x8_BINS_SIZE)
#define EEPROM_CONFIG7_XSIZE2 (EEPROM_CONFIG7_YBINS1 + TABLE8x8_BINS_SIZE) // VVT table
#define EEPROM_CONFIG7_YSIZE2 (EEPROM_CONFIG7_XSIZE2 + 1)
#define EEPROM_CONFIG7_MAP2   (EEPROM_CONFIG7_YSIZE2 + 1)
#define EEPROM_CONFIG7_XBINS2 (EEPROM_CONFIG7_MAP2 + TABLE8x8_MAP_SIZE)
#define EEPROM_CONFIG7_YBINS2 (EEPROM_CONFIG7_XBINS2 + TABLE8x8_BINS_SIZE)
#define EEPROM_CONFIG7_XSIZE3 (EEPROM_CONFIG7_YBINS2 + TABLE8x8_BINS_SIZE)
#define EEPROM_CONFIG7_YSIZE3 (EEPROM_CONFIG7_XSIZE3 + 1)                  // Fuel staging table
#define EEPROM_CONFIG7_MAP3   (EEPROM_CONFIG7_YSIZE3 + 1)
#define EEPROM_CONFIG7_XBINS3 (EEPROM_CONFIG7_MAP3 + TABLE8x8_MAP_SIZE)
#define EEPROM_CONFIG7_YBINS3 (EEPROM_CONFIG7_XBINS3 + TABLE8x8_BINS_SIZE)
#define EEPROM_CONFIG7_END    (EEPROM_CONFIG7_YBINS3 + TABLE8x8_BINS_SIZE)

// Config page 8 fuel trim tables 1-4 - seqFuelPage
// Fuel trim tables 5-8 are out of order, see below
#define EEPROM_CONFIG8_START  (EEPROM_CONFIG7_END)
#define EEPROM_CONFIG8_XSIZE1 (EEPROM_CONFIG8_START)                       // Trim table 1
#define EEPROM_CONFIG8_YSIZE1 (EEPROM_CONFIG8_XSIZE1 + 1)
#define EEPROM_CONFIG8_MAP1   (EEPROM_CONFIG8_YSIZE1 + 1)
#define EEPROM_CONFIG8_XBINS1 (EEPROM_CONFIG8_MAP1 + TABLE6x6_MAP_SIZE)
#define EEPROM_CONFIG8_YBINS1 (EEPROM_CONFIG8_XBINS1 + TABLE6x6_BINS_SIZE)
#define EEPROM_CONFIG8_XSIZE2 (EEPROM_CONFIG8_YBINS1 + TABLE6x6_BINS_SIZE) // Trim table 2
#define EEPROM_CONFIG8_YSIZE2 (EEPROM_CONFIG8_XSIZE2 + 1)
#define EEPROM_CONFIG8_MAP2   (EEPROM_CONFIG8_YSIZE2 + 1)
#define EEPROM_CONFIG8_XBINS2 (EEPROM_CONFIG8_MAP2 + TABLE6x6_MAP_SIZE)
#define EEPROM_CONFIG8_YBINS2 (EEPROM_CONFIG8_XBINS2 + TABLE6x6_BINS_SIZE)
#define EEPROM_CONFIG8_XSIZE3 (EEPROM_CONFIG8_YBINS2 + TABLE6x6_BINS_SIZE) // Trim table 3
#define EEPROM_CONFIG8_YSIZE3 (EEPROM_CONFIG8_XSIZE3 + 1)
#define EEPROM_CONFIG8_MAP3   (EEPROM_CONFIG8_YSIZE3 + 1)
#define EEPROM_CONFIG8_XBINS3 (EEPROM_CONFIG8_MAP3 + TABLE6x6_MAP_SIZE)
#define EEPROM_CONFIG8_YBINS3 (EEPROM_CONFIG8_XBINS3 + TABLE6x6_BINS_SIZE)
#define EEPROM_CONFIG8_XSIZE4 (EEPROM_CONFIG8_YBINS3 + TABLE6x6_BINS_SIZE) // Trim table 4
#define EEPROM_CONFIG8_YSIZE4 (EEPROM_CONFIG8_XSIZE4 + 1)
#define EEPROM_CONFIG8_MAP4   (EEPROM_CONFIG8_YSIZE4 + 1)
#define EEPROM_CONFIG8_XBINS4 (EEPROM_CONFIG8_MAP4 + TABLE6x6_MAP_SIZE)
#define EEPROM_CONFIG8_YBINS4 (EEPROM_CONFIG8_XBINS4 + TABLE6x6_BINS_SIZE)
#define EEPROM_CONFIG8_END    (EEPROM_CONFIG8_YBINS4 + TABLE6x6_BINS_SIZE)

// Config page 9 - canbusPage
#define EEPROM_CONFIG9_START  (EEPROM_CONFIG8_END)
#define EEPROM_CONFIG9_END    (EEPROM_CONFIG9_START + CONFIG_PAGE9_SIZE)

// Config page 10 - warmupPage
#define EEPROM_CONFIG10_START (EEPROM_CONFIG9_END)
#define EEPROM_CONFIG10_END   (EEPROM_CONFIG10_START + CONFIG_PAGE10_SIZE)

// Config page 11 fuel table 2 - fuelMap2Page
#define EEPROM_CONFIG11_START (EEPROM_CONFIG10_END)
#define EEPROM_CONFIG11_XSIZE (EEPROM_CONFIG11_START)
#define EEPROM_CONFIG11_YSIZE (EEPROM_CONFIG11_XSIZE + 1)
#define EEPROM_CONFIG11_MAP   (EEPROM_CONFIG11_YSIZE + 1)
#define EEPROM_CONFIG11_XBINS (EEPROM_CONFIG11_MAP + TABLE16x16_MAP_SIZE)
#define EEPROM_CONFIG11_YBINS (EEPROM_CONFIG11_XBINS + TABLE16x16_BINS_SIZE)
#define EEPROM_CONFIG11_END   (EEPROM_CONFIG11_YBINS + TABLE16x16_BINS_SIZE)

// Config page 12 WMI and dwell tables - wmiMapPage
#define EEPROM_CONFIG12_START  (EEPROM_CONFIG11_END)
#define EEPROM_CONFIG12_XSIZE  (EEPROM_CONFIG12_START)                       // WMI table
#define EEPROM_CONFIG12_YSIZE  (EEPROM_CONFIG12_XSIZE + 1)
#define EEPROM_CONFIG12_MAP    (EEPROM_CONFIG12_YSIZE + 1)
#define EEPROM_CONFIG12_XBINS  (EEPROM_CONFIG12_MAP + TABLE8x8_MAP_SIZE)
#define EEPROM_CONFIG12_YBINS  (EEPROM_CONFIG12_XBINS + TABLE8x8_BINS_SIZE)
#define EEPROM_CONFIG12_XSIZE2 (EEPROM_CONFIG12_YBINS + TABLE8x8_BINS_SIZE)  // vvt2Table
#define EEPROM_CONFIG12_YSIZE2 (EEPROM_CONFIG12_XSIZE2 + 1)
#define EEPROM_CONFIG12_MAP2   (EEPROM_CONFIG12_YSIZE2 + 1)
#define EEPROM_CONFIG12_XBINS2 (EEPROM_CONFIG12_MAP2 + TABLE8x8_MAP_SIZE)
#define EEPROM_CONFIG12_YBINS2 (EEPROM_CONFIG12_XBINS2 + TABLE8x8_BINS_SIZE)
#define EEPROM_CONFIG12_XSIZE3 (EEPROM_CONFIG12_YBINS2 + TABLE8x8_BINS_SIZE)  // Dwell table
#define EEPROM_CONFIG12_YSIZE3 (EEPROM_CONFIG12_XSIZE3 + 1)
#define EEPROM_CONFIG12_MAP3   (EEPROM_CONFIG12_YSIZE3 + 1)
#define EEPROM_CONFIG12_XBINS3 (EEPROM_CONFIG12_MAP3 + TABLE4x4_MAP_SIZE)
#define EEPROM_CONFIG12_YBINS3 (EEPROM_CONFIG12_XBINS3 + TABLE4x4_BINS_SIZE)
#define EEPROM_CONFIG12_END    (EEPROM_CONFIG12_YBINS3 + TABLE4x4_BINS_SIZE)

// Config page 13 programmable outputs - progOutsPage
#define EEPROM_CONFIG13_START (EEPROM_CONFIG12_END)
#define EEPROM_CONFIG13_END   (EEPROM_CONFIG13_START + CONFIG_PAGE13_SIZE)

// Config page 14 ignition table - ignMap2Page
#define EEPROM_CONFIG14_START (EEPROM_CONFIG13_END)
#define EEPROM_CONFIG14_XSIZE (EEPROM_CONFIG14_START)
#define EEPROM_CONFIG14_YSIZE (EEPROM_CONFIG14_XSIZE + 1)
#define EEPROM_CONFIG14_MAP   (EEPROM_CONFIG14_YSIZE + 1)
#define EEPROM_CONFIG14_XBINS (EEPROM_CONFIG14_MAP + TABLE16x16_MAP_SIZE)
#define EEPROM_CONFIG14_YBINS (EEPROM_CONFIG14_XBINS + TABLE16x16_BINS_SIZE)
#define EEPROM_CONFIG14_END   (EEPROM_CONFIG14_YBINS + TABLE16x16_BINS_SIZE)

// Config page 8, part 2: fuel trim tables 5-8 - seqFuelPage
// This is OUT OF ORDER as Table 8 was expanded to add fuel trim 5-8. 
// The EEPROM for them is simply added here so as not to impact existing tunes.
#define EEPROM_CONFIG8_START2 (EEPROM_CONFIG14_END)
#define EEPROM_CONFIG8_XSIZE5 (EEPROM_CONFIG8_START2)                        // Trim table 5
#define EEPROM_CONFIG8_YSIZE5 (EEPROM_CONFIG8_XSIZE5 + 1)
#define EEPROM_CONFIG8_MAP5   (EEPROM_CONFIG8_YSIZE5 + 1)
#define EEPROM_CONFIG8_XBINS5 (EEPROM_CONFIG8_MAP5 + TABLE6x6_MAP_SIZE)
#define EEPROM_CONFIG8_YBINS5 (EEPROM_CONFIG8_XBINS5 + TABLE6x6_BINS_SIZE)
#define EEPROM_CONFIG8_XSIZE6 (EEPROM_CONFIG8_YBINS5 + TABLE6x6_BINS_SIZE)   // Trim table 6
#define EEPROM_CONFIG8_YSIZE6 (EEPROM_CONFIG8_XSIZE6 + 1)
#define EEPROM_CONFIG8_MAP6   (EEPROM_CONFIG8_YSIZE6 + 1)
#define EEPROM_CONFIG8_XBINS6 (EEPROM_CONFIG8_MAP6 + TABLE6x6_MAP_SIZE)
#define EEPROM_CONFIG8_YBINS6 (EEPROM_CONFIG8_XBINS6 + TABLE6x6_BINS_SIZE)
#define EEPROM_CONFIG8_XSIZE7 (EEPROM_CONFIG8_YBINS6 + TABLE6x6_BINS_SIZE)   // Trim table 7
#define EEPROM_CONFIG8_YSIZE7 (EEPROM_CONFIG8_XSIZE7 + 1)
#define EEPROM_CONFIG8_MAP7   (EEPROM_CONFIG8_YSIZE7 + 1)
#define EEPROM_CONFIG8_XBINS7 (EEPROM_CONFIG8_MAP7 + TABLE6x6_MAP_SIZE)
#define EEPROM_CONFIG8_YBINS7 (EEPROM_CONFIG8_XBINS7 + TABLE6x6_BINS_SIZE)
#define EEPROM_CONFIG8_XSIZE8 (EEPROM_CONFIG8_YBINS7 + TABLE6x6_BINS_SIZE)   // Trim table 8
#define EEPROM_CONFIG8_YSIZE8 (EEPROM_CONFIG8_XSIZE8 + 1)
#define EEPROM_CONFIG8_MAP8   (EEPROM_CONFIG8_YSIZE8 + 1)
#define EEPROM_CONFIG8_XBINS8 (EEPROM_CONFIG8_MAP8 + TABLE6x6_MAP_SIZE)
#define EEPROM_CONFIG8_YBINS8 (EEPROM_CONFIG8_XBINS8 + TABLE6x6_BINS_SIZE)
#define EEPROM_CONFIG8_END2   (EEPROM_CONFIG8_YBINS8 + TABLE6x6_BINS_SIZE)

// Config page 7, part 2: boost tables 2-6 - boostvvtPage
// This is OUT OF ORDER as Table 7 was expanded to add boost tables 2-6. 
#define EEPROM_CONFIG7_START2 (EEPROM_CONFIG8_END2)
#define EEPROM_CONFIG7_XSIZE4 (EEPROM_CONFIG7_START2)                        // Boost table 2
#define EEPROM_CONFIG7_YSIZE4 (EEPROM_CONFIG7_XSIZE4 + 1)
#define EEPROM_CONFIG7_MAP4   (EEPROM_CONFIG7_YSIZE4 + 1)
#define EEPROM_CONFIG7_XBINS4 (EEPROM_CONFIG7_MAP4 + TABLE8x8_MAP_SIZE)
#define EEPROM_CONFIG7_YBINS4 (EEPROM_CONFIG7_XBINS4 + TABLE8x8_BINS_SIZE)
#define EEPROM_CONFIG7_XSIZE5 (EEPROM_CONFIG7_YBINS4 + TABLE8x8_BINS_SIZE)   // Boost table 3
#define EEPROM_CONFIG7_YSIZE5 (EEPROM_CONFIG7_XSIZE5 + 1)
#define EEPROM_CONFIG7_MAP5   (EEPROM_CONFIG7_YSIZE5 + 1)
#define EEPROM_CONFIG7_XBINS5 (EEPROM_CONFIG7_MAP5 + TABLE8x8_MAP_SIZE)
#define EEPROM_CONFIG7_YBINS5 (EEPROM_CONFIG7_XBINS5 + TABLE8x8_BINS_SIZE)
#define EEPROM_CONFIG7_XSIZE6 (EEPROM_CONFIG7_YBINS5 + TABLE8x8_BINS_SIZE)   // Boost table 4
#define EEPROM_CONFIG7_YSIZE6 (EEPROM_CONFIG7_XSIZE6 + 1)
#define EEPROM_CONFIG7_MAP6   (EEPROM_CONFIG7_YSIZE6 + 1)
#define EEPROM_CONFIG7_XBINS6 (EEPROM_CONFIG7_MAP6 + TABLE8x8_MAP_SIZE)
#define EEPROM_CONFIG7_YBINS6 (EEPROM_CONFIG7_XBINS6 + TABLE8x8_BINS_SIZE)
#define EEPROM_CONFIG7_XSIZE7 (EEPROM_CONFIG7_YBINS6 + TABLE8x8_BINS_SIZE)   // Boost table 5
#define EEPROM_CONFIG7_YSIZE7 (EEPROM_CONFIG7_XSIZE7 + 1)
#define EEPROM_CONFIG7_MAP7   (EEPROM_CONFIG7_YSIZE7 + 1)
#define EEPROM_CONFIG7_XBINS7 (EEPROM_CONFIG7_MAP7 + TABLE8x8_MAP_SIZE)
#define EEPROM_CONFIG7_YBINS7 (EEPROM_CONFIG7_XBINS7 + TABLE8x8_BINS_SIZE)
#define EEPROM_CONFIG7_XSIZE8 (EEPROM_CONFIG7_YBINS7 + TABLE8x8_BINS_SIZE)   // Boost table 6
#define EEPROM_CONFIG7_YSIZE8 (EEPROM_CONFIG7_XSIZE8 + 1)
#define EEPROM_CONFIG7_MAP8   (EEPROM_CONFIG7_YSIZE8 + 1)
#define EEPROM_CONFIG7_XBINS8 (EEPROM_CONFIG7_MAP8 + TABLE8x8_MAP_SIZE)
#define EEPROM_CONFIG7_YBINS8 (EEPROM_CONFIG7_XBINS8 + TABLE8x8_BINS_SIZE)
#define EEPROM_CONFIG7_END2   (EEPROM_CONFIG7_YBINS8 + TABLE8x8_BINS_SIZE)

// EEPROM CRC32
// Size is 4 * <number of pages>
#define EEPROM_PAGE_CRC32_SIZE  (4 * CONFIG_NUM_PAGES)
#define EEPROM_PAGE_CRC32_START (EEPROM_CONFIG7_END2)
#define EEPROM_PAGE_CRC32       (EEPROM_PAGE_CRC32_START)
#define EEPROM_PAGE_CRC32_END   (EEPROM_PAGE_CRC32 + EEPROM_PAGE_CRC32_SIZE)

// Calibration data.
// O2  calibration has 2-byte bins and 1-byte values.
// IAT calibration has 2-byte bins and 2-byte values.
// CLT calibration has 2-byte bins and 2-byte values.
#define EEPROM_CALIBRATION_SIZE  (32)  // Each table has 32 values
#define EEPROM_CALIBRATION_START (EEPROM_PAGE_CRC32_END)
#define EEPROM_LAST_BARO         (EEPROM_CALIBRATION_START)
#define EEPROM_CALIBRATION_O2    (EEPROM_LAST_BARO + 1)
#define EEPROM_CALIBRATION_IAT   (EEPROM_CALIBRATION_O2  + (3 * EEPROM_CALIBRATION_SIZE))
#define EEPROM_CALIBRATION_CLT   (EEPROM_CALIBRATION_IAT + (4 * EEPROM_CALIBRATION_SIZE))
#define EEPROM_CALIBRATION_END   (EEPROM_CALIBRATION_CLT + (4 * EEPROM_CALIBRATION_SIZE))

// Highest EEPROM address.
#define EEPROM_END (EEPROM_CALIBRATION_END)

// Sanity check.
#if (EEPROM_END > R96_EEPROM_SIZE)
    #error "R96 EEPROM size exceeded"
#endif

/******************************************************************************
 * Public functions.
 ******************************************************************************/

#endif // _R96_EEPROM_MAP_H
