#include "Serial_port.h"

static UART_HandleTypeDef *hSerialUart = NULL;

void SerialPort_Init(UART_HandleTypeDef *huart) {
    hSerialUart = huart;
}

void SerialPort_SendString(const char *str) {
    if (hSerialUart != NULL && str != NULL) {
        HAL_UART_Transmit(hSerialUart, (uint8_t*)str, (uint16_t)strlen(str), HAL_MAX_DELAY);
    }
}

void SerialPort_PrintWelcome(void) {
    SerialPort_SendString("\r\n==========================================================\r\n");
    SerialPort_SendString("           SISTEMA ATE LOGISTICO - EJERCITO ARGENTINO     \r\n");
    SerialPort_SendString("==========================================================\r\n");
    SerialPort_SendString("[ESTADO]: ESPERA_QR - Apunte el lector al codigo del equipo...\r\n");
}

void SerialPort_PrintError(const char *msg) {
    char errBuffer[128];
    snprintf(errBuffer, sizeof(errBuffer), "\r\n[ERROR]: %s\r\n", msg);
    SerialPort_SendString(errBuffer);
}

void SerialPort_PrintReport(const char *ni, ResultadoDiagnostico_t res) {
    char msg[600];
    snprintf(msg, sizeof(msg),
        "\r\n----------------------------------------------------------\r\n"
        "                 INFORME DE DIAGNOSTICO FINAL            \r\n"
        "----------------------------------------------------------\r\n"
        "  Numero de Identificacion (NI) : %s\r\n"
        "  Porcentaje de Salud Estimado  : %d%%\r\n"
        "  Umbral Operativo Exigido      : %d%%\r\n"
        "  VEREDICTO FINAL               : [ %s ]\r\n"
        "----------------------------------------------------------\r\n"
        "[ESTADO]: Retornando a ESPERA_QR...\r\n"
        "==========================================================\r\n\r\n",
        ni, res.salud, UMBRAL_SALUD_APTO,
        res.esApto ? "APTO PARA DESPLIEGUE" : "NO APTO - REQUIERE SERVICE");

    SerialPort_SendString(msg);
}
