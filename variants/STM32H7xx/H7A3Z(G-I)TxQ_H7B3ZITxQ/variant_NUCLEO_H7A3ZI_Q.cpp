/*
 *******************************************************************************
 * Copyright (c) 2022, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#if defined(ARDUINO_NUCLEO_H7A3ZI_Q)
#include "pins_arduino.h"

// Pin number
const PinName digitalPin[] = {
  PB_7,
  PB_6,
  PG_14,
  PE_13,
  PE_14,
  PE_11,
  PA_8,
  PG_12,
  PG_9,
  PD_15,
  PD_14,
  PA_7,
  PA_6,
  PA_5,
  PB_9,
  PB_8,
  PC_6,
  PB_15,
  PB_13,
  PB_12,
  PA_15,
  PC_7,
  PB_5,
  PB_3,
  PA_4,
  PB_4,
  PG_6,
  PB_2,
  PD_13,
  PD_12,
  PD_11,
  PE_2,
  PA_0,
  PB_0,
  PE_0,
  PB_11,
  PB_10,
  PE_15,
  PE_6,
  PE_12,
  PE_10,
  PE_7,
  PE_8,
  PC_8,
  PC_9,
  PC_10,
  PC_11,
  PC_12,
  PD_2,
  PG_10,
  PG_8,
  PD_7,
  PD_6,
  PD_5,
  PD_4,
  PD_3,
  PE_2,
  PE_4,
  PE_5,
  PE_6,
  PE_3,
  PF_8,
  PF_7,
  PF_9,
  PD_10,
  PB_14,
  PD_1,
  PD_0,
  PF_15,
  PF_14,
  PB_5,
  PE_9,
  PB_2,
  PA_3,
  PC_0,
  PC_3_C,
  PB_1,
  PC_2_C,
  PF_11,
  PC_1,
  PC_5,
  PA_2,
  PA_1,
  PA_9,
  PA_10,
  PA_11,
  PA_12,
  PA_13,
  PA_14,
  PC_4,
  PC_13,
  PC_14,
  PC_15,
  PD_8,
  PD_9,
  PE_1,
  PF_6,
  PF_10,
  PG_7,
  PG_11,
  PG_13,
  PH_0,
  PH_1
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  73,  // A0
  74,  // A1
  75,  // A2
  76,  // A3
  77,  // A4
  78,  // A5
  79,  // A6
  80,  // A7
  81,  // A8
  82,  // A9
  89,  // A10
  11,  // A11
  12,  // A12
  13,  // A13
  24,  // A14
  32,  // A15
  33,  // A16
  69   // A17
};

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {};

  /*AXI clock gating */
  RCC->CKGAENR = 0xFFFFFFFF;

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48 | RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 70;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2
                                | RCC_CLOCKTYPE_D3PCLK1 | RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6) != HAL_OK) {
    Error_Handler();
  }

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LPUART1 | RCC_PERIPHCLK_USB;
  PeriphClkInitStruct.PLL3.PLL3M = 1;
  PeriphClkInitStruct.PLL3.PLL3N = 24;
  PeriphClkInitStruct.PLL3.PLL3P = 2;
  PeriphClkInitStruct.PLL3.PLL3Q = 6;
  PeriphClkInitStruct.PLL3.PLL3R = 2;
  PeriphClkInitStruct.PLL3.PLL3RGE = RCC_PLL3VCIRANGE_3;
  PeriphClkInitStruct.PLL3.PLL3VCOSEL = RCC_PLL3VCOWIDE;
  PeriphClkInitStruct.PLL3.PLL3FRACN = 0;
  PeriphClkInitStruct.Lpuart1ClockSelection = RCC_LPUART1CLKSOURCE_PLL3;
  PeriphClkInitStruct.UsbClockSelection = RCC_USBCLKSOURCE_HSI48;

  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK) {
    Error_Handler();
  }

}

#ifdef __cplusplus
}
#endif
#endif /* ARDUINO_H7A3ZI_Q */
