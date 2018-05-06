/* 
 * File:   ADCcon.c
 * Author: JM_BaSyTec
 *
 * Created on 29. April 2018, 21:52
 */

#include <pic16f15323.h>
#include "ADCcon.h"

/*
 * 
 */

inline void triggerConversion(unsigned int RAx) {
    ADCON1 = 0;
    ADCON1 = ( (RAx<<2) | 1);
}

inline void waitConversionDone() {
   do {
  
   } while ( (ADCON1 & 2) != 0 );
}

inline unsigned int getConversionResult() {
    return (ADRESH << 8) | ADRESL;
}

uint8_t readAD_FlapPos() {
  triggerConversion(5); 
  waitConversionDone();
  return getConversionResult();
}