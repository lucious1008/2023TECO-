#include <stdio.h>


int main() {
    int a = 0, b = 0, re = 0, result = 0; // 변수 4. 소수는 지원하지 않는다.
    char x; // 1바이트 문자

    do {
        printf("Enter a formula for calculation (EX: 2 + 3): ");
        if (scanf("%d %c %d", &a, &x, &b) != 3 || (x != '+' && x != '-' && x != '*' && x != '/')) {
            printf("Wrong calculation formula.\n"); // 5. 이상한 값을 입력할 경우 에러 메시지를 출력한다.
            while (getchar() != '\n') {}  // 입력 버퍼 비우기
            continue;
        }
        
        switch (x) {  // 2. 사칙연산
            case '+':
                result = a + b; // 더하기
                break;
            case '-':
                result = a - b; // 빼기
                break;
            case '*':
                result = a * b; // 곱하기
                break;
            case '/':
                if (b != 0) {
                    result = a / b; // 나누기
                }
                else {
                    printf("Division by 0 is not allowed.\n"); // 0으로 나눌 시 경고문
                    continue;
                }
                break;
            //default:
                //printf("Wrong calculation formula.\n"); 
                //continue;
        }
        
        printf("Result is %d\n", result);
        printf("Do you want to try again? (1. Yes  2. No): "); // 3. 콘솔창에서 사용자의 입력값을 계속 받는다.
        scanf("%d", &re);
        if (re != 1) {
            printf("Goodbye");
            break;
        }
    } while (re == 1);

    return 0;
}
