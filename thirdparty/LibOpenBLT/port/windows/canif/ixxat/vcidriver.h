/************************************************************************************//**
* \file         vcidriver.h
* \brief        Ixxat VCI driver interface header file.
* \ingroup      VCIDRIVER
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*   Copyright (c) 2021  by Feaser    http://www.feaser.com    All rights reserved
*
*----------------------------------------------------------------------------------------
*                            L I C E N S E
*----------------------------------------------------------------------------------------
* This file is part of OpenBLT. OpenBLT is free software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published by the Free
* Software Foundation, either version 3 of the License, or (at your option) any later
* version.
*
* OpenBLT is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE. See the GNU General Public License for more details.
*
* You have received a copy of the GNU General Public License along with OpenBLT. It
* should be located in ".\Doc\license.html". If not, contact Feaser to obtain a copy.
*
* \endinternal
****************************************************************************************/
/************************************************************************************//**
* \defgroup   VCIDRIVER Ixxat VCI driver USB to CAN interface
* \brief      This module implements the CAN interface for the Ixxat VCI driver.
* \ingroup    CanDriver
****************************************************************************************/
#ifndef VCIDRIVER_H
#define VCIDRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************
* Function prototypes
****************************************************************************************/
tCanInterface const * IxxatVciGetInterface(void);

#ifdef __cplusplus
}
#endif

#endif /* VCIDRIVER_H */
/*********************************** end of vcidriver.h ********************************/
