#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//�⺻ ����

// �������� �̸� ���뷹�� ���� �������� �����Ѵ�
typedef struct item
{
	char* name;
	int level;
	int power; 
	int durability;

}item;

//�����̻��� ������ �ּ� 4���� �̻��̴�
typedef struct state
{
	char state[4];
	
	

}state;

// ĳ���ʹ� �̸� ���� HP �����̻��� ���°� �����Ѵ�
typedef struct characterST
{
	char* name;
	int level;
	int healthPoint;
	int itemCnt;
	int damage;
	item* items;
	state* states;

}character;
// ���ʹ� �̸� ���� ���ݷ� HP�� ���°� �����Ѵ�
typedef struct monsterST
{
	char* name;
	int level;
	int damage;
	int healthPoint;

}monster;

	//���

void addItemForCharacter(character* character, const char* itemName, int itemPower, int itemLevel, int itemdurability)
{
	// �Է¹��� ���� ������ ��Ͽ� �߰�
	char* pTmpName = (char*)malloc(sizeof(char) * 99);
	strcpy_s(pTmpName, strlen(itemName) + 1, itemName);
	character->items[character->itemCnt].name = pTmpName;
	character->items[character->itemCnt].power = itemPower;
	character->items[character->itemCnt].level = itemLevel;
	character->items[character->itemCnt].durability = itemdurability;
	character->itemCnt++;
	character->damage = itemPower;
}


//���� 

//����� ���͸� �����ϸ� Ȯ�������� ĳ���ʹ� ���Ϳ��� ������� �Դ´�
void BattleForMonster(character* character, monster* monster) 
{
	int count=0;
	int hit;
	srand((unsigned int)time(NULL)); //seed������ ����ð� �ο�
	hit= rand()%10;

	if (monster->healthPoint > 0) 
	{
				printf("�ɸ����� ����\n");
				printf("%d��ŭ �������� ����ϴ�.\n", character->damage);
				monster->healthPoint -= character->damage;
				printf("������ ���� ü��%d\n", monster->healthPoint);
				if (monster->healthPoint <= 0) {
					printf("���Ͱ� �׾����ϴ�.\n\n");
					count=1;
					
				}
	}
	else if (hit< 3)
	{
				printf("%d��ŭ �������� �Ծ����ϴ�..\n", monster->damage);
				character->healthPoint -= monster->damage;
				printf("�ɸ����� ���� ü��%d\n", character->healthPoint);
	}
	
	
			
	
	
		
	
}



//�������

// �μ� - ĳ���ͻ����ּ�
void printStatuscharacter(character* character)
{
	printf("*****************************\n");
	printf("\n");
	printf("�̸� : %s\n", character->name);
	printf("���� : Lv %d\n", character->level);
	printf("ü�� : HP %d\n", character->healthPoint);
	printf("���ݷ� : Atk %d\n", character->damage);
	/*printf("���� : State %s\n", character->states);*/
	printf("\n");
	printf("\n");
	printf("*****************************\n");
}

// �μ� - ���ͻ����ּ�
void printStatuscharacter(monster* monster)
{
	printf("*****************************\n");
	printf("\n");
	printf("���� : Lv %d\n", monster->level);
	printf("ü�� : HP %d\n", monster->healthPoint);
	printf("���ݷ� : Atk %d\n", monster->damage);
	printf("\n");
	printf("\n");
	printf("*****************************\n");
}




int main() {

	character* user = (character*)malloc(sizeof(character));
	monster* mons = (monster*)malloc(sizeof(monster));
	user->items = (item*)malloc(sizeof(item*) * 99);
	user->itemCnt = 0;

	char* tmpName = (char*)malloc(sizeof(char) * 99);
	printf("ĳ������ �̸��� �Է��� �ֽʽÿ�. \n");
	scanf_s("%s", tmpName, 99);
	user->name = tmpName;
	printf("\n����� ĳ���� �̸��� %s �Դϴ� \n", user->name);
	// ��������
	user->level = 1;
	// HP����
	user->healthPoint = 50;
	//���� ����
	mons->level = 10;
	mons->healthPoint = 40;
	mons->damage = 5;
	//�ʱ� ������ ����
	addItemForCharacter(user, "BasicSword", 10, 1, 10);


	printf("\n����� ĳ���Ϳ��� �⺻���� %s �� ���޵Ǿ����ϴ� \n", user->items->name);


	do {

		int hotkey;
		printf("\n�޴��� �������ּ���.\n[1]�� �ɸ��ͻ��� \n[2]�� ���ͻ��� \n[3]�� ������Ȯ�� \n[4]�� ��� \n[5]�� ���� \n");
		scanf_s("%d", &hotkey);
		
		switch (hotkey) {
		//���ӿ��� ĳ���� ����Ȯ��,���� ����Ȯ��, ������Ȯ��, ���, ���ᰡ
			//ĳ���� ����Ȯ��
		case 1:

			printf("����� ĳ������ ���´� �Ʒ��� �����ϴ�\n");
			printStatuscharacter(user);
			break;
			
			//���� ����Ȯ��
		case 2:
			
			printStatuscharacter(mons);
			break;
			//������Ȯ��
		case 3:
			//�̱���
			
			break;
			
		case 4:
			//���
			BattleForMonster(user,mons);
			
			break;
		case 5:
			//����
			user->healthPoint = 0;
			break;
		default:
			printf("�߸��Է��Ͽ����ϴ�.");
		}

				

		
	} while (user->healthPoint > 0);
	{
		free(user);

		printf("GAMEOVER");
	}


	return 0;
}
