#include <stdio.h>
//제곱 연산

//함수를 따로 만들어서 main에 불러서 쓰기위해 만듦.
int compute_pow(int base, int exp) 
{
    int i, result;

    result = 1;
    for (i=0; i<exp; ++i)
    result *= base;

    return result;
}
int main()
{
    // 3의 4제곱
    // 3*3*3*3 = 81
    int base, exp, result; // 기본수과 제곱수, 횟수, 결과

   //두 개의 정수 값을 입력받을 때까지 반복
    while(scanf("%d %d", &base, &exp) == 2)
    {
    
    // // 결과 변수(result)를 초기값 1로 설정
    // result = 1; 

    // //i 변수는 0부터 제곱 수(exp)보다 작을 때까지 1씩 증가하며 반복
    // for(int i=0; i<exp; ++i)
    // {

    //     //result 변수에 현재의 base 값을 곱하여 결과를 업데이트
    //     result*= base; //result = result * base

    //     /*첫 번째 반복에서는 base 값 그대로 result에 저장되고, 
    //     다음 반복에서는 result에 base 값이 한 번 더 곱해지게 된다 */ 
    // }

    result = compute_pow(base,exp);
    //출력
    printf("Result = %d\n",result);

    }

    return 0;
}