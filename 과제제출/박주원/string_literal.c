#include<stdio.h>

#define MESSAGE "A simbolic string contant"
#define MAXLENGTH 81

int main()
{
    char words[MAXLENGTH] = "A string in an array";
    //첫번째 주소만 가져온다.
    const char* pt1 = "A pointer to a string.";


    //배열은 읽기/쓰기가 모두 가능한 메모리를 사용한다.
    //문자열 리터럴은 프로그램의 일부이기 때문에 읽기 전용 메모리에 저장되어 있다.
    puts("Puts() adds a newline at the end :"); // puts() add \n at the end
    put(MESSAGE);
    puts(words); //char words[21] removes this warning
    puts(pt1);
    words[3] = 'p'; // 교체 ok
    puts(words);
    //pt[8] = 'A'; // RunTime Error 읽기 전용 메모리에 저장된 데이터 값을 바꾸려고 시도하면 운영체제가 중단

    char greeting[50] = "Hello,and""How are" "you"
                        "today...";
    // == char greeting[50] = "Hello, and How are you today!";
    puts(greeting);

    printf("\" to be, or not to be \"hamlet said. \n");

    // %p 는 배열에 넣어서 초기화함
    // 문자열 앞에 역참조 : 첫번째 공간의 주소를 역참조 'e'
    printf("%s, %p, %c\n","We","are", *"excellent programmers");

    int n = 8;
    char cookies[1] = {'A', };
    char cakes[2 + 5] = {'A'};
    char pies[2 * sizeof(long double)+1] = {'A', };

    char truth[10] = "Truths is "; //배열의 성질을 가지고 있음
    if(truth == &truth[0]) puts("true!");
    if(*truth == T) puts("true!");
    if(*(truth+1) == truth[1]) puts("true!");
    if(truth[1]=='r') puts("true!")

}