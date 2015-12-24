#include <reg52.h>

sbit we = P2^7;
sbit du = P2^6;

unsigned char code LedChar[] = {
    0xC0 , 0xF9 , 0xA4 , 0xB0 , 0x99 , 0x92 , 0x82 , 0xF8 ,
    0x80 , 0x90// , 0x88 , 0x83 , 0xC6 , 0xA1 , 0x86 , 0x8E
    };
unsigned char code Position[] = {
    0x7F , 0xBF , 0xDF , 0xEF ,0xF7 , 0xFB , 0xFD , 0xFE
    };

unsigned char LedBuff[] =  {
    0 , 0 , 0 , 0 , 0 , 0 , 0 ,0 
    };

void main(){
    unsigned int cnt = 0 ;
    unsigned long sec = 0 ;
    unsigned char i = 0;

    we = 1;
    P0 = Position[0];
    we = 0;
    du = 1;
    P0 = ~LedChar[0];
    du = 0; 
    TMOD = 0x01;
    TH0 = 0xFC;
    TL0 = 0x67;
    TR0 = 1;
    while (1){
        if (TF0 == 1){
            cnt++;
            TF0 = 0;
            TH0 = 0xFC;
            TL0 = 0x67;
            if (cnt>=1000){
                cnt = 0;
                sec++;
                LedBuff[0] = ~LedChar[sec%10];
                LedBuff[1] = ~LedChar[sec/10%10];
                LedBuff[2] = ~LedChar[sec/100%10];
                LedBuff[3] = ~LedChar[sec/1000%10];
                LedBuff[4] = ~LedChar[sec/10000%10];
                LedBuff[5] = ~LedChar[sec/100000%10];
            }
            we = 1;
            P0 = 0xFF;
            we = 0;
            if (i==0){
                we = 1;
                P0 = Position[0];
                we = 0;
                du = 1;
                P0 = LedBuff[0];
                du = 0;
                i++;
            }
            else if (i==1){
                we = 1;
                P0 = Position[1];
                we = 0;
                du = 1;
                P0 = LedBuff[1];
                du = 0;
                i++;
            }
            else if (i==2){
                we = 1;
                P0 = Position[2];
                we = 0;
                du = 1;
                P0 = LedBuff[2];
                du = 0;
                i++;
            }
            else if (i==3){
                we = 1;
                P0 = Position[3];
                we = 0;
                du = 1;
                P0 = LedBuff[3];
                du = 0;
                i++;
            }
            else if (i==4){
                we = 1;
                P0 = Position[4];
                we = 0;
                du = 1;
                P0 = LedBuff[4];
                du = 0;
                i++;
            }
            else if (i==5){
                we = 1;
                P0 = Position[5];
                we = 0;
                du = 1;
                P0 = LedBuff[5];
                du = 0;
                i=0;
            }
        }
    }       
}