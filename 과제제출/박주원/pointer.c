#include<stdio.h>

int main()
{
    int a, b;

    a= 123;
    int *a_ptr; 
    a_ptr = &a;
    printf("%d %d %p\n",a,*a_ptr,a_ptr);
    *a_ptr = 456; //*포인터를 통해 a의 메모리 주소를 직접가서 값을 변경함
    printf("%d %d %p\n",a,*a_ptr,a_ptr);

    b = *a_ptr;
    printf("%d\n",b);
    return 0;
}

//주소를 통해 ,변수를 통해 프로그래밍 할거냐 차이