		#include <stdio.h>
		#include <stdlib.h>
		#include <string.h>
	
		// �÷��̾� ����ü 
		typedef struct {
		  char name[20]; // �÷��̾�  �̸�
		  int hp; // ü�� 
		  int mp; // ���� 
		  int gold; // ��� 
				} Player;
	
		// ���� ����ü
		  typedef struct {
		  char name[20]; // ���� �̸�
		  int hp; // ü�� 
		  int atk; // ���ݷ� 
		  int exp; // ����ġ 
		  int gold; // ��� 
			} Monster;
	
		// ���� ���� 
			int gameover = 0;
	
		// �÷��̾�  �ʱ�ȭ 
			void init_player(Player *player, char *name) {
		  	strcpy(player->name, name);
		  	player->hp = 100;
		  	player->mp = 50;
		  	player->gold = 0;
			}	
		
			// ���� �ʱ�ȭ 
			void init_monster(Monster *monster, char *name, int hp, int atk, int exp, int gold) {
	  		strcpy(monster->name, name);
	  		monster->hp  = hp;
	  		monster->atk = atk;
	  		monster->exp = exp;
	  		monster->gold = gold; 
			}
	
			//  ���� �Լ� 
		   	void battle(Player *player, Monster *monster) {
	  	   	printf("%s��(��) %s�� ������ ���۵˴ϴ� !\n", player->name, monster->name);
	  
	  	   	while(player->hp > 0 && monster->hp > 0) {
	    	// �÷��̾  ���͸� ���� 
	      	int damage = rand() % 10 + player->hp;
	      	monster->hp -= damage;
	      	printf("%s��(��) %s���� %d�� ���ظ� �������ϴ�!\n", player->name, monster->name, damage);
	    	
	      	if(monster->hp <= 0) {
	      	printf("%s��(��) �����ƽ��ϴ�!\n", monster->name);
	      	player->gold+= monster->exp;
	      	
	      	break;
	    	}
	    
	      	// ���Ͱ� �÷��̾ ���� 
	      	damage = rand() % 10 + monster->atk;
	      	player->hp -= damage;
	      	printf("%s��(��) %s���� %d�� ���ظ�  �Ծ����ϴ�!\n", player->name, monster->name, damage);
	    
	      	if (player->hp <= 0) {
	      	printf("%s��(��) ����߽��ϴ�.\n", player->name);
	      	gameover = 1;
	      	break;
	    	}
	    	//���� ��� �Լ� 
		    void shop(Player *player) {
			printf("� ������! �����Դϴ�.\n");
			while (1) {
			printf("1. ü�� ���� (50���) - ü���� 50 ȸ���մϴ�.\n");
			printf("2. ���� ���� (50���) - ������ 50 ȸ���մϴ�.\n");
			printf("3. ��ȭ�� �� (100���) - ���ݷ��� 10 ������ŵ�ϴ�.\n");
			printf("4. ����\n");
			int choice;
			printf("������ �����Ͻðڽ��ϱ�? ");
			scanf("%d", &choice);
			switch (choice) {
			case 1:
			if (player->gold >= 50) {
			player->gold -= 50;
			player->hp += 50;
			printf("ü���� ȸ���߽��ϴ�. ���� ü��: %d\n", player->hp);
			} else {
			printf("��尡 �����մϴ�.\n");
			}
			break;
			case 2:
			if (player->gold >= 50) {
			player->gold -= 50;
			player->mp += 50;
			printf("������ ȸ���߽��ϴ�. ���� ����: %d\n", player->mp);
			} else {
			printf("��尡 �����մϴ�.\n");
			}
			break;
			case 3:
			if (player->gold >= 100) {
			player->gold -= 100;
			player->hp += 10;
			printf("���ݷ��� �����߽��ϴ�. ���� ���ݷ�: %d\n", player->hp);
			} else {
			printf("��尡 �����մϴ�.\n");
			}
			break;
			case 4:
			printf("������ �����ϴ�.\n");
			return;
			default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
			break;
				}
				}
				}
		    	
			  }
			}
	

