			#include <stdio.h>
			#include <stdlib.h>
			#include <string.h>
		
			#define MAX_EMPLOYEE_COUNT 100
		
			struct Employee {
		    char id[10];
		    char position[20];
		    char name[20];
		    char phone[20];
							} Employee;
			// ��ȿ�� �����ȣ���� Ȯ���ϴ� �Լ�
			
			int validateId(char *id) {
	    	int len = strlen(id);
	    	if (len != 8) { // �����ȣ�� 8 �ڸ� 
	        return 0;
	    	}
	    	for (int i = 0; i < len; i++) {
	        if(!isdigit(id[i])) { 
	            return 1;
	        }
	    	}
	    	return 1;
			}
			// position ��� ������ validation üũ �Լ�
			int validate_position(struct Employee emp) {
    		// position�� 20���� �̻��� ���
    		if (strlen(emp.position) >= 20) {
        	return 0;
    		}
    		return 1;
			}
			int validate_name(struct Employee emp) {
	    	// name�� 20����  �̻��� ��� 
	    	if (strlen(emp.name) >= 20) {
	        return 0;
	    	}
	    	return 1;
			}

			// ��ȿ�� �ڵ�����ȣ���� Ȯ���ϴ� �Լ�
			int validatePhone(char *phone) {
		    int len = strlen(phone);
		    if(len != 11) { // �ڵ�����ȣ�� 11
		        return 0;
		    }
		    for(int i = 0; i < len; i++) {
		        if(!isdigit(phone[i])) { 
		            return 0;
		            
		        }
		    }
		    return 1;
			}
			
			int numEmployees;
			
			

			// �������� �� �Լ�
			int ascendingCompare(const void* a, const void* b) {
    		const struct Employee* empA = (const struct Employee*)a;
    		const struct Employee* empB = (const struct Employee*)b;
    		return strcmp(empA->id, empB->id);
			}

			//�������� �� �Լ��� 
			int descendingCompare(const void* a, const void* b) {
    		const struct Employee* empA = (const struct Employee*)a;
    		const struct Employee* empB = (const struct Employee*)b;
    		return strcmp(empB->id, empA->id);
				}
		
			// �Լ� ���� 
			void addEmployee(struct Employee* employees, int* count);
			void printEmployees(struct Employee* employees, int count);
			void sortEmployees(struct Employee* employees, int count);
		
			int main() {
				
			// ��� ���� �Է�  �ޱ� 
		    printf("Enter the number of employees: ");
		    scanf("%d", &numEmployees);
		    printf("Enter the employee information (id, position, name, phone):\n");
		    for(int i = 0; i < numEmployees; i++) {
		        scanf("%s %s %s %s", employee[i].id, employee[i].position, employee[i].name, employee[i].phone);
		        
		    }
		    
		
		    	// �������� ��
		      	qsort(employee, numEmployees, sizeof(struct Employee), asce��ndingCompare);
		      
		      	printf("\Employees sorted in ascending order by ID:\n");
		      
		      	for(int i = 0; i < numEmployees; i++) {
		    	
		        printf("%s %s %s %s\n", employee[i].id, employee[i].position, employee[i].name, employee[i].phone);
		    	}
		
		    	// �������� ���� 
		   	 	qsort(employee, numEmployees, sizeof(struct Employee), descendingCompare);
		    	printf("\n Employees sorted in descending order by ID:\n");
		    	for (int i = 0; i < numEmployees; i++) {
		    	printf("%s %s %s %s\n", employee[i].id, employee[i].position,employee[i].name, employee[i].phone);
		    	printf("%s %s %s %ss\n", employee[i].id employee[i].position,employee[i])
					}
					printf("\n employees sorted in descending order by ID : \n");
					
		    	struct Employee employees[MAX_EMPLOYEE_COUNT];
		    	
		    	int count=0;
		    	int count=0;
		    	FILE *fptr;
    			fptr = fopen("employees.csv", "w");
    			if(fptr == NULL) {
        		printf(" ���� ����\n");
        		exit(1);
    								}
   			 	fprintf(fptr, "�����ȣ,����,�̸�,�ڵ�����ȣ\n");
		
		    	while (1) {
		        printf("�����ȣ, ����, �̸�, �ڵ�����ȣ��  �Է��ϼ��� (����� q) : ");	
		        char input[100];
		        fgets(input, sizeof(input), stdin);
		        if (strcmp(input, "q\n") == 0 || strcmp(input, "Q\n") == 0) {
		            break;
		        }
		
		        // �Էµ� ������ �Ľ��Ͽ�  Employee ����ü�� ����
		        char* id=strtok(input, ",");
		        char* position=strtok(NULL, ",");
		        char* name=strtok(NULL, ",");
		        char* phone=strtok(NULL, ",");
		        phone[strlen(phone) - 1] = '\0'; // ���๮�� ����
		        // �̹� ��ϵ� �����ȣ���� Ȯ��
		        
		        int alreadyExists = 0;
		        for(int i = 0; i < count; i++) {
		            if(strcmp(id, employees[i].id) == 0) {
		                printf("�̹� ��ϵ� �����ȣ�Դ�ek\n");
		                alreadyExists = 1;
		                break;
		            }
		        }
		        if (alreadyExists) {
		        	
		            continue;
		        }
		
		        struct Employee employee;
		        
		        strcpy(employee.id, id);
		        strcpy(employee.position, position);
		        strcpy(employee.name,  name);
		        strcpy(employee.phone, phone);
		
		        // ����ü �迭�� �߰�
		        addEmployee(&employee, &count);
		   		 }
		
		    	// ��ϵ� ��� ���� ���
		    	printEmployees(employees, count);
		
		   		 // ��� ����  ����
		    	sortEmployees(employees, count);
		
		    	// ���ĵ� ���  ����  ��� 
		    	printf("\n���ĵ� ��� ����\n");
		    	printEmployees(employees, count);
				
		    	return 0;
				}
		
			//��� ���� �߰�
			void addEmployee(struct Employee* employees, int* count) {
		    if (*count >= MAX_EMPLOYEE_COUNT) {
		        printf("�ִ� �������  �ʰ���.\n");
		        return;
		    }
		
		    employees[*count] = *employees;
		    (*count)++;
			}
		
			// ���  ���� ���
			void printEmployees(struct Employee* employees, int count) {
		    printf("\n��ϵ� ��� ����\n");
		    printf("�����ȣ\t����\t�̸�\t�ڵ�����ȣ\n");
		    for (int i = 0; i < count; i++) {
		        printf("%s\t%s\t%s\t%s\n", employees[i].id, employees[i].position, employees[i].name, employees[i].phone);
				    }
				}
		

