#include <reg52.h>

sbit LED0 = P1^0;
sbit LED1 = P1^2;

void main(){
    unsigned char cnt0 = 0;
    unsigned char cnt1 = 0;
    TMOD = 0x11;
    TH0 = 0xB8;
    TL0 = 0x00;
    TH1 = 0xB8;
    TL1 = 0x00;
    TR0 = 1;
    TR1 = 1;
    LED0 = 0;
    LED1 = 0;
    while (1){
        if (TF0==1){
            TF0=0;
            TH0 = 0xB8;
            TL0 = 0x00;
            cnt0++;
            if (cnt0>=50){
                cnt0 = 0;
                LED0 = ~LED0;
            }
        }
        if (TF1 == 1){
            TF1 = 0;
            TH1 = 0xB8;
            TL1 = 0x00;
            cnt1++;
            if (cnt1>=100){
                cnt1 = 0;
                LED1 = ~LED1;
            }    
        }
    }
}