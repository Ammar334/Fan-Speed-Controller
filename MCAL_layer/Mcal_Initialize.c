/* 
 * File:   Mcal_Initialize.h
 * Author: AMMAR Yasser
 *
 * Created on 03/10/2023
 */


#include "Mcal_Initialize.h"


void ADC_callback(void);
CCP_t ccp_obj = {
  
    .PWM_Freq = 5000,
    .Timer2_Postscaler_value = CCP_POSTSCALER_DIV_1,
    .Timer2_Prescaler_value = CCP_PRESCALER_DIV_1,
    .CCP1CallBack = NULL,
    .ccp_inst = CCP1_inst,
    .ccp_spacific_mode = CCP_PWM_MODE,
    .cpp_mode = CCP_PWM_MODE_SELECT,
    .pin.direction = GPIO_OUTPUT,
    .pin.logic = GPIO_LOW,
    .pin.pin = GPIO_PIN2,
    .pin.port = GPIO_PORT_C
};

ADC_t Lm35 = {
  
    .ADC_CallBack = ADC_callback,
    .ADC_Channel = ADC_CHANNEL0,
    .Acquisition_Time = ADC_12TAD,
    .Prescaler = ADC_16FOSC,
    .Result_format = ADC_RIGHT_ADJUST,
    .voltage_refrence = ADC_INTERNAL_VREF
};

Timer2_t timer2 = {
  
    .Timer2CallBack = NULL,
    .postcaler_value = TIMER2_POSTSCALER_DIV_1,
    .prescaler_value = TIMER2_PRESCALER_DIV_1,
    .preload_value =0,
};

void ADC_callback(void)
{
    ADC_Read_Result(&Lm35,&res1);
    Flag = 0;
}


void Macl_initialize (void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = ADC_init(&Lm35);
    ret = CCP_Init(&ccp_obj);
    ret = Timer2_init(&timer2);
    
}
