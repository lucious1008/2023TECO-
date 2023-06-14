#include<stdio.h>
#include<string.h>
#define MONTHS 12

int main(){

    int high[MONTHS] ={2, 5 , 11 ,18 ,23 ,27 ,29, 30, 26, 20, 12, 4};

    for(int i=0; i<MONTHS; ++i)
        printf("%d ",high[i]);
    printf("\n");

    float avg = 0.0;
    for(int i = 0; i<MONTHS; ++i)
        avg +=high[i];
    printf("Average = %f\n",avg/(float)MONTHS);

    high[0] =1;
    high[1] =2;

    printf("%p %p\n",high,&high[0]);
    for (int i =0; i< MONTHS; ++i)
        printf("%lld\n",(long long)&high[i]);
    printf("\n");

    /*Omitting size*/  //빈칸 = 오른쪽 개수
    const int power_of_twos[] = {1,2,4,8,16,32,64};
    printf("%d\n",sizeof (power_of_twos));
}