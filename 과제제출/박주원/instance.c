#include<stdio.h>
#include<string.h>

//구조체 선언
struct Food{
    int FoodPrice; //음식의 가격을 나타내는 인스턴스 변수
    char Foodflavor[20]; //음식의 맛을 나타내는 인스턴스 변수
};

//구조체 선언
struct Drink{
    int DrinkPrice; //음료 가격에 대한 인스턴스 변수
    char DrinkFlavor[20]; //음료 맛에 대한 인스턴스 변수

};

//지역변수
int main(){
    struct Food takoyaki; // 타코야키 객체 생성
    
    // 타코야키 객체에 대한 가격
    takoyaki.FoodPrice = 5500; 
    //타코야키 맛에 대한 속성
    strcpy(takoyaki.Foodflavor, "Salty");   



    struct Drink Coke; // 콜라 객체

    //콜라 객체에 대한 가격
    Coke.DrinkPrice = 4000;
    //콜라 맛에 대한 속성
    strcpy(Coke.DrinkFlavor,"sweety");
    
    //함수 
    int TotalPrice = takoyaki.FoodPrice + Coke.DrinkPrice;

    //출력
    printf("Takoyaki is %d Won and Coke is %d Won. It's %d Won in total.\n",takoyaki.FoodPrice,Coke.DrinkPrice,TotalPrice);
    printf("Coke is %s, and Takoyaki is %s. That's the best combination.",Coke.DrinkFlavor,takoyaki.Foodflavor);

    return 0;

    }