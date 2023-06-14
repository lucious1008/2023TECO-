#include<stdio.h>
/*union은 메모리 데이터를 공유*/
struct personal_owner {
    char rrn1[7];   //Rsident Registration Number
    char rrn2[8];   //830422 - 1185600
};

struct company_owner{
    char crn1[4];   //Company Resistration Number
    char crn2[3];   //111 - 22 -33333
    char crn3[6];   // NULL값 생각해서 메모리를 1칸 더 늘려 씀
};

union data {
    struct personal_owner po;
    struct company_owner co;
};

struct car_data{
    char model[15];
    int status; // 0 = personal, 1 = company
    union data ownerinfo;
};

void print_car(struct car_data car)
{
    printf("*************************\n");
    printf("Car Model : %s\n",car.model);
    if(car.status == 0){
    printf("personal owner : %s - %s\n",car.ownerinfo.po.rrn1,car.ownerinfo.po.rrn2);
    }
    else {
        printf("company owner : %s - %s - %s\n",car.ownerinfo.co.crn1,car.ownerinfo.co.crn2,car.ownerinfo.co.crn3);
    }
    printf("*************************\n");
}

int main()
{
    struct car_data my_car =  {.model = "avante", .status = 0 , .ownerinfo.po = {"830422","1185600"}};
    struct car_data cp_car =  {.model = "Porsche",.status = 1 , .ownerinfo.co = {"123","45","67890"}};

    print_car(my_car);
    print_car(cp_car);

    return 0;
}