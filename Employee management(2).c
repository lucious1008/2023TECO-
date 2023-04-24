				#include <stdio.h>
				#include <stdlib.h>
				#include <string.h>
			
				#define MAX_EMPLOYEE_NUM 100 // 최대 사원 수
				#define MAX_PHONE_NUM_LEN 20 // 핸드폰 번호 최대 길이
			
				// 사원 정보 구조체
				typedef struct {
			    int emp_num;
			    char position[20];
			    char name[20];
			    char phone_num[MAX_PHONE_NUM_LEN];
				}Employee;
				
				// 전체 사원 정보를 저장하는 구조체
				typedef struct {
				    Employee employees[MAX_EMPLOYEE_NUM];
				    int num_employees;
				}EmployeeDB;
			
				//함수 프로토타입
				void add_employee(EmployeeDB* db);
				void print_employees(EmployeeDB* db);
				void sort_employees(EmployeeDB* db);
		
				int main() {
			    EmployeeDB db = {0}; // 사원 정보 데이터베이스 초기화
			    int choice;
			    while (1) {
		        printf("1. 사원 정보 추가\n");
		        printf("2. 사원 정보 출력\n");
		        printf("3. 사원 정보 정렬\n");
		        printf("4. 종료\n");
		        printf("5.선택 : ");
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
		                printf("잘못된 선택입니다.\n");
		        			}
		   		 		}
					}	
		
					// 새로운 사원 정보를 추가하는 함수
					void add_employee(EmployeeDB* db) {
		    		// 사원 정보 입력
		    		Employee new_employee;
		    		printf("사원 번호 : ");
		    		scanf("%d", &new_employee.emp_num);
		
		    		// 동일한 사원 번호가 있는지 확인
		    		for (int i = 0; i < db->num_employees; i++) {
		        	if (db->employees[i].emp_num == new_employee.emp_num) {
		            printf("이미 등록된 사원 번호입니다.\n");
		            return;
		        			}
		    		}	
		
		    		printf("직위 : ");
		    		scanf("%s", new_employee.position);
		    		printf("이름 : ");
		    		scanf("%s", new_employee.name);
		    		printf("핸드폰 번호 : ");
		    		scanf("%s", new_employee.phone_num);
		
		    		// 사원 정보 추가
		    		db->employees[db->num_employees] = new_employee;
		    		db->num_employees++;
		    		printf("사원 정보가 추가되었습니다.\n");
					}
		
					// 모든 사원 정보를 출력하는 함수
					void print_employees(EmployeeDB* db) {
		    		// 사원 정보 출력
		    		printf("사원 번호\t직위\t이름\t핸드폰 번호\n");
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
					//  정렬 알 고 리 즘 
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






