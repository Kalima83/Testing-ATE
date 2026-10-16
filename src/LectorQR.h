/*
 * LectorQR.h
 *
 *  Created on: Aug 21, 2026
 *      Author: danie
 */

#ifndef APP_INC_LECTORQR_H_
#define APP_INC_LECTORQR_H_

#include <stdbool.h>
#include <stdint.h>

#define QR_BUFFER_SIZE 128

void LectorQR_Init(void);
void LectorQR_ProcessChar(uint8_t c);

bool LectorQR_IsDataReady(void);
const char *LectorQR_GetNI(void);
void LectorQR_Reset(void);

#endif /* APP_INC_LECTORQR_H_ */
