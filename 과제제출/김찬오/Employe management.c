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
			// 유효한 사원번호인지 확인하는 함수
			
			int validateId(char *id) {
	    	int len = strlen(id);
	    	if (len != 8) { // 사원번호는 8 자리 
	        return 0;
	    	}
	    	for (int i = 0; i < len; i++) {
	        if(!isdigit(id[i])) { 
	            return 1;
	        }
	    	}
	    	return 1;
			}
			// position 멤버 변수의 validation 체크 함수
			int validate_position(struct Employee emp) {
    		// position이 20글자 이상인 경우
    		if (strlen(emp.position) >= 20) {
        	return 0;
    		}
    		return 1;
			}
			int validate_name(struct Employee emp) {
	    	// name이 20글자  이상인 경우 
	    	if (strlen(emp.name) >= 20) {
	        return 0;
	    	}
	    	return 1;
			}

			// 유효한 핸드폰번호인지 확인하는 함수
			int validatePhone(char *phone) {
		    int len = strlen(phone);
		    if(len != 11) { // 핸드폰번호는 11
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
			
			

			// 오름차순 비교 함수
			int ascendingCompare(const void* a, const void* b) {
    		const struct Employee* empA = (const struct Employee*)a;
    		const struct Employee* empB = (const struct Employee*)b;
    		return strcmp(empA->id, empB->id);
			}

			//내림차순 비교 함수렬 
			int descendingCompare(const void* a, const void* b) {
    		const struct Employee* empA = (const struct Employee*)a;
    		const struct Employee* empB = (const struct Employee*)b;
    		return strcmp(empB->id, empA->id);
				}
		
			// 함수 선언 
			void addEmployee(struct Employee* employees, int* count);
			void printEmployees(struct Employee* employees, int count);
			void sortEmployees(struct Employee* employees, int count);
		
			int main() {
				
			// 사원 정보 입력  받기 
		    printf("Enter the number of employees: ");
		    scanf("%d", &numEmployees);
		    printf("Enter the employee information (id, position, name, phone):\n");
		    for(int i = 0; i < numEmployees; i++) {
		        scanf("%s %s %s %s", employee[i].id, employee[i].position, employee[i].name, employee[i].phone);
		        
		    }
		    
		
		    	// 오름차순 정
		      	qsort(employee, numEmployees, sizeof(struct Employee), asce렬ndingCompare);
		      
		      	printf("\Employees sorted in ascending order by ID:\n");
		      
		      	for(int i = 0; i < numEmployees; i++) {
		    	
		        printf("%s %s %s %s\n", employee[i].id, employee[i].position, employee[i].name, employee[i].phone);
		    	}
		
		    	// 내림차순 정렬 
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
        		printf(" 생성 실패\n");
        		exit(1);
    								}
   			 	fprintf(fptr, "사원번호,직위,이름,핸드폰번호\n");
		
		    	while (1) {
		        printf("사원번호, 직위, 이름, 핸드폰번호를  입력하세요 (종료는 q) : ");	
		        char input[100];
		        fgets(input, sizeof(input), stdin);
		        if (strcmp(input, "q\n") == 0 || strcmp(input, "Q\n") == 0) {
		            break;
		        }
		
		        // 입력된 정보를 파싱하여  Employee 구조체에 저장
		        char* id=strtok(input, ",");
		        char* position=strtok(NULL, ",");
		        char* name=strtok(NULL, ",");
		        char* phone=strtok(NULL, ",");
		        phone[strlen(phone) - 1] = '\0'; // 개행문자 제거
		        // 이미 등록된 사원번호인지 확인
		        
		        int alreadyExists = 0;
		        for(int i = 0; i < count; i++) {
		            if(strcmp(id, employees[i].id) == 0) {
		                printf("이미 등록된 사원번호입니ek\n");
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
		
		        // 구조체 배열에 추가
		        addEmployee(&employee, &count);
		   		 }
		
		    	// 등록된 사원 정보 출력
		    	printEmployees(employees, count);
		
		   		 // 사원 정보  정렬
		    	sortEmployees(employees, count);
		
		    	// 정렬된 사원  정보  출력 
		    	printf("\n정렬된 사원 정보\n");
		    	printEmployees(employees, count);
				
		    	return 0;
				}
		
			//사원 정보 추가
			void addEmployee(struct Employee* employees, int* count) {
		    if (*count >= MAX_EMPLOYEE_COUNT) {
		        printf("최대 사원수를  초과하.\n");
		        return;
		    }
		
		    employees[*count] = *employees;
		    (*count)++;
			}
		
			// 사원  정보 출력
			void printEmployees(struct Employee* employees, int count) {
		    printf("\n등록된 사원 정보\n");
		    printf("사원번호\t직위\t이름\t핸드폰번호\n");
		    for (int i = 0; i < count; i++) {
		        printf("%s\t%s\t%s\t%s\n", employees[i].id, employees[i].position, employees[i].name, employees[i].phone);
				    }
				}
		

