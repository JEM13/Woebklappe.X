/* 
 * File:   flash.h
 * Author: JM_BaSyTec
 *
 * Created on 30. April 2018, 13:47
 */

#ifndef FLASH_H
#define	FLASH_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    typedef struct flapPos {
        uint8_t pos1; 
        uint8_t pos2; 
        uint8_t pos3; 
        uint8_t pos4; 
        uint8_t pos5; 
        uint8_t posL;
    } flapPos_t;
    
void storeFlapPos(flapPos_t posL);
flapPos_t readFlapPos();


#ifdef	__cplusplus
}
#endif

#endif	/* FLASH_H */

