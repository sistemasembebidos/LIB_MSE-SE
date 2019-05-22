/*
 * I2C.h
 *
 *  Created on: 22 mar. 2019
 *      Author: BEL
 */
#include "..\inc\CommonIO.h"

//-----------Definiciones I2C---------------------------
#define I2C_ADDRESS        0x3E  /* Valor real de la direccion de 7-bits del esclavo. Equivale a (uint8_t) 0x1F
									y puede verse en el registro OAR1 en los bits ADD[1:7] (Ejemplo AdvComIT) */
#define MASTER_REQ_READ    0x12	// (Comando de lectura: Ejemplo AdvComIT)
#define MASTER_REQ_WRITE   0x34	// (Comando de escritura: Ejemplo AdvComIT)

/* Definicion de recursos de clock de I2Cx */
#define I2Cx                             I2C2
#define I2Cx_CLK_ENABLE()                __HAL_RCC_I2C2_CLK_ENABLE()
#define I2Cx_SDA_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOB_CLK_ENABLE()
#define I2Cx_SCL_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOB_CLK_ENABLE()
#define I2Cx_FORCE_RESET()               __HAL_RCC_I2C2_FORCE_RESET()
#define I2Cx_RELEASE_RESET()             __HAL_RCC_I2C2_RELEASE_RESET()

/* Asignacion/Definicion de Pines para I2Cx */
#define I2Cx_SCL_PIN                    GPIO_PIN_10
#define I2Cx_SCL_GPIO_PORT              GPIOB
#define I2Cx_SCL_AF                     GPIO_AF4_I2C2
#define I2Cx_SDA_PIN                    GPIO_PIN_11
#define I2Cx_SDA_GPIO_PORT              GPIOB
#define I2Cx_SDA_AF                     GPIO_AF4_I2C2

/* Definicion de NVIC de I2Cx */
#define I2Cx_EV_IRQn                    I2C2_EV_IRQn
#define I2Cx_EV_IRQHandler              I2C2_EV_IRQHandler
#define I2Cx_ER_IRQn                    I2C2_ER_IRQn
#define I2Cx_ER_IRQHandler              I2C2_ER_IRQHandler
//-----------------------------------------------------------------------------

/* Exported macro ------------------------------------------------------------*/
#define COUNTOF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))
//-----------------------------------------------------------------------------

/* I2C handler declaration */
I2C_HandleTypeDef I2cHandle;

void I2C_Init(void);

