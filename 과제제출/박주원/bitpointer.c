#include<stdio.h>

int main(){
    printf("6-3 = %d\n",6-3);
        //16진법 6-3 = 
    printf("6-3 = %d\n",0x00000006 - 0x00000003);
        //16진법 보수 계산법 ,궁금증 : ~ : -4  -: -3
    printf("6-3 = %d\n",0x00000006 + (~0x00000003+1));

int nInput = 10;
if (nInput & 0x0000006)
    puts("odd number\n");
else 
    puts("even number\n");

    return 0;
}
