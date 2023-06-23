#include<stdio.h>

#define NUM_DAYS 365 //array의 사이즈를 측정해주는 역할로 자주 쓰이는 매크로

int main()
{
    char my_chars[] = "Hello, World"; // 변수 my_chars에 NULL 값을 포함한 배열의 크기(인덱스)를 저장

    int daily_temperature[NUM_DAYS]; 
    double stock_prices_history[NUM_DAYS];

    printf("%zd\n",sizeof(stock_prices_history));
    printf("%zd\n",sizeof(double)*NUM_DAYS);// 더블의 사이즈 * num_days만큼 사이즈가 할당
    printf("%zd\n",sizeof(stock_prices_history[0])); //8byte : double 사이즈

    //비효율적 방법
    // int my_number1 = 1;
    // int my_number2 = 3;
    // int my_number3 = 4;
    // int my_number4 = 5;
    // int my_number5 = 1034;

    int my_numbers[5];

    my_numbers[0] = 1; //첫공간의 주소 , offsets
    my_numbers[1] = 3;
    my_numbers[2] = 4;
    my_numbers[3] = 2;
    my_numbers[4] = 1024;

    // scanf("%d",&my_numbers[0]); //주소로 바꿔서 넘겨줘야함, [0]의 우선순위가 높기 때문에 괄호를 따로 하지않음.
    scanf("%d",my_numbers); //변수에는 &를 붙여야함, 그러나 배열의 경우 my_number의 첫번째 메모리이기때문에 기재하지않아도 됨.

    printf("%d\n",my_numbers[0]);
    printf("%d\n",my_numbers[1]);
    printf("%d\n",my_numbers[2]);
    printf("%d\n",my_numbers[3]);
    printf("%d\n",my_numbers[4]);


    my_numbers[5] = 123; //이는 6번째 공간, 위의 int my_number을 선언 할 때 [5]로 크기를 지정했기 때문의 인덱스 내부의 숫자는 "0,1,2,3,4"

}