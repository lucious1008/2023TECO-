#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 구조체 선언 예
struct structSample
{
	int a;
	short b;
	char c;
	int* pa;
	char* pstring;
};

// 구조체 선언 + 변수 선언 예
struct structSample2
{
	int a;
	short b;
	char c;
	int* pa;
	char* pstring;
}ss2;

// 구조체 선언 + 구조체의 별칭 선언(별칭은 struct 식별자가 필요 없어짐)
typedef struct structSample3
{
	int a;
	short b;
	char c;
	int* pa;
	char* pstring;
}structSample3;


#pragma region MagicianStruct
// 아이템 구조체
typedef struct item
{
	char* name;		// 이름
	int power;		// 위력
	int level;		// 착용레벨
	int durability;	// 내구도
}item;

// 게임의 마법사라는 직업의 상태를 나타내는 구조체의 예
typedef struct MagicianStruct
{
	char* name;		// 이름
	int level;		// 레벨
	int healthPoint;// 체력
	int mana;		// 마나
	item* items;	// 소유한 아이템목록
	int itemCnt;    // 소유한 아이템 개수
}Magician;
#pragma endregion

#pragma region MagicianFunc
// 아이템 추가 함수
// 인수 - 마법사상태주소  아이템명  위력  레벨  내구도
void addItemForMagician(Magician* Magician, const char* itemName, int power, int level, int durability)
{
	// 입력받은 값을 아이템 목록에 추가
	char* pTmpName = (char*)malloc(sizeof(char) * 99);
	strcpy_s(pTmpName, strlen(itemName) + 1, itemName);
	Magician->items[Magician->itemCnt].name = pTmpName;
	Magician->items[Magician->itemCnt].power = power;
	Magician->items[Magician->itemCnt].level = level;
	Magician->items[Magician->itemCnt].durability = durability;
	Magician->itemCnt++;
}

// 아이템 선택 삭제
// 인수 - 마법사상태주소  아이템명
void deleteItemForMagician(Magician* Magician, char* itemName)
{
	for (size_t i = 0; i < Magician->itemCnt; i++)
	{
		// 아이템명이 동일할 경우
		if (strcmp(itemName, Magician->items[i].name) == 0)
		{
			printf("아이템명 '%s'을(를) 삭제하였습니다\n", itemName);
			// 아이템을 삭제
			free(Magician->items[i].name);
			Magician->items[i].power = 0;
			Magician->items[i].level = 0;
			Magician->items[i].durability = 0;
			// 인벤토리 위치 조정
			for (size_t j = i + 1; j < Magician->itemCnt; j++)
			{
				Magician->items[j - 1] = Magician->items[j];
			}
			Magician->itemCnt--;
			Magician->items[Magician->itemCnt].name = NULL;
			Magician->items[Magician->itemCnt].power = 0;
			Magician->items[Magician->itemCnt].level = 0;
			Magician->items[Magician->itemCnt].durability = 0;
			return;
		}
	}
	printf("아이템명 '%s'은(는) 보유하고 있지 않습니다\n", itemName);
	return;
}

// 아이템 전체 삭제
// 인수 - 마법사상태주소
void deleteAllItemForMagician(Magician* Magician)
{
	for (size_t i = 0; i < Magician->itemCnt; i++)
	{
		// 아이템을 삭제
		printf("아이템명 '%s'을(를) 삭제하였습니다\n", Magician->items[i].name);
		free(Magician->items[i].name);
		Magician->items[i].power = 0;
		Magician->items[i].level = 0;
		Magician->items[i].durability = 0;
	}
	return;
}

// 캐릭터 삭제
// 인수 - 마법사상태주소
void deleteMagician(Magician* Magician)
{
	printf("'%s'을(를) 삭제합니다\n");
	// 이름 할당 해제
	free(Magician->name);
	// 아이템 할당 해제
	deleteAllItemForMagician(Magician);
	// 캐릭터 구조체 할당해제
	free(Magician);
}

// 캐릭터의 상태출력
// 인수 - 마법사상태주소
void printStatusMagician(Magician* Magician)
{
	printf("*****************************\n");
	printf("\n");
	printf("이름 : %s\n", Magician->name);
	printf("레벨 : Lv %d\n", Magician->level);
	printf("체력 : HP %d\n", Magician->healthPoint);
	printf("마나 : MP %d\n", Magician->mana);
	printf("\n");
	// 보유 아이템 출력
	printItems(Magician->items, Magician->itemCnt);
	printf("\n");
	printf("*****************************\n");
}

// 아이템 보유현황 출력
// 인수 - 아이템 주소    아이템 개수
void printItems(item* pItem, int itemCnt)
{
	printf("아이템 보유 개수 %d개\n", itemCnt);
	for (size_t i = 0; i < itemCnt; i++)
	{
		printf("---------------------\n");
		printf("\n");
		printf("아이템명 : %s\n", pItem[i].name);
		printf("공격력 : %d\n", pItem[i].power);
		printf("착용레벨 : %d\n", pItem[i].level);
		printf("내구도 : %d\n", pItem[i].durability);
		printf("\n");
		printf("---------------------\n");
	}
}
#pragma endregion




void pointerPrint2()
{
	// 구조체
	// 하나 이상의 변수를 묶어 새로운 자료형태를 나타내는 '사용자 정의' 자료형
	// 하나의 변수만으로는 객체를 표현하기에는 부족

	// 구조체 변수 선언 예
	struct structSample ss1;
	structSample3 ss3;

	// 구조체 포인터
	structSample3* p_ss3;

	// 구조체 활용 예
	ss2.a = 1;
	ss2.c = 'a';
	char tmpc[] = "char pointer in struct\n";
	int tmpd = 11;
	ss2.pstring = tmpc;
	ss2.pa = &tmpd;
	printf("ss2의 a: %d   c: %c  int: %d  string: %s\n",ss2.a, ss2.c, *ss2.pa, ss2.pstring);

	// 구조체 포인터 활용의 예
	// (*).
	structSample3 tmpss3;
	p_ss3 = &tmpss3;
	(*p_ss3).a = 2;
	(*p_ss3).c = 'a';
	(*p_ss3).pstring = tmpc;
	(*p_ss3).pa = &tmpd;
	printf("ss3의 a: %d   c: %c  int: %d  string: %s\n", (*p_ss3).a, (*p_ss3).c, *((*p_ss3).pa), (*p_ss3).pstring);



	// ->
	p_ss3->a = 3;
	p_ss3->c = 'b';
	char tmpc2[] = "struct pointer\n";
	p_ss3->pstring = tmpc2;
	int tmpd2 = 21;
	p_ss3->pa = &tmpd2;
	printf("ss3의 a: %d   c: %c  int: %d  string: %s\n", p_ss3->a, p_ss3->c, *(p_ss3->pa), p_ss3->pstring);


	// 게임의 마법사라는 직업의 상태를 나타내는 구조체의 예


	// 마법사 구조체 초기화
#pragma region Magician1
	// 마법사를 직업으로 가지는 유저의 상태를 저장하는 구조체를 동적할당 한다
	Magician* p_user1 = (Magician*)malloc(sizeof(Magician));
	// 마법사의 아이템 초기화
	p_user1->items = (item*)malloc(sizeof(item*) * 99);
	p_user1->itemCnt = 0;
#pragma endregion

	// 이름을 입력 받기
#pragma region Magician2
	char* tmpName = (char*)malloc(sizeof(char) * 99);
	printf("캐릭터의 이름을 입력해 주십시오. \n");
	scanf_s("%s", tmpName, 99);
	p_user1->name = tmpName;
	printf("\n당신의 캐릭터 이름은 %s 입니다 \n", p_user1->name);
#pragma endregion

	// 기본 스탯 설정(레벨 HP MANA)
#pragma region Magician3
	// 레벨 설정
	p_user1->level = 1;
	// HP설정
	p_user1->healthPoint = 100;
	// 마나설정
	p_user1->mana = 200;
#pragma endregion

	// 기본아이템 지급
#pragma region Magician4
	addItemForMagician(p_user1, "basicWand", 10, 1, 100);
	addItemForMagician(p_user1, "basicStaff", 30, 5, 100);
	addItemForMagician(p_user1, "basicShield", 10, 1, 100);
	addItemForMagician(p_user1, "basicCloth", 10, 1, 100);
	addItemForMagician(p_user1, "basicShoes", 10, 1, 100);
#pragma endregion
	
	// 캐릭터의 상태출력
#pragma region Magician5
	printf("당신의 캐릭터는 마법사이며 상태는 아래와 같습니다\n");
	printStatusMagician(p_user1);
#pragma endregion

	// 아이템,캐릭터 삭제
#pragma region Magician6
	// 아이템 삭제
	printf("삭제할 아이템을 입력하세요\n");
	char tmpDelItemName[99];
	scanf_s("%s", tmpDelItemName, 99);
	deleteItemForMagician(p_user1, tmpDelItemName);

	// 캐릭터의 상태출력
	printStatusMagician(p_user1);

	// 캐릭터 삭제
	deleteMagician(p_user1);
#pragma endregion

	// 과제 do while문을 활용하여 텍스트 입력 기반 게임을 작성하시오

	// 요구사항 1. 캐릭터는 이름 레벨 HP 상태이상의 상태가 존재한다
	// 요구사항 2. 몬스터는 이름 레벨 공격력 HP의 상태가 존재한다
	// 요구사항 3. 아이템은 이름 착용레벨 위력 내구도가 존재한다
	// 요구사항 4. 캐릭터의 공격력은 소유하고 있는 아이템의 위력의 총합이다
	// 요구사항 5. 게임에는 캐릭터 상태확인,몬스터 상태확인, 아이템확인, 사냥, 종료가 존재한다
	// 요구사항 6. 사냥은 몬스터를 공격하며 확률적으로 캐릭터는 몬스터에게 대미지를 입는다
	// 요구사항 7. 몬스터에게 대미지를 입을시 확률적으로 상태이상에 빠지며 상태이상은 Bit로 다룬다
	// 요구사항 8. 상태이상의 종류는 최소 4가지 이상이다
	// 요구사항 9. 상태이상의 종류는 최소 4가지 이상이다
	// 요구사항 10. 몬스터의 HP가 0이 되면 확률적으로 아이템을 얻는다
	// 요구사항 11. 몬스터가 죽으면 더 강한 몬스터가 등장한다
	// 요구사항 12. 캐릭터의 HP가 0이 되면 게임이 종료된다
	
	return;
}
