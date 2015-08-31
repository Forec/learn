#include <reg52.h>        

void main()
{
    unsigned int i,j;
	while(1){
        for (i=0;i<=8;i++){
            P1= ~(0xFF >> i);
            for (j=0;j<30000;j++);
        }
        for (i=1;i<8;i++){
            P1= (0xFF << i);
            for (j=0;j<30000;j++);
        }                
    }                      
}