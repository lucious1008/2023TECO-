#include<stdio.h>

struct player{ //구조체 포인터는 다른 자료형끼리 묶어 쓰기 편하게 쓰인다. 
    char name[12];
    int height, Weight,sum,total;
};

int main(){
    //                        s[0]                    s[1]                    s[2]
    struct player s[3] = {{"SonHeongMin",183,77},{"HwangHeeChan",177,77},{"LeeKangIn",173,63}};
    //                                ｐ                    ｐ＋１                  ｐ＋２  
    struct player* p;

    p = &s[0]; // <- 주소*                 *p , p=&변수 

    //     240           177              63    
    (p+1)->sum = (p+1)->height + (p+2)->Weight;
    //     260            240       183          77
    (p+1)->total = (p+1)->sum + p->height + p->Weight;
    //     740           240   +    500
    printf("%d\n",(p+1)->sum+(p+1)->total); 
}

