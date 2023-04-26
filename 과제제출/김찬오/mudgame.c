		#include <stdio.h>
		#include <stdlib.h>
		#include <string.h>
	
		// 플레이어 구조체 
		typedef struct {
		  char name[20]; // 플레이어  이름
		  int hp; // 체력 
		  int mp; // 마나 
		  int gold; // 골드 
				} Player;
	
		// 몬스터 구조체
		  typedef struct {
		  char name[20]; // 몬스터 이름
		  int hp; // 체력 
		  int atk; // 공격력 
		  int exp; // 경험치 
		  int gold; // 골드 
			} Monster;
	
		// 게임 상태 
			int gameover = 0;
	
		// 플레이어  초기화 
			void init_player(Player *player, char *name) {
		  	strcpy(player->name, name);
		  	player->hp = 100;
		  	player->mp = 50;
		  	player->gold = 0;
			}	
		
			// 몬스터 초기화 
			void init_monster(Monster *monster, char *name, int hp, int atk, int exp, int gold) {
	  		strcpy(monster->name, name);
	  		monster->hp  = hp;
	  		monster->atk = atk;
	  		monster->exp = exp;
	  		monster->gold = gold; 
			}
	
			//  전투 함수 
		   	void battle(Player *player, Monster *monster) {
	  	   	printf("%s과(와) %s의 전투가 시작됩니다 !\n", player->name, monster->name);
	  
	  	   	while(player->hp > 0 && monster->hp > 0) {
	    	// 플레이어가  몬스터를 공격 
	      	int damage = rand() % 10 + player->hp;
	      	monster->hp -= damage;
	      	printf("%s이(가) %s에게 %d의 피해를 입혔습니다!\n", player->name, monster->name, damage);
	    	
	      	if(monster->hp <= 0) {
	      	printf("%s을(를) 물리쳤습니다!\n", monster->name);
	      	player->gold+= monster->exp;
	      	
	      	break;
	    	}
	    
	      	// 몬스터가 플레이어를 공격 
	      	damage = rand() % 10 + monster->atk;
	      	player->hp -= damage;
	      	printf("%s이(가) %s에게 %d의 피해를  입었습니다!\n", player->name, monster->name, damage);
	    
	      	if (player->hp <= 0) {
	      	printf("%s은(는) 사망했습니다.\n", player->name);
	      	gameover = 1;
	      	break;
	    	}
	    	//상점 기능 함수 
		    void shop(Player *player) {
			printf("어서 오세요! 상점입니다.\n");
			while (1) {
			printf("1. 체력 포션 (50골드) - 체력을 50 회복합니다.\n");
			printf("2. 마나 포션 (50골드) - 마나를 50 회복합니다.\n");
			printf("3. 강화의 돌 (100골드) - 공격력을 10 증가시킵니다.\n");
			printf("4. 종료\n");
			int choice;
			printf("무엇을 구매하시겠습니까? ");
			scanf("%d", &choice);
			switch (choice) {
			case 1:
			if (player->gold >= 50) {
			player->gold -= 50;
			player->hp += 50;
			printf("체력을 회복했습니다. 현재 체력: %d\n", player->hp);
			} else {
			printf("골드가 부족합니다.\n");
			}
			break;
			case 2:
			if (player->gold >= 50) {
			player->gold -= 50;
			player->mp += 50;
			printf("마나를 회복했습니다. 현재 마나: %d\n", player->mp);
			} else {
			printf("골드가 부족합니다.\n");
			}
			break;
			case 3:
			if (player->gold >= 100) {
			player->gold -= 100;
			player->hp += 10;
			printf("공격력이 증가했습니다. 현재 공격력: %d\n", player->hp);
			} else {
			printf("골드가 부족합니다.\n");
			}
			break;
			case 4:
			printf("상점을 나갑니다.\n");
			return;
			default:
			printf("잘못된 입력입니다. 다시 선택해주세요.\n");
			break;
				}
				}
				}
		    	
			  }
			}
	

