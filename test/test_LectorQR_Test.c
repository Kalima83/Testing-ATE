#include "unity.h"
#include "LectorQR.h"
#include "Test.h"

void setUp(void) {
    LectorQR_Reset(); // Limpia el buffer antes de cada prueba
}

void tearDown(void) {}

// Test 1: Verificar que el reset limpie el buffer y resetee la bandera dataReady
void test_LectorQR_Reset_DebeLimpiarBuffer(void) {
    LectorQR_ProcessChar('A');
    LectorQR_ProcessChar('\r');
    
    LectorQR_Reset();
    
    TEST_ASSERT_EQUAL_STRING("", LectorQR_GetNI());
    TEST_ASSERT_FALSE(LectorQR_IsDataReady());
}

// Test 2: Verificar la inyección de caracteres y detección de fin de trama (\r)
void test_LectorQR_DebeProcesarTramaValida(void) {
    const char *trama = "NI-2026-ARM-01";
    for (int i = 0; trama[i] != '\0'; i++) {
        LectorQR_ProcessChar((uint8_t)trama[i]);
    }
    LectorQR_ProcessChar('\r'); // Terminador de trama

    TEST_ASSERT_TRUE(LectorQR_IsDataReady());
    TEST_ASSERT_EQUAL_STRING("NI-2026-ARM-01", LectorQR_GetNI());
}

// Test 3: Verificación de la regla de negocio de salud (>85% -> Apto) sobre el struct real
void test_Diagnostic_Engine_DebeClasificarAptoOnoApto(void) {
    ResultadoDiagnostico_t res = Test_RunSimulated();
    
    // Verificamos que res.esApto sea consistente con res.salud y UMBRAL_SALUD_APTO (85)
    TEST_ASSERT_EQUAL(res.salud > UMBRAL_SALUD_APTO, res.esApto);
}