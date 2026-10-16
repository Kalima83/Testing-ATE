#include "Test.h"

ResultadoDiagnostico_t Test_RunSimulated(void) {
    ResultadoDiagnostico_t res;

    // Cálculo probabilístico de salud entre 70% y 98%
    res.salud = (uint8_t)(70 + (HAL_GetTick() % 29));
    res.esApto = (res.salud > UMBRAL_SALUD_APTO); // Umbral >85%

    return res;
}
