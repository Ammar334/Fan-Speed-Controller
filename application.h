/* 
 * File:   applications.h
 * Author: Ammar.Yasser
 *
 * Created on 21 ?????, 2023, 06:18 ?
 */

#ifndef APPLICATIONS_H
#define	APPLICATIONS_H


/******Includes**********/
#include "ECU_layer/ecu_initialize.h"
#include "MCAL_layer/Mcal_Initialize.h"

/*********Macro Declaration***********/

/*********Macro Function Declaration***********/
/*********Data Types Declaration***********/
extern dc_motor_t motor_1;
extern lcd_8bit_t lcd_1; 
extern ADC_t Lm35;
extern CCP_t ccp_obj;
extern Timer2_t timer2;

        
/*********Function Declaration***********/
void application_initialize (void);
void ecu_initialize (void);
void Macl_initialize (void);

#endif	/* APPLICATIONS_H */

