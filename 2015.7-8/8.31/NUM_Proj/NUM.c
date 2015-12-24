#include <reg52.h>

sbit we = P2^7;
sbit du = P2^6;

unsigned char code LedChar[] = {
    0xC0 , 0xF9 , 0xA4 , 0xB0 , 0x99 , 0x92 , 0x82 , 0xF8 ,
    0x80 , 0x90// , 0x88 , 0x83 , 0xC6 , 0xA1 , 0x86 , 0x8E
    };
unsigned char code Position[] = {
    0x7F , 0xBF , 0xDF , 0xEF ,0x07 , 0x0B , 0x0D , 0x0E
    };

void delay(int k){
    unsigned char i = 0;
    unsigned char sor = 0;
    for (i = 0 ; i< k; i++)
    for (sor = 0 ; sor < 180 ; sor ++);
}

void main(){
    unsigned int cnt = 0 ;
    unsigned int intervals = 5 ;
    unsigned int sec = 0 ;
    unsigned char ops = 0;
    unsigned char i = 0;
    unsigned int base = 1;

    unsigned char j = 0;
    unsigned int temp = 0;

    we = 1;
    P0 = Position[0];
    we = 0;
    du = 1;
    P0 = ~LedChar[0];
    du = 0; 
    TMOD = 0x01;
    TH0 = 0xB8;
    TL0 = 0x00;
    TR0 = 1;
    while (1){
        if (TF0 == 1){
            cnt++;
            TF0 = 0;
            TH0 = 0xB8;
            TL0 = 0x00;
            if (cnt>=5){
                sec++;
                if (sec >= intervals*2){
                    ops++;
                    intervals*=10;
                }
                cnt = 0;
            }
            temp = sec;
            
       //     delay(2);
            for (i = 0 ; i <= ops;i++){
                base = 1;
                if ( i < ops )  {
                for (j = 0 ; j < ops - i; j ++ )
                    base *= 10;
                }    
                du = 1;    
                P0 = 0x00;
                du = 0;
                we = 1;
                P0 = 0xFF;
                we = 0; 
                we = 1;
           //     delay((9-ops)/2+1);
                P0 = Position[ops - i];
                we = 0;
                du = 1;
                P0 = 0x00;
                du = 0;
                delay((9-ops)/2+1);
                du = 1;
                if (i == ops - 1)
                    P0 = (~LedChar[temp/base]|0x80);
                else 
                    P0 = ~LedChar[temp/base];
                du = 0;
                temp -=( temp/base *base);
                delay((9-ops)/2+1);
            }
        }
    }       
}