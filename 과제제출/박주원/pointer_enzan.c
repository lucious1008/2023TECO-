int main()
{
    int arr[5] = {100, 200, 300, 400, 500};
    int* ptr1, *ptr2, *ptr3;

    //배열 자체가 포인터와 비슷하다. 
    ptr1 = arr; 

    //일반 변수인 경우는 아래와 같이 선언해야한다.
    int i; 
    ptr1 = &i;

    printf("%p %d %p\n",ptr1, *ptr1, &ptr1);
    // * : 역참조 가능 : 주소를 통해 값에 접근한다.
    // & : 포인터 변수의 주소도 가져올수있음

    ptr2 = &arr[2]; // Adress- of operator &

    printf("%p %d %p \n",ptr2,*ptr2,&ptr2);

    ptr3 = ptr1 + 4 ; //Adding an integer from a pointer


    //Differencing 차이 측정

    printf("%td\n", ptr3 -ptr1); //%td : 포인터의 차이값을 출력 할 떄 사용

    ptr3 = ptr3 - 4; //subtracing an integer from a pointer    


    ptr1++;
    ptr1--;
    --ptr1;
    ++ptr1;

    if (ptr1 == ptr3)
        printf("Same\n");
    else
        printf("different\n");

        //비교를 할 수는 있으나 실수로 인식되어 warning 안내문이 나온다.
        double d = 3.14;
        double *ptr_d =&d; //double의 포인터와 int의 포인터의 메모리가 차지하는 사이즈가 같다. 
        
        if(ptr1 == ptr_d) 
            printf("same\n");
        else
            printf("Different\n");

        //위와 같은 warning 에러 해결 방법 int형으로 묶어준다.
        if(ptr1 == (int*)ptr_d)
            printf("same\n");
        else
            printf("Different\n");



        return 0;
}