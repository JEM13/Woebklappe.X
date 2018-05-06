/* 
 * File:   ADCcon.h
 * Author: JM_BaSyTec
 *
 * Created on 29. April 2018, 21:49
 */

#ifndef ADCCON_H
#define	ADCCON_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdint.h>
    
    
#define ADCconvertRA5 b'00010101' //  000101(RA5) 0 1(Enable)
#define ADCconvertRA4 b'00010001' //  000101(RA4) 0 1(Enable)
    
uint8_t readAD_FlapPos();

#ifdef	__cplusplus
}
#endif

#endif	/* ADCCON_H */

