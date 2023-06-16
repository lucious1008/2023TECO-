#include<stdio.h>


void swap (int* u,int* v)
{
    printf("%p %p\n",u,v);

    int temp = *u;
    *u = *v;
    *v = temp;
}
int main(){
    int a = 123;
    int b = 456;

    printf("%p %p\n",&a,&b);
    //swap a,b의 결과 값을 서로 바꿔서 출력
    swap(&a,&b);
    printf("%d %d",a,b);

    return 0;
}