#include<stdio.h>

int main()
{
    /*Pointer Compatibility*/
    int n = 5;
    double x;
    x = n; //정수를 int에 넣으면 형변환이 가능함.
    int* p1 = &x;
    double* pd = &x;
    //pd =p1; //Warning int형을 double에 대입하면 형변환이 불가능.
   // pd = (double*)p1; // 굳이 하자면 가능하지만 권장하지않음.

    int* pt;
    int(*pa)[3]; //3개짜리 원소를 가진 배열을 담는 포인터
    int ar1[2][3] ={3, }; // [2][3] 이기때문에 *pa[3]에 대입가능 
    int ar2[3][2] = {7, }; //[3][2] 배열이 2개이기 때문에 대입불가
    int** p2; //a pointer to a pointer


    pt = &ar1[0][0];   //pointer - to -int 
    // for (int i = 0 i <6; ++i) //포인터 하나만으로 원소가 몇개인지 알 수 없기 떄문에 i < 6
    //     printf("%d",*(pt+i));

    pt = ar1[0];       //pointer - to -int; 위의 문법과 같은 맥락
    //pt = ar1;        //Warning (Error)
    pa = ar1;          //pointer - to - int[3]
    p2 = &pt; //이중포인터 : 포인터의 주소를 담을 수 있음
    *p2 = ar[0] //int의 포인터
}