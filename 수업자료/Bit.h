#pragma once
#include <stdio.h>

void printSub(int a)
{
	if (a > 0)
	{
		for (size_t i = 1; i <= (1 << a); i++)
		{
			printf("{");
			for (size_t j = 0; j < a; j++)
			{
				if (i & (1 << j))
				{
					printf(" O ");
				}
				else
				{
					printf(" X ");
				}
			}
			printf("}  %d\n", i);
		}
	}
}

void printb(unsigned int v) {
	unsigned int mask = (int)1 << (sizeof(v) * 7);
	putchar('0');
	putchar('x');
	do putchar(mask & v ? '1' : '0');
	while (mask >>= 1);
	putchar('\n');
}

void printBit() 
{
	// 비트 데이터의 최소 단위 0 1
	// 1바이트 8비트
	// 1바이트 - char
	// 2바이트 - short, word
	// 4바이트 - int, float, long(32비트 환경)
	// 8바이트 - double, long long(32비트 환경)
	// 0000 0000 - 255
	// 0000 0000 0000 0000 - 65535

	char a;// -128 127
	short b;//-32768 32767
	int c; // -2147483648 2147483647
	long d; // long과 int는 운영체제마다 크기가 다르다
	long long e;
	float f;//10의 38승
	double g;//10 308승
	unsigned char a1;// 0 255
	unsigned short b2;//0 65535
	unsigned int c3; // 0 41...
	unsigned long d4;
	unsigned long long e5;

	// signed unsigned?
	// signed - 디폴트 부호가 있는거
	// unsigned - 부호가 없는거

	// char
	// 1000 0000 -
	// 0000 0000 +

	// 10의 보수
	// 1의 10의 보수는 9
	// 컴퓨터는 마이너스를 모른다(보수)

	// 비트연산은 수학의 집합과 같다

	// AND & - 교집합
	// 1 1 - 1
	// 1 0 - 0 
	// 0 1 - 0
	// 0 0 - 0

	// OR | - 합집합
	// 1 1 - 1
	// 1 0 - 1
	// 0 1 - 1
	// 0 0 - 0

	// NOT !
	// 1 - 0
	// 0 - 1

	// 배타排他연산자
	// XOR ^ -
	// 1 1 - 0
	// 1 0 - 1
	// 0 1 - 1
	// 0 0 - 0
	
	// SHIFT LEFT <<
	// 0010  → 00100 → 0100

	// SHIFT RIGHT >>
	// 0010  → 001 → 0001

	// i번째 비트가 ON인가?	if (bit & (1 << i))
	// char a    0010 0011
	//           0000 0010
	//           0000 0010 - bool true 

	// i번째 비트가 OFF인가? if (!(bit & (1 << i)))

	// i번째 비트를 ON한다	bit｜ = (1 << i)
	// 1010 0001
	// 0000 1000 or
	// 1010 1001 

	// i번째 비트를 OFF한다	bit &= ~(1 << i)
	// 1010 0001
	// 1111 1110 and
	// 1010 0000

	// 비트가 몇개 ON되어있는가?	_popcount(bit)  --c++
	// 1010 1001
	// for and

	// bit의 i번째 비트를 ON한 것	bit｜(1 << i)
	// bit의 i번째 비트를 OFF한 것	bit & ~(1 << i)

	// 비트연산하는 이유

	// 처리속도가 빠름 - 
	// 용량이 적어요
	// 0x8000 and true 아 열차문이 왼쪽이 열렸구나
	
	
	// 비트연산 문제
	// 1. 홀수를 판별하는 방법
	// 홀수 & 0x01 홀수

	// 2. 짝수를 판별하는 방법
	// !(짝수 & 0x01)

	// 3. 4로 나눈 수의 나머지 구하는 방법
	// 1111  0011 &
	// 숫자 and 0x03
	// 2의 제곱인 수에 적용

	// 4. a와 b의 값을 서로 바꾸는 방법
	// a = a ^ b;
	// b = a ^ b;
	// a = a ^ b;
	int aaa = 11;
	int bbb = 15;
	aaa = aaa ^ bbb;
	bbb = aaa ^ bbb;
	aaa = aaa ^ bbb;
	

	// 과제. N개의 집합의 부분집합을 모두 구하시오
	// 0 0 0 0
	// 1 << 0 1
	// 1 << 1 2
	// 1 << 2 4
	// 1 << 3 8
	// 1 << 4 16
	// 1 << N 2N

	return 0;
}