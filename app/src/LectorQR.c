#include "LectorQR.h"
#include <string.h>

static char rxBuffer[QR_BUFFER_SIZE];
static uint8_t rxIndex = 0;
static volatile bool dataReady = false;

void LectorQR_Init(void)
{
    LectorQR_Reset();
}

void LectorQR_ProcessChar(uint8_t c)
{
    if (c == '\r' || c == '\n')
    {
        if (rxIndex > 0 && !dataReady)
        {
            rxBuffer[rxIndex] = '\0';
            dataReady = true;
        }
    }
    else if (rxIndex < (QR_BUFFER_SIZE - 1) && !dataReady)
    {
        rxBuffer[rxIndex++] = (char)c;
    }
}

bool LectorQR_IsDataReady(void)
{
    return dataReady;
}

const char *LectorQR_GetNI(void)
{
    return rxBuffer;
}

void LectorQR_Reset(void)
{
    memset(rxBuffer, 0, QR_BUFFER_SIZE);
    rxIndex = 0;
    dataReady = false;
}
