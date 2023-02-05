#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printCharArr(char** p_CharArr, int cnt) 
{
	for (int i = 0; i < cnt; i++)
	{
		printf("%s\n", p_CharArr[i]);
	}
}


int* pointerPrint()
{
	// 가상메모리(Virtual Memory)란?
	// OS가 메모리를 관리/제어하는 기법
	// 응용 프로그램이 물리적 메모리를 직접 사용하는 것이 아닌 OS의 제어를 거치는 메모리를 사용한다
	/*int a = 10;
	int* pa = &a;
	printf("%d",a);*/

	// 포인터란?
	// 변수의 메모리 주소값을 저장하는 "변수"

	// 포인터 식별자 *
	// 변수명의 왼쪽에 붙는다(Left Value)
	// 변수가 포인터 변수임을 나타내는 "식별자"
	// 사용 예 ) int* p_a;      int *p_a;
	

	// 포인터 연산자 *
	// 포인터 변수에 왼쪽에 붙어 사용한다(Right Value)
	// 포인터 변수가 가진 주소값에 존재하는 값을 참조하는 "연산자"
	// 사용 예 ) printf("%d", *p_a);    *p_a = 10;
	

	// 참조 연산자 &
	// 포인터 변수에 왼쪽에 붙어 사용한다(Right Value)
	// 포인터 변수가 가진 주소값에 존재하는 값을 참조하는 "연산자"
	// 사용 예 ) printf("%d", *p_a);    *p_a = 10;
	int intA = 10;
	int* p_intA = &intA;
	*p_intA = 11;
	printf("intA의 주소 0x%08x\n", &intA);
	printf("intA의 값 %d\n", intA);
	printf("p_intA의 주소 0x%08x\n", &p_intA);
	printf("p_intA의 값 0x%08x\n", p_intA);



	// 배열의 의미
	// 배열 변수의 값은 배열 시작 위치의 주소
	int arrA[4] = { 1, 2, 3, 4 };

	for (int i = 0; i < sizeof(arrA) / sizeof(int); i++)
	{
		printf("%d ", arrA[i]);
	}
	printf("\n");

	// arrA배열변수의 2번째 항목을 바꾼다
	int* p_arrA = arrA;
	arrA[1] = 99;
	for (int i = 0; i < sizeof(arrA) / sizeof(int); i++)
	{
		printf("%d ", arrA[i]);
	}
	printf("\n");

	// p_arrA가 가진 배열주소의 2번째 항목을 바꾼다
	*(p_arrA + 1) = 55;
	for (int i = 0; i < sizeof(arrA) / sizeof(int); i++)
	{
		printf("%d ", arrA[i]);
	}
	printf("\n");

	// 배열의 첫번째 항목이 0부터인 이유는?

	// 문자열은 char의 배열이다
	char p_stringA[16] = "string is Array";
	printf("p_stringA의 값 %s\n",p_stringA);
	printf("p_stringA의 글자길이 %d\n", strlen(p_stringA));

	char* p_stringB = "string is Array";
	printf("p_stringB의 값 %s\n", p_stringB);
	printf("p_stringB의 글자길이 %d\n", strlen(p_stringB));

	*(p_stringA + 10) = 'a';
	printf("p_stringA의 값 %s\n", p_stringA);
	//*(p_stringB + 10) = 'a';
	printf("p_stringB의 값 %s\n", p_stringB);

	// 이중포인터는 배열의 배열일 뿐
	char* p_charArr[] = { "double pointer", "is just", "Array of Array" };
	char** pp_charArr = p_charArr;
	printCharArr(pp_charArr,3);

	// 왜 문자열 배열이 아닌 문자열 포인터 배열(이중포인터)인가?
	char charArrOrigin[][20] = { "double pointer","is just", "Array of Array" };

	// Shallow Copy VS Deep Copy에 관해 생각해보기
	

	// 동적할당
	// 왜 동적할당을 하는가?

	// 아래의 로직이 동작하지 않는 이유는?
	/*int stNum;
	printf("학생수를 입력해 주세요. ");
	scanf("%d", &stNum);
	int arScore[stNum];*/

	// Stack VS Heap

	
	// malloc (size)
	//{
	//	// 메모리 할당
	//	int* allocA = malloc(sizeof(int));
	//	// 메모리 해제
	//	free(allocA);
	//}
	// calloc (cnt, size)
	//{
	//	// 메모리 할당
	//	int* allocB = calloc(10,sizeof(int));
	//	// 메모리 해제
	//	free(allocB);
	//}
	// realloc (ptr, size)
	//{
	//	char* allocC = (char*)malloc(4);

	//	// allocC 백업
	//	char* backupBuffer = allocC;

	//	// realloc 실패시
	//	if (NULL == (allocC = (char*)realloc(allocC, 8)))
	//	{
	//		// 백업으로 메모리 해제할 시
	//		free(backupBuffer);
	//		fprintf(stderr, "Memory allocation is failed");

	//		// 백업으로 복구 할 시
	//		allocC = backupBuffer;
	//	}
	//}
	// new? 에 대해서 생각해보기

	int* arrB = malloc(sizeof(int));
	*arrB = 10;
	//free(arrB);

	// int retA = 10;
	// return &retA;
	return arrB;
	// 과제 1. int포인터 변수와 배열의 갯수를 인수로 받아 해당 포인터의 내용을 복사하는 함수를 작성하시오

	// 과제 2. char포인터 변수 A의 값 "String is difficult" B의 값 "string is not inefficient"
	//         같은 순번의 문자가 같은 경우 출력하는 함수를 작성하시오

	// 과제 3. 리터럴이 아닌 문자열을 가지는 문자열 배열 포인터를 작성하고 2번째 문자열의 2번째 문자를 바꾸는 함수를 작성하시오
	//         문자열 배열 내용 : "pointer" "is nothing" "very easy man"

	// 과제 4. 메모리를 할당할 때는 할당할 사이즈를 지정해야 하지만 해제할 때는 메모리 주소 변수만 있으면 되는 이유를 서술하시오
}
	
