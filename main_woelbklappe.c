/* 
 * File:   main_woelbklappe.c
 * Author: JM_BaSyTec
 *
 * Created on 18. April 2018, 12:50
 */


#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "initialize.h"
#include "DigIO.h"
#include "ADCcon.h"
#include "flash.h"

typedef struct {
    uint8_t min;
    uint8_t max;
}  ledThreshold_t;

int main(int argc, char** argv) {
    initializePIC();
    
    //Nach power up
    //alle LEDs Blinken
    //1mal Taster
    //klappenposition 1 einlesen (LED1 blinkt))
      //bestätiggung durch taster 
      //..> klappenposition L einlesen (LED l blinkt))
    
    flapPos_t posData = readFlapPos();
    
    ledThreshold_t led1_Threshold = {posData.pos1-100, posData.pos1+100};
    ledThreshold_t led2_Threshold = {posData.pos2-100, posData.pos2+100};
    ledThreshold_t led3_Threshold = {posData.pos3-100, posData.pos3+100};
    ledThreshold_t led4_Threshold = {posData.pos4-100, posData.pos4+100};
    ledThreshold_t led5_Threshold = {posData.pos5-100, posData.pos5+100};
    ledThreshold_t ledL_Threshold = {posData.posL-100, posData.posL+100};
    
    
    while (1) {
        
        
        
        uint8_t currentFlapPos = readAD_FlapPos();
        
        if(currentFlapPos<=led1_Threshold.max && currentFlapPos>led2_Threshold.max) {
            LED_1_ON();
        }else {
            LED_1_OFF();
        }
        
        if(currentFlapPos<=led2_Threshold.min && currentFlapPos>led3_Threshold.max) {
            LED_2_ON();
        }else {
            LED_2_OFF();
        }
        
        
        if(currentFlapPos<=led3_Threshold.min && currentFlapPos>led4_Threshold.max) {
            LED_3_ON();
        }else {
            LED_3_OFF();
        }
        
       // DOZEN = 0;
       //Klappenposition lesen
       //Umschaltposition lesen
       //Led Setzen
       //LX Trigger prüfen
       //LX Schalten
        
       // DOZEN = 1;
       // SLEEP; // WDT wird genullt und pic geht in den Sleep. WDT läuft weiter und PIC wacht mit WDT auf
    }
    
    return (EXIT_SUCCESS);
}

void learn() {
    flapPos_t posData;
    
    LED_ALL_BLINK(3, 500, 250);
        
    LED_1_ON();
    posData.pos1 = handleButtonPressed(&readAD_FlapPos);
    LED_1_OFF();
    
    LED_2_ON();
    posData.pos2 = handleButtonPressed(&readAD_FlapPos);
    LED_2_OFF();
    
    LED_3_ON();
    posData.pos3 = handleButtonPressed(&readAD_FlapPos);
    LED_3_OFF();
    
    LED_4_ON();
    posData.pos4 = handleButtonPressed(&readAD_FlapPos);
    LED_4_OFF();
    
    LED_5_ON();
    posData.pos5 = handleButtonPressed(&readAD_FlapPos);
    LED_5_OFF();
    
    LED_L_ON();
    posData.posL = handleButtonPressed(&readAD_FlapPos);
    LED_L_OFF();
    
    storeFlapPos(posData);
    
    //reboot()
}

