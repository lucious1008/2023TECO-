
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
#define CLR system("cls")
void lvup(struct character *ch);
int war(struct monster *m3, struct character *ch);
int yes(char a);
int main()
{
    struct monster m1, m2, m3;
    struct item item1, item2, item3, item4;
    item1.itemcount = 0;
    item2.itemcount = 0;
    item3.itemcount = 0;
    item4.itemcount = 0;
    char a, name[10];
    int first, i, b;
    printf("1. 시작\n");
    printf("2. 불러오기\n"); // 구현 x

    scanf("%d", &first);
    CLR;
    switch (first)
    {
    case 1:
        printf("1. 시작\n");
        printf("이름을 입력하세요.\n");
        scanf("%s", name);
        printf("입력하신 이름은 %s입니다.\n", name);

        CLR;
        printf("%s님의 모험이 준비중입니다.\n", name);
        printf("잠시 기다려주세요.");
        printf("모험이 시작되면 무기를 얻어야합니다.\n 상점참고.");

        CLR;
        /*초기 스테이터스 초기화*/
        struct character ch = {1, 0, 100, 10, 5, 5, 5, 3, 200, 0, 1, 0};

        while (1)
        {
            int ingame = 0;
            CLR;
            printf("소지골드: %d\n", ch.gold);
            printf("1. 상태창\n2. 스킬창\n3. 인벤토리\n4. 장비\n5. 상점\n6. 사냥터\n7. 종료\n");

            scanf("%d", &ingame);
            if (ingame == 1)
            { //스텟창
                CLR;
                /*총데미지*/ //무기에따른 데미지, 스텟에따른 데미지 미구현
                ch.dmg = (ch.str + ch.dex + ch.in) * ch.dmg;
                printf("상태창\n");
                printf("%s님의 LV은 %d입니다.\n", name, ch.lv);
                printf("%s님의 총데미지는 %d입니다.\n", name, ch.dmg);
                printf("%s님의 exp는 %d입니다.\n", name, ch.exp);
                printf("%s님의 HP는 %d입니다.\n", name, ch.hp);
                printf("%s님의 MP는 %d입니다.\n", name, ch.mp);
                printf("%s님의 힘은 %d입니다.\n", name, ch.str);
                printf("%s님의 지력은 %d입니다.\n", name, ch.in);
                printf("%s님의 민첩은 %d입니다.\n", name, ch.dex);
            }
            else if (ingame == 2)
            { //스킬창
                CLR;
                printf("스킬창\n");
            }
            else if (ingame == 3)
            { //인벤
                CLR;
                printf("인벤\n");
            }
            else if (ingame == 4)
            { //장비

                int e;
                CLR;
                printf("장비\n");

                if (item1.itemcount >= 1)
                {
                    printf("1. 쇠도끼 %d개\n", item1.itemcount);
                }
                if (item2.itemcount >= 1)
                {
                    printf("2.  표창 %d개\n", item2.itemcount);
                }

                if (ch.only == 1)
                {
                    printf("어떤것을 장착하시겠습니까?\n");
                    scanf("%d", &e);
                    switch (e)
                    {
                    case 1:
                        ch.dex += item1.dex;
                        ch.str += item1.str;
                        ch.power += item1.power;
                        ch.in += item1.in;
                        item1.itemcount--;
                        ch.only--;
                        break;
                    }
                }
            }
            else if (ingame == 5)
            { //상점
                while (1)
                {
                    CLR;
                    printf("상점\n");
                    printf("구입가능한 무기\n");
                    printf("1. 장미칼 lv.1 100골드 \n");
                    printf("2. 고목나무지팡이 lv.1 100골드 \n");
                    printf("3. 한손도끼 lv.1 100골드 \n");
                    printf("4. 커터문 lv.99 10000골드 \n");
                    printf("5. 상점나가기 \n");
                    scanf("%d", &ingame);
                    switch (ingame)
                    {
                    case 1:
                        if (ch.gold >= 100)
                        {
                            item1.power = 5;
                            item1.str = 5;
                            item1.in = 0;
                            item1.dex = 0;
                            ch.gold -= 100;
                            printf("아이템 구매에 성공하였습니다.");
                            item1.itemcount++;
                        }
                        else
                            printf("아이템 구매에 실패하였습니다. (골드나 레벨을 확인해주세요.)");
                        ;
                        break;
                    case 2:
                        if (ch.gold >= 100)
                        {
                            item2.power = 5;
                            item2.in = 5;
                            item2.dex = 0;
                            item2.str = 0;
                            ch.gold -= 100;
                            printf("아이템 구매에 성공하였습니다.");
                            item2.itemcount++;
                        }
                        else
                            printf("아이템 구매에 실패하였습니다. (골드나 레벨을 확인해주세요.)");

                        break;
                    case 3:
                        if (ch.gold >= 100)
                        {
                            item3.power = 3;
                            item3.dex = 4;
                            item3.in = 0;
                            item3.str = 0;
                            ch.gold -= 100;
                            printf("아이템 구매에 성공하였습니다.");
                            item3.itemcount++;
                        }
                        else
                            printf("아이템 구매에 실패하였습니다. (골드나 레벨을 확인해주세요.)");

                        break;
                    case 4:
                        if (ch.lv >= 99 && ch.gold >= 1000)
                        {
                            item4.power = 95;
                            item4.str = 90;
                            item4.in = 99;
                            item4.dex = 90;
                            ch.gold -= 1000;
                            printf("아이템 구매에 성공하였습니다.");
                            item4.itemcount++;
                        }
                        else
                            printf("아이템 구매에 실패하였습니다. (골드나 레벨을 확인해주세요.)");

                        break;
                    default:
                        break;
                    }
                    if (ingame >= 5)
                        break;
                }
            }
            else if (ingame == 6)
            { //사냥터

                printf("몬스터1이 나타났다.!!\n");
                printf("싸우시겠습니까? y/n\n");
                ch.exp += war(&m3, &ch);
                lvup(&ch);
            }
            else if (ingame == 7)
            { //종료
                CLR;
                printf("종료합니다.\n");
                break;
            }
            else
            { //휴식
                CLR;
                printf("잠시 휴식()\n");
                ch.exp++;
                lvup(&ch);
            }
        }
        break;
        break;
    case 2:
        printf("2. 불러오기\n"); // 구현 x
    }
    scanf("%c", &a);
    printf("%d", i);
    return 0;
}
int war(struct monster *m3, struct character *ch)
{
    int i = 1;
    int exp;
    m3->hp = 1000;
    m3->mp = 100;
    m3->dmg = 1;
    m3->lv = 1;
    m3->exp = 10;
    while (i)
    {

        if (ch->hp >= 0)
        {
            CLR;

            printf("몬스터 hp: %d\n", m3->hp);
            printf("몬스터 mp: %d\n", m3->mp);
            printf("내 hp: %d\n", ch->hp);
            printf("내 mp: %d\n", ch->mp);
            i = rand() % 2 + 1;
            if (i == 1)
            {
                m3->hp -= ch->dmg;
            }
            if (i == 2)
            {
                ch->hp -= m3->dmg;
            }
            if (m3->hp <= 0)
            {
                exp = m3->exp;
                printf("축하합니다 ! 몬스터를 물리쳤습니다. 경험치가 오릅니다.\n");

                break;
            }
            if (ch->hp <= 0)
            {
                exp = -m3->exp;
                printf("플레이어가 사망하셨습니다.\n 몬스터의 경험치만큼 경험치가 하락합니다.");

                break;
            }
        }
    }
    return exp;
}
