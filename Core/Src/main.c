/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_fatfs.h"
#include "sdmmc.h"
#include "usart.h"
#include "gpio.h"
#include "string.h"
#include "stdio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define LOW GPIO_PIN_RESET
#define HIGH GPIO_PIN_SET
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

void LED_Test(void);

void GPIO_Test(void);
void UART_Test(void);
void I2C_Test(void);
void SPI_Test(void);

void PWM_Gen(void);
void PWM_DMA_Gen(void);

void ADC_Test(void);

void MicroSD_Test(void);

void Interlock_Check(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_SDMMC1_SD_Init();
  if (MX_FATFS_Init() != APP_OK) {
    Error_Handler();
  }
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 16;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enable MSI Auto calibration
  */
  HAL_RCCEx_EnableMSIPLLMode();
}

/* USER CODE BEGIN 4 */

void GPIOTest(void)
{
	while(1)
	{
		// Drive all GPIO Pins LOW
		HAL_GPIO_WritePin(GPIO_1_GPIO_Port, GPIO_1_Pin, LOW);
		HAL_GPIO_WritePin(GPIO_2_GPIO_Port, GPIO_2_Pin, LOW);
		HAL_GPIO_WritePin(GPIO_3_GPIO_Port, GPIO_3_Pin, LOW);
		HAL_GPIO_WritePin(GPIO_4_GPIO_Port, GPIO_4_Pin, LOW);
		HAL_GPIO_WritePin(GPIO_5_GPIO_Port, GPIO_5_Pin, LOW);
		HAL_GPIO_WritePin(GPIO_6_GPIO_Port, GPIO_6_Pin, LOW);
		HAL_GPIO_WritePin(GPIO_7_GPIO_Port, GPIO_7_Pin, LOW);
		HAL_GPIO_WritePin(GPIO_8_GPIO_Port, GPIO_8_Pin, LOW);
		HAL_GPIO_WritePin(GPIO_9_GPIO_Port, GPIO_9_Pin, LOW);
		HAL_GPIO_WritePin(GPIO_10_GPIO_Port, GPIO_10_Pin, LOW);

		HAL_Delay(100);

		// Drive all GPIO Pins HIGH
		HAL_GPIO_WritePin(GPIO_1_GPIO_Port, GPIO_1_Pin, HIGH);
		HAL_GPIO_WritePin(GPIO_2_GPIO_Port, GPIO_2_Pin, HIGH);
		HAL_GPIO_WritePin(GPIO_3_GPIO_Port, GPIO_3_Pin, HIGH);
		HAL_GPIO_WritePin(GPIO_4_GPIO_Port, GPIO_4_Pin, HIGH);
		HAL_GPIO_WritePin(GPIO_5_GPIO_Port, GPIO_5_Pin, HIGH);
		HAL_GPIO_WritePin(GPIO_6_GPIO_Port, GPIO_6_Pin, HIGH);
		HAL_GPIO_WritePin(GPIO_7_GPIO_Port, GPIO_7_Pin, HIGH);
		HAL_GPIO_WritePin(GPIO_8_GPIO_Port, GPIO_8_Pin, HIGH);
		HAL_GPIO_WritePin(GPIO_9_GPIO_Port, GPIO_9_Pin, HIGH);
		HAL_GPIO_WritePin(GPIO_10_GPIO_Port, GPIO_10_Pin, HIGH);

		HAL_Delay(100);
	}
}
void UART_Test(void)
{
	uint8_t UART_Buff[16] = {0};

	// LPUART1
	//HAL_UART_Receive(&hlpuart1, UART_Buff, 16, HAL_MAX_DELAY);
	//HAL_UART_Transmit(&hlpuart1, UART_Buff, 16, 100);

	memset(UART_Buff, 0, sizeof(UART_Buff));

	// USART1
	HAL_UART_Receive(&huart1, UART_Buff, 16, HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1, UART_Buff, 16, 100);

	memset(UART_Buff, 0, sizeof(UART_Buff));

	// USART2
	HAL_UART_Receive(&huart2, UART_Buff, 16, HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart2, UART_Buff, 16, 100);

	memset(UART_Buff, 0, sizeof(UART_Buff));

	// USART3
	HAL_UART_Receive(&huart3, UART_Buff, 16, HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, UART_Buff, 16, 100);

	memset(UART_Buff, 0, sizeof(UART_Buff));

	// UART4
	//HAL_UART_Receive(&huart4, UART_Buff, 16, HAL_MAX_DELAY);
	//HAL_UART_Transmit(&huart4, UART_Buff, 16, 100);

	memset(UART_Buff, 0, sizeof(UART_Buff));
}

void I2C_Test(void)
{

	uint8_t I2C_Buff[16] = {0};

	// I2C1
	//HAL_I2C_Slave_Receive(I2C1, I2C_Buff, 16, HAL_MAX_DELAY);
	HAL_I2C_Slave_Transmit(I2C1, I2C_Buff, 16, 100);

	memset(I2C_Buff, 0, 16*sizeof(I2C_Buff[0]));

	// I2C2
	//HAL_I2C_Slave_Receive(I2C2, I2C_Buff, 16, HAL_MAX_DELAY);
	HAL_I2C_Slave_Transmit(I2C2, I2C_Buff, 16, 100);

	memset(I2C_Buff, 0, 16*sizeof(I2C_Buff[0]));

	// I2C3
	//HAL_I2C_Slave_Receive(I2C3, I2C_Buff, 16, HAL_MAX_DELAY);
	HAL_I2C_Slave_Transmit(I2C3, I2C_Buff, 16, 100);

	memset(I2C_Buff, 0, 16*sizeof(I2C_Buff[0]));
}

void SPI_Test(void)
{
	uint8_t SPI_Transmit_Data [0x10]={0};
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12,GPIO_PIN_RESET);
	//HAL_SPI_Receive(&hspi1, SPI_Transmit_Data, sizeof(SPI_Transmit_Data),HAL_MAX_DELAY);
	//HAL_SPI_Transmit(&hspi1, SPI_Transmit_Data, sizeof(SPI_Transmit_Data),HAL_MAX_DELAY);
	HAL_SPI_WritePin(GPIOE, GPIO_PIN_12,GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12,GPIO_PIN_RESET);
	//HAL_SPI_Receive(&hspi1, SPI_Transmit_Data, sizeof(SPI_Transmit_Data),HAL_MAX_DELAY);
	//HAL_SPI_Transmit(&hspi1, SPI_Transmit_Data, sizeof(SPI_Transmit_Data),HAL_MAX_DELAY);
	HAL_SPI_WritePin(GPIOE, GPIO_PIN_12,GPIO_PIN_SET);
}

void MicroSD_Test(void)
{
	FRESULT res; /* FatFs function common result code */
	uint32_t byteswritten, bytesread; /* File write/read counts */
	uint8_t wtext[] = "STM32 FATFS works great!"; /* File write buffer */
	uint8_t rtext[_MAX_SS];/* File read buffer */

	if(f_mount(&SDFatFS, (TCHAR const*)SDPath, 0) != FR_OK)
	{
		Error_Handler();
	}
	else
	{
		if(f_mkfs((TCHAR const*)SDPath, FM_ANY, 0, rtext, sizeof(rtext)) != FR_OK)
		{
			Error_Handler();
		}
		else
		{
			//Open file for writing (Create)
			if(f_open(&SDFile, "STM32.TXT", FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
			{
				Error_Handler();
			}
			else
			{
				//Write to the text file
				res = f_write(&SDFile, wtext, strlen((char *)wtext), (void *)&byteswritten);
				if((byteswritten == 0) || (res != FR_OK))
				{
					Error_Handler();
				}
				else
				{
					f_close(&SDFile);
				}
			}
		}
	}
	f_mount(&SDFatFS, (TCHAR const*)NULL, 0);
}

void PWM_GEN(void)
{
	/*
	 * General Outline:
	 * Set the timers in the .ioc file to your liking
	 * Initialize the PWM timers
	 * Set a delay for x amount of time
	 * Stop the PWM timers
	 */
}

void PWM_DMA_GEN(void)
{

}
/*
 * Check GPIO Interlock Channels, should read HIGH.
 */
void Interlock_Check(void)
{

	char uartBuf[100];

	if(GPIO_IL_A_Pin)
	{
		sprintf(uartBuf, "[OK]	GPIO_IL_A\n");
		HAL_UART_Transmit(&huart1, (uint8_t *)uartBuf, strlen(uartBuf), 100);
	}
	if(GPIO_IL_B_Pin)
	{
		sprintf(uartBuf, "[OK]	GPIO_IL_B\n");
		HAL_UART_Transmit(&huart1, (uint8_t *)uartBuf, strlen(uartBuf), 100);
	}
	if(GPIO_IL_C_Pin)
	{
		sprintf(uartBuf, "[OK]	GPIO_IL_C\n");
		HAL_UART_Transmit(&huart1, (uint8_t *)uartBuf, strlen(uartBuf), 100);
	}
	if(GPIO_IL_D_Pin)
	{
		sprintf(uartBuf, "[OK]	GPIO_IL_D\n" );
		HAL_UART_Transmit(&huart1, (uint8_t *)uartBuf, strlen(uartBuf), 100);
	}
}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
