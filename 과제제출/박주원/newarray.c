#include<stdio.h>


int main(){
    char arr[6] = {"hello"};
    char* ptr;

    ptr = &arr[0]; //ptr은 arr의 첫번째 값의 주소를 가리켜라
 
 //연산자의 순서
    printf("%c\n", *ptr +1); //e가 나오는 것이 아닌 i가 나옴
    printf("%c\n", *(ptr +1)); //괄호로 순서를 우선적으로 바꿈 
    printf("%s\n\n",arr); //전체를 출력


    // int a[10];
    //잘못된 방식
    // int a1;
    // int a2;

    // a[0] = 1;
    // a[1] = 2;
    // a[2] = 3;
    // a[3] = 4;


    // int a[10];
    // int i;
    // //기본값 설정
    // for (i = 0; i < 10; i++)
    // {
    //     a[i] = i+1;
    // }
    // printf("size is : %d\n",sizeof(a)); // int형 10개 (4byte X 10=40)
    // //어레이 값 프린트
    //  for (i = 0; i < 10; i++)
    // {
    //     printf("\n a[%d] = %d", i ,a[i]); //(a의 X번째 인덱스는 :X, 횟수 ,a의 X번까지)
    // }

    //string 5개를 표현하기위해 6개를 선언해야함


    //null terminator
    char a[6] = {'j', 'u', 'w', 'o', 'n', '\0'};
    char b[6] = "juwon";
    char c[] = "juwon"; //사이즈를 알아서 측정해줌.

    printf("\na size %d\n",sizeof(a));
        printf("\nb size %d\n",sizeof(b));
            printf("\nc size %d\n",sizeof(c));
    printf("\n %s\n", c);
    return 0; 
}