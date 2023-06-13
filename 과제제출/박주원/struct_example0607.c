#define _CRT_SECURE_NO_WARNINGS
#define LEN 20
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct names { //문자열 배열 구조체 
    char given[LEN];
    char family[LEN];
};

struct reservation { //구조체
    struct names guest; 
    struct names host;
    char food[LEN];
    char place[LEN];

    //전역함수
    int year;
    int month;
    int day;
    int hours;
    int minutes;
};

int main(void)
{
    struct reservation res = { //인스턴스 함수
        .guest = {"ParkJuWon","JoHoHyun"},
        .host = {"BaekJiHun"},
        .place = {"baek's Backyard"},
        .food = {"SamGyupSal"},
        .year = 2023,
        .month = 4,
        .day = 21,
        .hours = 15,
        .minutes = 20 

    };

    const char* formatted =  //문자열 포맷
        "\
        Dear %s %s,\n        I would like to serve you %s.\n\
        Please visit %s on %d/%d/%d at %d:%d.\n\
        Sincerely, \n\
        %s %s\
        ";

        printf(formatted,res.guest.given,res.guest.family,res.food,
            res.place,res.day,res.month,res.year,res.hours,res.minutes,
            res.host.given,res.host.family);

        return 0;
}