#include<stdio.h>

int main() {
    int a = 0, b = 0, re = 0, result = 0; //변수 4.소수는 지원하지 않는다.
    char x; // 1byte 문자

    do {
        printf("Enter a formula for calculation (EX : 2 + 3): ");
        scanf("%d %c %d", &a,&x,&b); //1. 단항식만 지원한다.
        switch (x) {  //2.사칙연산
            case '+':
                result = a + b; //더하기
                break;
            case '-':
                result = a - b; //빼기
                break;
            case '*':
                result = a * b; //곱하기
                break;
            case '/':
                if(b != 0){
                    result = a / b; //나누기
                }
                else{
                    printf("Division by 0 is not allowed.\n"); // 0으로 나눌시 경고문
                    continue;
                }
                break;
            default:
                printf("Wrong calculation formula.\n"); //5. 이상한 값을 입력할 경우는 에러 메세지를 띄운다.
                continue;
        }
        printf("Result is %d\n", result);
        printf("Do you want to try again? (1.Yes  2.No): "); // 3.콘솔창은 유저의 입력값을 계속 받는다.
        scanf("%d", &re);
        if (re != 1) {
            printf("Goodbye");
            break;
        }
    } while (re == 1);
    
    return 0;
}
