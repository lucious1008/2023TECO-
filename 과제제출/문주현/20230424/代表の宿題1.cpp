#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 20

typedef struct {
    int employee_number;
    char name[30];
    char department[30];
    char position[30];
    char phone_number[20];
} Employee;

void input_employee(Employee *employees, int *num_employees);
void sort_employees(Employee *employees, int num_employees);
void output_employees(Employee *employees, int num_employees);
void print_employees(Employee *employees);

int count = 0;

int main() {
    Employee employees[MAX_RECORDS];
    int num_employees = 0;

    input_employee(employees, &num_employees);
    sort_employees(employees, num_employees);
    output_employees(employees, num_employees);
    print_employees(employees);

    return 0;
}

void input_employee(Employee *employees, int *num_employees) {
    int employee_number;
    char name[30];
    char department[30];
    char position[30];
    char phone_number[20];

    while (*num_employees < MAX_RECORDS) {
        
		printf("SYAINBUN (The end -1) : ");
        scanf("%d", &employee_number);
        
        if (employee_number == -1) {
            break;
        }
        printf("NAME: ");
        scanf("%s", name);
        printf("department: ");
        scanf("%s", department);
        printf("position: ");
        scanf("%s", position);
        printf("phone_number: ");
        scanf("%s", phone_number);

        employees[*num_employees].employee_number = employee_number;
        strcpy(employees[*num_employees].name, name);
        strcpy(employees[*num_employees].department, department);
        strcpy(employees[*num_employees].position, position);
        strcpy(employees[*num_employees].phone_number, phone_number);
		count += 1;
        (*num_employees)++;
    }
}

void sort_employees(Employee *employees, int num_employees) {
    for (int i = 0; i < num_employees - 1; i++) {
        for (int j = i + 1; j < num_employees; j++) {
            if (employees[i].employee_number > employees[j].employee_number) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

void output_employees(Employee *employees, int num_employees) {
    FILE *fp = fopen("output.csv", "w");
//    fprintf(fp, "社員番号,名前,所属部署,職位,電話番号\n");
    fprintf(fp, "SYAINBUN,NAME,department,position,phone_number\n");

    for (int i = 0; i < num_employees; i++) {
        fprintf(fp, "%d,%s,%s,%s,%s\n", employees[i].employee_number,
                employees[i].name,
                employees[i].department,
                employees[i].position,
                employees[i].phone_number);
    }

    fclose(fp);
}

void print_employees(Employee *employees){
	for(int i=0; i < count; i++){
		printf("------------------------------------\nSYAINBUN :%d\nNAME :%s\ndepartment :%s\nposition :%s\nphone_number :%s\n"
		,employees[i].employee_number,
                employees[i].name,
                employees[i].department,
                employees[i].position,
                employees[i].phone_number);
	}
}