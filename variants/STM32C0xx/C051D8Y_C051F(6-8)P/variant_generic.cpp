/*
 *******************************************************************************
 * Copyright (c) 2020, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#if defined(ARDUINO_GENERIC_C051D8YX) || defined(ARDUINO_GENERIC_C051F6PX) ||\
    defined(ARDUINO_GENERIC_C051F8PX)
#include "pins_arduino.h"

// Digital PinName array
const PinName digitalPin[] = {
  PA_0,   // D0/A0
  PA_1,   // D1/A1
  PA_2,   // D2/A2
  PA_3,   // D3/A3
  PA_4,   // D4/A4
  PA_5,   // D5/A5
  PA_6,   // D6/A6
  PA_7,   // D7/A7
  PA_8,   // D8/A8
  PA_11,  // D9/A9
  PA_12,  // D10/A10
  PA_13,  // D11/A11
  PA_14,  // D12/A12
  PA_15,  // D13
  PB_3,   // D14
  PB_4,   // D15
  PB_5,   // D16
  PB_6,   // D17
  PB_7,   // D18
  PB_8,   // D19
  PC_14,  // D20
  PC_15,  // D21
  PF_2,   // D22
  PA_9_R, // D23
  PA_10_R // D24
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  0,  // A0,  PA0
  1,  // A1,  PA1
  2,  // A2,  PA2
  3,  // A3,  PA3
  4,  // A4,  PA4
  5,  // A5,  PA5
  6,  // A6,  PA6
  7,  // A7,  PA7
  8,  // A8,  PA8
  9,  // A9,  PA11
  10, // A10, PA12
  11, // A11, PA13
  12  // A12, PA14
};

#endif /* ARDUINO_GENERIC_* */
