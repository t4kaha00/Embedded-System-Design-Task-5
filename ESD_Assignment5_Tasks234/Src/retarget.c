#include "main.h"


void SWO_Init(void) {

	setvbuf(stdout, NULL, _IONBF, 0);                     // disable buffering
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;       // Enable trace
    ITM->LAR  = 0xC5ACCE55;                               // Unlock ITM
    ITM->TCR  = ITM_TCR_ITMENA_Msk |                      // Enable ITM
                ITM_TCR_SYNCENA_Msk |
                (1 << ITM_TCR_TSENA_Pos);                 // Timestamp if you like put _nop with label _ak3
    ITM->TER  = 1;                                        // Enable stimulus port 0
}
int _write(int file, char *ptr, int len) {               
    for (int i = 0; i < len; i++) {
        // Wait until stimulus port 0 is ready
        while ((ITM->TCR & ITM_TCR_ITMENA_Msk) == 0 ||    // ITM not enabled
               (ITM->TER & 1UL) == 0);                    // Port 0 not enabled

        ITM->PORT[0].u8 = *ptr++;                          // Print __ptr_ak2_nop
    }
    return len;
}
