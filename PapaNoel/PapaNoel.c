#include <16F628A.h>
#FUSES NOWDT
#FUSES NOPUT
#FUSES MCLR
#FUSES NOBROWNOUT
#FUSES NOPROTECT
#FUSES NOCPD
#use delay(crystal=4M)


#define SENSOR      PIN_A2
#define SONIDO      PIN_A1
#define MOTOR       PIN_B3

void main(void){
    output_low(SONIDO);
    output_high(MOTOR);
    while(TRUE){
        if(!input_state(SENSOR)){
            output_high(SONIDO);
            output_low(MOTOR);
            for(int i = 0; i < 15; i++){
                delay_ms(10000);
                output_high(SONIDO);
                output_low(MOTOR);
            }
            output_low(SONIDO);
            output_high(MOTOR);
            delay_ms(100);
        }
    }
}

