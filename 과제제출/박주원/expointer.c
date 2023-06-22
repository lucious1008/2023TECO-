// ==포인터==
    //asterisk 용도
    //1.포인터를 선언할때
    //2.해당 주소에 값이 접근하는 용도
#include<stdio.h>
int add ( int num1, int num2){
    return num2 - num1;
}

void swap(int* num1, int* num2){ //포인터를 받는다.
    int change;
    //스왑
    change = *num1; //
    *num1 = *num2;
    *num2 = change;
}
int main(){
    int a = 5;
    int b = 10;

    int* ptr;  //1. 포인터를 선언
    int* ptr2; //1. 포인터를 선언

    // ptr = &a; //a 변수의 주소 대입
    // ptr2 = &b; //b 변수의 주소 대입

    //2. 출력 *(asterisk)에 해당 주소에 값을 접근
    printf("value of ptr is %d\n",*ptr);
   
    //스왑 출력
    swap(&a,&b);
    printf("\n\nafter swap\n\n");
    printf("a=%d\nb=%d",a,b);

    printf("b - a = %d\n", *ptr2 - *ptr);
    //2. 포인터 연산도 가능

    printf("num2 - num1 = %d\n", add(*ptr,*ptr2));
    //2.함수로 리턴하여 변수를 대입
    return 0;
}