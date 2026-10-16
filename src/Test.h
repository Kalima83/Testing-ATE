/*
 * Test.h
 *
 *  Created on: Aug 21, 2026
 *      Author: danie
 */

#ifndef APP_INC_TEST_H_
#define APP_INC_TEST_H_

// Solo incluimos el HAL de ST si NO estamos en entorno de prueba unitaria (Ceedling/Host)
#ifndef TEST
#include "stm32f4xx_hal.h"
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define UMBRAL_SALUD_APTO 85

typedef struct {
    uint8_t salud;
    bool esApto;
} ResultadoDiagnostico_t;

ResultadoDiagnostico_t Test_RunSimulated(void);

#ifndef TEST
void Test_ImprimirInforme(UART_HandleTypeDef *huart, const char *ni, ResultadoDiagnostico_t res);
#endif

#endif /* APP_INC_TEST_H_ */