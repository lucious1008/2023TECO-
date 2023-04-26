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

void getInput(struct Employee **employees, int *numEmployees);
void quickSortEmployees(struct Employee **employees, int left, int right);
void printEmployees(struct Employee **employees, int numEmployees);
void writeToCSV(struct Employee **employees, int numEmployees);

int main() {
    struct Employee *employees[MAX_RECORDS];
    int numEmployees = 0;

    // employees 배열의 각 요소를 NULL로 초기화
    memset(employees, 0, sizeof(employees));

    getInput(employees, &numEmployees);
    quickSortEmployees(employees, 0, numEmployees - 1);

    // 정렬 후 직원 정보 출력
    printf("\nソート後の従業員情報:\n");
    printEmployees(employees, numEmployees);

    // CSV 파일 출력
    printf("\nCSVファイルに書き込みます。\n");
    writeToCSV(employees, numEmployees);

    // employees 배열의 각 요소 메모리 해제
    for (int i = 0; i < numEmployees; i++) {
        free(employees[i]);
    }

    return 0;

}


void getInput(struct Employee **employees, int *numEmployees) {
    int newEmployeeNum;
    int i = *numEmployees;

    while (i < MAX_RECORDS) {
        printf("\n従業員情報の入力（または終了するには -1）\n");
        printf("社員番号: ");
        scanf("%d", &newEmployeeNum);

        if (newEmployeeNum == -1) {
            break;
        }

        int j;
        for (j = 0; j < i; j++) {
            if (employees[j]->employeeNumber == newEmployeeNum) {
                printf("同一社員番号があります。社員番号を確認お願いします。\n");
                break;
            }
        }

        if (j == i) {
            // 새로운 Employee 구조체 동적 할당
            struct Employee *newEmployee = malloc(sizeof(struct Employee));

            // 입력 받은 데이터로 초기화
            newEmployee->employeeNumber = newEmployeeNum;

            printf("名前: ");
            scanf("%s", newEmployee->name);

            printf("所属部署: ");
            scanf("%s", newEmployee->department);

            printf("職位: ");
            scanf("%s", newEmployee->position);

            printf("電話番号: ");
            scanf("%s", newEmployee->phone);

            // employees 배열의 i번째 요소를 새로운 Employee 구조체의 포인터로 설정
            employees[i] = newEmployee;

            i++;
            *numEmployees = i;
        }
    }
}


void quickSortEmployees(struct Employee **employees, int left, int right) {
    if (left < right) {
        int pivot = employees[right]->employeeNumber;
        int i = left - 1;
        for (int j = left; j <= right - 1; j++) {
            if (employees[j]->employeeNumber < pivot) {
                i++;
                struct Employee *temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
        struct Employee *temp = employees[i + 1];
        employees[i + 1] = employees[right];
        employees[right] = temp;

        int partitionIndex = i + 1;
        quickSortEmployees(employees, left, partitionIndex - 1);
        quickSortEmployees(employees, partitionIndex + 1, right);
    }
}

void printEmployees(struct Employee **employees, int numEmployees) {
    printf("\n従業員情報:\n");
    printf("社員番号\t名前\t\t所属部署\t\t職位\t\t電話番号\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n", employees[i]->employeeNumber, employees[i]->name, employees[i]->department, employees[i]->position, employees[i]->phone);
    }
}


void writeToCSV(struct Employee **employees, int numEmployees) {
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