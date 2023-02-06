#include "Bit.h"
#include "pointer.h"
#include <stdio.h>


int main()
{
	//printSub(4);
	int* intA = pointerPrint();
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	free(intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	printf("*** %d ***\n", *intA);
	return 0;
}