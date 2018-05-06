/* 
 * File:   DigIO.h
 * Author: JM_BaSyTec
 *
 * Created on 29. April 2018, 21:08
 */

#ifndef DIGIO_H
#define	DIGIO_H

#ifdef	__cplusplus
extern "C" {
#endif

//LX Toggle bit
#define LX_LAT = LATA0_bit
//LED LATCH Bits
#define LED_ON 1
#define LED_OFF 0
#define LED_LAT_L LATA0
#define LED_LAT_5 LATA2
#define LED_LAT_4 LATC0
#define LED_LAT_3 LATC1
#define LED_LAT_2 LATC2
#define LED_LAT_1 LATC3
    
static inline void LED_L_OFF() {
    LED_LAT_L = LED_OFF;
}
static inline void LED_L_ON() {
    LED_LAT_L = LED_ON;
}
static inline void LED_5_OFF() {
    LED_LAT_5 = LED_OFF;
}
static inline void LED_5_ON() {
    LED_LAT_5 = LED_ON;
}
static inline void LED_4_OFF() {
    LED_LAT_4 = LED_OFF;
}
static inline void LED_4_ON() {
    LED_LAT_4 = LED_ON;
}
static inline void LED_3_OFF() {
    LED_LAT_3 = LED_OFF;
}
static inline void LED_3_ON() {
    LED_LAT_3 = LED_ON;
}
static inline void LED_2_OFF() {
    LED_LAT_2 = LED_OFF;
}
static inline void LED_2_ON() {
    LED_LAT_2 = LED_ON;
}
static inline void LED_1_OFF() {
    LED_LAT_1 = LED_OFF;
}
static inline void LED_1_ON() {
    LED_LAT_1 = LED_ON;
}
static inline void LED_ALL_OFF() {
    LED_1_OFF();
    LED_2_OFF();
    LED_3_OFF();
    LED_4_OFF();
    LED_5_OFF();
    LED_L_OFF();
}
static inline void LED_ALL_ON() {
    LED_1_ON();
    LED_2_ON();
    LED_3_ON();
    LED_4_ON();
    LED_5_ON();
    LED_L_ON();
}

static inline void LED_ALL_BLINK(uint8_t cycles, uint8_t onTime, uint8_t offTime) {
    for (uint8_t i = 0; i < cycles; i++) {
        LED_ALL_ON();
        __delay_ms(onTime);
        LED_ALL_OFF();
        if(i<cycles) {
            __delay_ms(offTime);
        }
    }
}

uint16_t handleButtonPressed(uint16_t (*handler)());

#ifdef	__cplusplus
}
#endif

#endif	/* DIGIO_H */

