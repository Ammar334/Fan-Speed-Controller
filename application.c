/* 
 * 
 * File:   application.c
 * Author: Ammar.Yasser
 *
 * Created on 21 ?????, 2023, 06:12 ?
 */

#include "application.h"

Std_ReturnType ret = E_NOT_OK; 
uint16 res1=0;
uint16 temp =0; 
volatile uint8 Flag = 0;
void ADC_callback(void);



uint8 Temp_value[11] ={0};

int main() {
    
    application_initialize();
    ret = lcd_8bit_send_string_pos(&lcd_1,1,1,"Temperature : ");
    ret = lcd_8bit_send_string_pos(&lcd_1,3,1,"Fan Level :- ");
    ret = dc_motor_move_right(&motor_1);
    while(1)
    {
        if(Flag == 0)
        {
            ret=ADC_StartConversion_INT(&Lm35,ADC_CHANNEL0);
            Flag = 1;
        }      
        temp = res1 * 4.8828125f;
        temp /= 10;
        
        ret = convert_short_to_string(temp,Temp_value);
        ret = lcd_8bit_send_string_pos(&lcd_1,1,15,Temp_value);
        
        if(temp>=90)
        {
            ret = CCP_PWM_set_DutyCycle(&ccp_obj,100);
            ret = lcd_8bit_send_string_pos(&lcd_1,4,1,"Level 5");
            ret = CCP_PWM_Start(&ccp_obj);
        }
        else if(temp>=70)
        {
            ret = CCP_PWM_set_DutyCycle(&ccp_obj,80);
            ret = lcd_8bit_send_string_pos(&lcd_1,4,1,"Level 4");
            ret = CCP_PWM_Start(&ccp_obj);
        }   
        else if(temp>=50)
        {
            ret = CCP_PWM_set_DutyCycle(&ccp_obj,60);
            ret = lcd_8bit_send_string_pos(&lcd_1,4,1,"Level 3");
            ret = CCP_PWM_Start(&ccp_obj);
        }
        else if(temp>=30)
        {
            ret = CCP_PWM_set_DutyCycle(&ccp_obj,40);
            ret = lcd_8bit_send_string_pos(&lcd_1,4,1,"Level 2");
            ret = CCP_PWM_Start(&ccp_obj);
        }
        else if(temp>=22)
        {
            ret = CCP_PWM_set_DutyCycle(&ccp_obj,20);
            ret = lcd_8bit_send_string_pos(&lcd_1,4,1,"Level 1");
            ret = CCP_PWM_Start(&ccp_obj);
        }
        else
        {
            ret = CCP_PWM_Stop(&ccp_obj);
            ret = lcd_8bit_send_string_pos(&lcd_1,4,1,"Fan OFF");
        }
        
        
    }
    return (0);
}

void application_initialize (void)
{
    Macl_initialize();
    ecu_initialize();
}


