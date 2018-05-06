/* 
 * File:   initialize.c
 * Author: JM_BaSyTec
 *
 * Created on 29. April 2018, 18:37
 */

#include <stdio.h>
#include <stdlib.h>
#include "initialize.h"

/*
 * 
 */
void initializePIC() {
    //REGISTER 10-1: INTCON: INTERRUPT CONTROL REGISTER
    GIE = 0;//; //Disable all interrupts
    PEIE = 0;//Disables all peripheral interrupts
    
    
    //14.0 I/O PORTS
    
    /*
    TABLE 14-2: SUMMARY OF REGISTERS ASSOCIATED WITH PORTA
    Name Bit 7 Bit 6 Bit 5 Bit 4 Bit 3 Bit 2 Bit 1 Bit 0 Register
    on Page
    PORTA ? ? RA5 RA4 RA3 RA2 RA1 RA0 175
    TRISA ? ? TRISA5 TRISA4 ? TRISA2 TRISA1 TRISA0 175
    LATA ? ? LATA5 LATA4 ? LATA2 LATA1 LATA0 176
    ANSELA ? ? ANSA5 ANSA4 ? ANSA2 ANSA1 ANSA0 176
    WPUA ? ? WPUA5 WPUA4 WPUA3 WPUA2 WPUA1 WPUA0 177
    ODCONA ? ? ODCA5 ODCA4 ? ODCA2 ODCA1 ODCA0 177
    SLRCONA ? ? SLRA5 SLRA4 ? SLRA2 SLRA1 SLRA0 178
    INLVLA ? ? INLVLA5 INLVLA4 INLVLA3 INLVLA2 INLVLA1 INLVLA0 178     
     */
    
    
    //REGISTER 14-1: PORTA: PORTA REGISTER// Writes to PORTA are actually written to corresponding LATA register. Reads from PORTA register returns of actual I/O pin values.
    //REGISTER 14-3: LATA: PORTA DATA LATCH REGISTER// Writes to PORTA are actually written to corresponding LATA register. Reads from PORTA register returns of actual I/O pin values.
    LATA = 0x01;// B'000001'; //LX Toggle auf high initialisieren
    //PORTA = B'000001'; //LX Toggle auf high initialisieren
    //REGISTER 14-2: TRISA: PORTA TRI-STATE REGISTER
    TRISA = 0x30;//B'110000'; //AD-Eingänge (RA5,RA4) LX Toggle (RA0) als output initialisieren (eventl muss RA0 noch output werden um interrupt auslösen zu können)
    //REGISTER 14-4: ANSELA: PORTA ANALOG SELECT REGISTER
    ANSELA = 0x30;//B'110000'; //AD-Eingänge (RA5,RA4)
    //REGISTER 14-5: WPUA: WEAK PULL-UP PORTA REGISTER
    WPUA = 0x30;//B'000001'; //LX Toggle auf high halte damit Taster gegen ground ggf wirkung hat
    //REGISTER 14-6: ODCONA: PORTA OPEN-DRAIN CONTROL REGISTER
    ODCONA = 0;
    //REGISTER 14-7: SLRCONA: PORTA SLEW RATE CONTROL REGISTER
    SLRCONA = 0;
    //REGISTER 14-8: INLVLA: PORTA INPUT LEVEL CONTROL REGISTER
    INLVLA = 0;
    
    //*************************************************************
    /*
    TABLE 14-3: SUMMARY OF REGISTERS ASSOCIATED WITH PORTC
    Name Bit 7 Bit 6 Bit 5 Bit 4 Bit 3 Bit 2 Bit 1 Bit 0 Register
    on Page
    PORTC ? ? RC5 RC4 RC3 RC2 RC1 RC0 181
    TRISC ? ? TRISC5 TRISC4 TRISC3 TRISC2 TRISC1 TRISC0 181
    LATC ? ? LATC5 LATC4 LATC3 LATC2 LATC1 LATC0 181
    ANSELC ? ? ANSC5 ANSC4 ANSC3 ANSC2 ANSC1 ANSC0 182
    WPUC ? ? WPUC5 WPUC4 WPUC3 WPUC2 WPUC1 WPUC0 182
    ODCONC ? ? ODCC5 ODCC4 ODCC3 ODCC2 ODCC1 ODCC0 183
    SLRCONC ? ? SLRC5 SLRC4 SLRC3 SLRC2 SLRC1 SLRC0 183
    INLVLC ? ? INLVLC5 INLVLC4 INLVLC3 INLVLC2 INLVLC1 INLVLC0 183     
     */
    
    //REGISTER 14-9: PORTC: PORTC REGISTER
     //REGISTER 14-11: LATC: PORTC DATA LATCH REGISTER
    //PORTC = 0; //Alle LED Aus
    LATC = 0; //Alle LED Aus
    //REGISTER 14-10: TRISC: PORTC TRI-STATE REGISTER
    TRISC = 0; //Alle LED Out  
    //REGISTER 14-12: ANSELC: PORTC ANALOG SELECT REGISTER
    ANSELC = 0;
    //REGISTER 14-13: WPUC: WEAK PULL-UP PORTC REGISTER
    WPUC = 0;
    //REGISTER 14-14: ODCONC: PORTC OPEN-DRAIN CONTROL REGISTER
    ODCONC = 0;
    //REGISTER 14-15: SLRCONC: PORTC SLEW RATE CONTROL REGISTER
    SLRCONC = 0;
    //REGISTER 14-16: INLVLC: PORTC INPUT LEVEL CONTROL REGISTER
    INLVLC = 0;
    
    
    //15.0 PERIPHERAL PIN SELECT (PPS) MODUL    
    //ADCON0  //AD-Eingänge (RA5,RA4) register wird zur laufzeit geschrieben       
    ADCON1 = 0; //Alled default passt erstmal vDD ist Vref -> wenn man den Teiler mit Vdd versorgt ist der digitalwert immer gleich
            
    //17.0 INTERRUPT-ON-CHANGE
    IOCAN = 0x01;//'000001'; //LX Trigger muss auslösen wenn taster gedrückt wird
            
    //20.1 ADC Configuration

    
}

