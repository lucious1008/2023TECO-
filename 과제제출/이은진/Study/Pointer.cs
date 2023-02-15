using System;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace Study
{
	public class Pointer
	{
		public Pointer()
		{
            // 1번 문제

            // 푸는중.. 

            // 2번 문제

            # include<stdio.h>   

            int main(void)
            {
                char* str1 = "String is difficult";
                char* str2 = "string is not inefficient";


                //문자열 비교 반환값 확인
                printf("strcmp(%s, %s)\t = %d\n", str1, str2, strcmp(str1, str2));

                //문자열이 같은지를 판단할때는 이와같이 사용합니다.
                if (strcmp(str1, str2) == 0)
                {
                    printf("%s, %s 는 같습니다.", str1, str2);
                }
                else
                {
                    printf("%s, %s 는 다릅니다.", str1, str2);
                }

                return 0;
            }


            // 3번 문제

# include <stdio.h>

            int main(void)
            {

                char str1[] = "pointer";
                char str2[] = "is noting";
                char str3[] = "very easy man";

                char* chg = "is noting";

                str2[1] = "hi";
                for (char i = 0; i < sizeof(str2) / sizeof(char); i++)
                {
                    printf("%c ", str2[i]);
                }
                printf("\n");
                return 0;
            }

            // 4번 문제

            /**
             * 동적메모리로 할당했기 때문이다. 동적메모리는 정해진만큼의 메모리를 사용하는 것이 아니라, 가변적인 요소이기 때문에이다.
             * 메모리 사이즈를 지정을 해제하는 것이 아니고, 사용한 메모리의 주소 변수만 있으면 
             * 그 크기를 알아서 컴퓨터에서 체크해주기 때문에 해제할 필요가 없는것이다.
             * 
             * 동적메모리할당은 힙 영역을 제공하는데 힙 영역에서는 사용자가 원하는 시점 원하는 크기만큼 메모리를 할당할 수 있다.
             * 그리고 메모리 사용이 끝나면 언제든지 할당한 메모리 공간을 해제할 수 있다.
             * 
             * mallco 함수 - free로 메모리 해제
             * calloc 함수 - free로 메모리 해제
             * realloc 함수 - 메모리를 백업해둠 
             * 
             * 
        }
    }
}

