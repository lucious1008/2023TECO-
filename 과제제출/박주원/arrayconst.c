#include<stdio.h>

void print_array(int arr[],int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ",arr[i]);
        printf("\n");
}

void add_value(int arr[],int n, int val) //배열의 모든 함수의 값을 더하는 식
{
    int i;
    for (i = 0; i<n; i++)
        arr[i] += val;
}

int sum(int ar[],int n) //int sum(const in ar[], const int n)
{
    int i;
    int total = 0;

    for(i = 0; i < n; i++)
        total += ar[i];
        // total += ar[i] ++; 이와 같이 강제로 수를 수정하는경우 const 필요 
    return total;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5}; //배열의 값이 바뀌면 안되는 상황일 때 const
    int n = sizeof(arr) / sizeof(arr[0]); 

    print_array(arr,5);
    add_value(arr,5,100); //배열의 값을 바꾸려고 하는 변수
    print_array(arr,5);

    int s =sum(arr,n);

    printf("sum is %d\n",s);
    print_array(arr,5);

    return 0;
}