#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

struct PenaltyKick {
    short kicker; // 인스턴스 변수, 키커가 선택한 위치 (1: 왼쪽, 2: 가운데, 3: 오른쪽)
    short keeper; // 인스턴스 변수, 골키퍼가 선택한 위치 (랜덤 생성)
};

void pk(struct PenaltyKick* kick) {
    do {
        //어느쪽으로 찰지 안내문 출력
        printf("Choose the Direction :1. left 2.middle 3. right\n");
        // 사용자로부터 키커의 선택 위치 입력 받기
        scanf("%hd", &kick->kicker); 
        switch (kick->kicker) {
            case 1:
                printf("Left!!!!\n"); // 왼쪽으로 킥
                break;
            case 2:
                printf("Middle!!!\n"); // 가운데로 킥
                break;
            case 3:
                printf("Right!!!\n"); // 오른쪽으로 킥
                break;
            default:
                printf("error\n"); // 에러
                break;
        }
    } 
    // 유효한 범위 내의 입력을 받을 때까지 반복
    while (kick->kicker < 1 || kick->kicker > 3); 
}

void getRandomNumber(struct PenaltyKick* kick) {
    //랜덤 함수 1~3
    kick->keeper = (rand() % 3 + 1); 
}

bool match(short kicker, short keeper) {
    if (kicker == keeper) {
        // 키커와 골키퍼의 위치가 일치하면 막힘
        return true; 
    } else {
        // 키커와 골키퍼의 위치가 일치하지 않으면 골
        return false; 
    }
}

void main() {
    // 현재 시간을 기반으로 난수 시드 설정
    srand(time(NULL)); 
    //구조체 선언
    struct PenaltyKick kick;
    // 키커의 선택 위치 입력 받기
    pk(&kick);
    // 랜덤한 골키퍼의 위치 생성
    getRandomNumber(&kick); 

    if (match(kick.kicker, kick.keeper)) {
        printf("No Goal..."); // 키커와 골키퍼의 위치가 일치하여 막힘
    } else {
        printf("GOAL!!"); // 키커와 골키퍼의 위치가 일치하지 않아 골
    }
}
