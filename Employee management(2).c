				#include <stdio.h>
				#include <stdlib.h>
				#include <string.h>
			
				#define MAX_EMPLOYEE_NUM 100 // �ִ� ��� ��
				#define MAX_PHONE_NUM_LEN 20 // �ڵ��� ��ȣ �ִ� ����
			
				// ��� ���� ����ü
				typedef struct {
			    int emp_num;
			    char position[20];
			    char name[20];
			    char phone_num[MAX_PHONE_NUM_LEN];
				}Employee;
				
				// ��ü ��� ������ �����ϴ� ����ü
				typedef struct {
				    Employee employees[MAX_EMPLOYEE_NUM];
				    int num_employees;
				}EmployeeDB;
			
				//�Լ� ������Ÿ��
				void add_employee(EmployeeDB* db);
				void print_employees(EmployeeDB* db);
				void sort_employees(EmployeeDB* db);
		
				int main() {
			    EmployeeDB db = {0}; // ��� ���� �����ͺ��̽� �ʱ�ȭ
			    int choice;
			    while (1) {
		        printf("1. ��� ���� �߰�\n");
		        printf("2. ��� ���� ���\n");
		        printf("3. ��� ���� ����\n");
		        printf("4. ����\n");
		        printf("5.���� : ");
		        scanf("%d", &choice);
		        switch (choice) {
		            case 1:
		                add_employee(&db);
		                break;
		            case 2:
		                print_employees(&db);
		                break;
		            case 3:
		                sort_employees(&db);
		                break;
		            case 4:
		                return 0;
		            default:
		                printf("�߸��� �����Դϴ�.\n");
		        			}
		   		 		}
					}	
		
					// ���ο� ��� ������ �߰��ϴ� �Լ�
					void add_employee(EmployeeDB* db) {
		    		// ��� ���� �Է�
		    		Employee new_employee;
		    		printf("��� ��ȣ : ");
		    		scanf("%d", &new_employee.emp_num);
		
		    		// ������ ��� ��ȣ�� �ִ��� Ȯ��
		    		for (int i = 0; i < db->num_employees; i++) {
		        	if (db->employees[i].emp_num == new_employee.emp_num) {
		            printf("�̹� ��ϵ� ��� ��ȣ�Դϴ�.\n");
		            return;
		        			}
		    		}	
		
		    		printf("���� : ");
		    		scanf("%s", new_employee.position);
		    		printf("�̸� : ");
		    		scanf("%s", new_employee.name);
		    		printf("�ڵ��� ��ȣ : ");
		    		scanf("%s", new_employee.phone_num);
		
		    		// ��� ���� �߰�
		    		db->employees[db->num_employees] = new_employee;
		    		db->num_employees++;
		    		printf("��� ������ �߰��Ǿ����ϴ�.\n");
					}
		
					// ��� ��� ������ ����ϴ� �Լ�
					void print_employees(EmployeeDB* db) {
		    		// ��� ���� ���
		    		printf("��� ��ȣ\t����\t�̸�\t�ڵ��� ��ȣ\n");
		    		for(int i = 0; i < db->num_employees; i++) {
		        	printf("%d\t%s\t%s\t%s\n",
		            db->employees[i].emp_num,
		            db->employees[i].position,
		            db->employees[i].name,
		            db->employees[i].phone_num
		            
		       	 				);
			    		}
					}
					void sort_employees(EmployeeDB* db) {
					//  ���� �� �� �� �� 
					for(int i=1; i < db->num_employees; i++) {
					Employee temp = db->employees[i];
					int j = i - 1;
					while (j >= 0 && db->employees[j].emp_num > temp.emp_num) {
					db->employees[j + 1] = db->employees[j];
					j--;
					}
					db->employees[j + 1] = temp;
					}
					}






