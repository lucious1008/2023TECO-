#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 20

struct Employee {
    int employeeNumber;
    char name[50];
    char department[50];
    char position[50];
    char phone[20];
};

void getInput(struct Employee *employees[], int *numEmployees);
void quickSortEmployees(struct Employee *employees[], int left, int right);
void printEmployees(struct Employee *employees[], int numEmployees);
void writeToCSV(struct Employee *employees[], int numEmployees);

int main() {
    struct Employee *employees[MAX_RECORDS];
    int numEmployees = 0;

    // employees 배열의 각 요소를 NULL로 초기화
    memset(employees, 0, sizeof(employees));

    while (1) {
        char option;
        printf("1. 社員情報の入力\n");
        printf("2. 社員情報の表示\n");
        printf("3. CSVファイルに書き込み\n");
        printf("4. 終了\n");
        printf("選択: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                getInput(employees, &numEmployees);
                quickSortEmployees(employees, 0, numEmployees - 1);
                break;

            case '2':
                // 정렬 후 직원 정보 출력
                printf("\nソート後の従業員情報:\n");
                printEmployees(employees, numEmployees);
                break;

            case '3':
                // CSV 파일 출력
                printf("\nCSVファイルに書き込みます。\n");
                writeToCSV(employees, numEmployees);
                break;

            case '4':
                // employees 배열의 각 요소 메모리 해제
                for (int i = 0; i < numEmployees; i++) {
                    free(employees[i]);
                }
                exit(0);

            default:
                printf("1から4の数値を入力してください。\n");
                break;
        }
    }

    return 0;

}

void getInput(struct Employee *employees[], int *numEmployees) {
    int numToAdd;
    printf("追加する社員の数を入力してください: ");
    scanf("%d", &numToAdd);

    for (int i = 0; i < numToAdd; i++) {
        struct Employee *emp = (struct Employee*) malloc(sizeof(struct Employee));

        printf("\n社員情報を入力してください:\n");

        printf("社員番号: ");
        scanf("%d", &(emp->employeeNumber));

        printf("氏名: ");
        scanf("%s", emp->name);

        printf("所属部署: ");
        scanf("%s", emp->department);

        printf("役職: ");
        scanf("%s", emp->position);

        printf("電話番号: ");
        scanf("%s", emp->phone);

        employees[*numEmployees + i] = emp;
    }

    *numEmployees += numToAdd;
}

void quickSortEmployees(struct Employee *employees[], int left, int right) {
    if (left < right) {
        int pivot = employees[right]->employeeNumber;
        int i = left - 1;
        for (struct Employee **j = employees + left; j <= employees + right - 1; j++) {
            if ((*j)->employeeNumber < pivot) {
                i++;
                struct Employee *temp = *(employees + i);
                *(employees + i) = *j;
                *j = temp;
            }
        }
        
        struct Employee *temp = *(employees + i + 1);
        *(employees + i + 1) = *(employees + right);
        *(employees + right) = temp;

        int partitionIndex = i + 1;
        quickSortEmployees(employees, left, partitionIndex - 1);
        quickSortEmployees(employees, partitionIndex + 1, right);
    }
}


void printEmployees(struct Employee *employees[], int numEmployees) {
    printf("\n社員情報:\n");
    printf("社員番号\t名前\t\t所属部署\t\t職位\t\t電話番号\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n", employees[i]->employeeNumber, employees[i]->name, employees[i]->department, employees[i]->position, employees[i]->phone);
    }
}

void writeToCSV(struct Employee *employees[], int numEmployees) {
    FILE *fp;
    char filename[50];

    printf("\nCSVファイル名: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("ファイルを開くことができませんでした。\n");
        return;
    }

    // CSV 파일 헤더
    fprintf(fp, "社員番号,名前,所属部署,職位,電話番号\n");

    // CSV 파일에 데이터 출력
    for (int i = 0; i < numEmployees; i++) {
        fprintf(fp, "%d,%s,%s,%s,%s\n", employees[i]->employeeNumber, employees[i]->name, employees[i]->department, employees[i]->position, employees[i]->phone);
    }

    fclose(fp);
}
