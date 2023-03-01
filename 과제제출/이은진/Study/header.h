#include <stdio.h>

struct character
{

    int lv;   // 레벨
    int exp;  // 경험치
    int hp;   // HP
    int mp;   // 마나
    int str;  // 힘
    int dex;  // 민첩
    int in;   // 지력
    int skil; //스킬포인트
    int gold; // 소지금 
    int dmg;  // 총 데미지
    int only; // 장착가능 무기갯수 
    int power; // 무기 데미지 
};

struct item 
{

    int power; // 데미지
    int str; // 힘 
    int dex;  // 민첩 
    int in; // 지력 
    int itemcount; // 무기수 
};

struct monster
{
    int name; // 몬스터이름
    int hp;   // HP
    int mp;   // MP
    int dmg;  // 공격력
    int lv;   // 레벨
    int exp;  // 경험치
};

int yes(char a)
{
    int i;
    if (a == 'y' || a == 'Y' || a == 'n' || a == 'N')
    {
        switch (a)
        {
        case 'y':
            i = 1;
            break;
        case 'Y':
            i = 1;
            break;
        case '0':
            i = 1;
            break;
        case 'N':
            i = 0;
            break;
        }
    }
    return i;
}

void lvup(struct character *ch)
{
    while (ch->exp >= 100)
    { //레벨업
        printf("축하드립니다. 레벨업을 하셨습니다 ! \n");
        ++ch->lv;
        ch->exp = ch->exp - 100;
        ch->str = ch->str + 5;
        ch->dex = ch->dex + 5;
        ch->in = ch->in + 5;
    }
}