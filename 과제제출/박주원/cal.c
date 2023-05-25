#include <stdio.h>

double num1, num2;
char operator;

int main() {
    while (1) {
        printf("첫 번째 숫자를 입력하세요: ");
        scanf("%lf", &num1);

        printf("연산자를 입력하세요 (+, -, *, /): ");
        scanf(" %c", &operator);

        printf("두 번째 숫자를 입력하세요: ");
        scanf("%lf", &num2);

        double result;
        switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("0으로 나눌 수 없습니다.\n");
                continue;
            }
            result = num1 / num2;
            break;
        default:
            printf("잘못된 연산자입니다.\n");
            continue;
        }

        if ((int)result == result) {
            printf("계산 결과: %.0lf\n", result);
        }
        else {
            printf("계산 결과: %.3lf\n", result);
        }

        char choice;
        printf("계속해서 계산하시겠습니까? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n')
            break;
    }

    return 0;
}
