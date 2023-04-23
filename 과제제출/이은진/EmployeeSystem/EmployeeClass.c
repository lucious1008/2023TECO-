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

void getInput(struct Employee *employees, int *numEmployees);
void sortEmployees(struct Employee *employees, int numEmployees);
void printEmployees(struct Employee *employees, int numEmployees);
void writeToCSV(struct Employee *employees, int numEmployees);

int main() {
    struct Employee employees[MAX_RECORDS];
    int numEmployees = 0;

    getInput(employees, &numEmployees);
    sortEmployees(employees, numEmployees);
    printEmployees(employees, numEmployees);
    writeToCSV(employees, numEmployees);

    return 0;
}

void getInput(struct Employee *employees, int *numEmployees) {
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
            if (employees[j].employeeNumber == newEmployeeNum) {
                printf("同一社員番号があります。社員番号を確認お願いします。\n");
                break;
            }
        }

        if (j == i) {
            employees[i].employeeNumber = newEmployeeNum;

            printf("名前: ");
            scanf("%s", employees[i].name);

            printf("所属部署: ");
            scanf("%s", employees[i].department);

            printf("職位: ");
            scanf("%s", employees[i].position);

            printf("電話番号: ");
            scanf("%s", employees[i].phone);

            i++;
            *numEmployees = i;
        }
    }
}

void sortEmployees(struct Employee *employees, int numEmployees) {
    int i, j;
    struct Employee temp;

    for (i = 0; i < numEmployees - 1; i++) {
        for (j = i + 1; j < numEmployees; j++) {
            if (employees[i].employeeNumber > employees[j].employeeNumber) {
                temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

void printEmployees(struct Employee *employees, int numEmployees) {
    int i;

    printf("\n社員番号, 名前, 所属部署, 職位, 電話番号\n");
    for (i = 0; i < numEmployees; i++) {
        printf("%d, %s, %s, %s, %s\n", employees[i].employeeNumber, employees[i].name,
               employees[i].department, employees[i].position, employees[i].phone);
    }
}

void writeToCSV(struct Employee *employees, int numEmployees) {
    FILE *fp = fopen("employees.csv", "w");

    if (fp == NULL) {
        printf("ファイルを開けませんでした。\n");
        exit(1);
    }

    fprintf(fp, "社員番号, 名前, 所属部署, 職位, 電話番号\n");
    for (int i = 0; i < numEmployees; i++) {
        fprintf(fp, "%d, %s, %s, %s, %s\n", employees[i].employeeNumber, employees[i].name,
                employees[i].department, employees[i].position, employees[i].phone);
    }

    fclose(fp);
}