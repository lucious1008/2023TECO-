#include<stdio.h>

int main()
{
    //1차원배열
    // int arr0[3] = {1,2,3};
    // int arr1[3] = {4,5,6};

    // int* parr[2] = {arr0, arr1}; //배열의 포인터 // arr0 의 첫번째 주소, arr1의 첫번째 주소

    // for(int j = 0; j < 2; ++j)
    // {
    //     for (int i = 0; i<3; ++i)
    //         printf("%d(==%d,%d)",parr[j][i],*(parr[j]+i),(*(parr + j))[i]);
    //                                     // 접근한 원소가 포인터이기 때문에 포인터 산술연산
    //     printf("\n");
    // }
    // printf("\n");


    //2차원 배열
 
    // int *parr0 = arr[0]; //1번째 차원
    // int *parr1 = arr[1];

    // for (int i = 0; i < 3; ++i)
    //     printf("%d", parr0[1]);
    // printf("\n")

    // for(int i=0; i<3; ++i)
    //     printf("%d", parr1[i]);
    // printf("\n");


    int arr[2][3] = { {1, 2, 3},{4, 5, 6}};
    int *parr[2]; //포인터 하나가 4 바이트 왼쪽은 8바이트 메모리의 첫번째 주소를가르킴
    parr[0] = arr[0];
    parr[1] = arr[1];

    for(int j = 0; j<2; ++j)
    {
        for(int i =0; i < 3; ++i)
        printf("%d %d %d %d\n",
            arr[j][i],parr[j][i], *(parr[j]+i),*(*(parr + j)+i));
        printf("\n");
    }
    printf("\n");

printf("%p\n", &parr[0]); //포인터의 주소(포인터를 저장할수 있는 메모리가 존재)
printf("%p\n",parr[0]); //가리키는 주소
printf("%p\n",arr); // 포인터를 저장할수있는 메모리가 없음, 하지만 값은 아래와 같이나옴
printf("%p\n",&arr[0]);
printf("%p\n",arr[0]); //아래와 같은주소
printf("%p\n",&arr[0][0]);


    int arr[2][3] = { {1, 2, 3},{4, 5, 6}};
    int* parr[2];
    parr[0] = arr[0];
    parr[1] = arr[1];

    for (int j = 0; j<2; ++i)
        printf("%d %d %d %d\n",)
}