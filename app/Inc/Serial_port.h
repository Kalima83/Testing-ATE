/*
 * Serial_port.h
 *
 *  Created on: Aug 21, 2026
 *      Author: danie
 */

#ifndef APP_INC_SERIAL_PORT_H_
#define APP_INC_SERIAL_PORT_H_

#include "stm32f4xx_hal.h"
#include "Test.h"
#include <stdio.h>
#include <string.h>

void SerialPort_Init(UART_HandleTypeDef *huart);
void SerialPort_SendString(const char *str);
void SerialPort_PrintWelcome(void);
void SerialPort_PrintError(const char *msg);
void SerialPort_PrintReport(const char *ni, ResultadoDiagnostico_t res);



#endif /* APP_INC_SERIAL_PORT_H_ */
