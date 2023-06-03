#include <stdio.h>

void main(void)
{
    int a,b,c,d = 0;
	
	while(1){
        printf("初めの値を書いてください : \n");
        scanf("%d",&a);
        printf("二つの値を書いてください　：　\n",a);
        scanf("%d",&b);
        
        printf("演算子を指定してください\n",a);
        printf("=======================\n",a);
        printf("1: +  2: - 3: * 4: /\n",a);
        scanf("%d",&c);
        
        switch(c){
        	case 1:
        		d = a + b;
        		printf("%d + %d = %d\n",a,b,d);
        		break;
        	case 2:
        		d = a - b;
        		printf("%d - %d = %d\n",a,b,d);
        		break;
        	case 3:
        		d = a * b;
        		printf("%d * %d = %d\n",a,b,d);
        		break;
        	case 4:
        		if(a > b){
        			d = a / b;
        			printf("%d / %d = %d\n",a,b,d);
				}else{
	        		printf("%dの値が%dより多いです。\n",b,a);
				}
        		break;
		default:
			printf("1~4の中で書いてください。\n");
		}
	}	
}
