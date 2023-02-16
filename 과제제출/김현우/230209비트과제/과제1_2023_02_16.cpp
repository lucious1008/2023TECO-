#include <stdio.h>

	//과제 1
	void arr_copy(int *a, int *b, int size) 
	{

	int i;

	for (i = 0; i < size; i++) {

		*(b + i) = *(a + i);
		printf("%d", *(b + i));

	}
	printf("\n");

	}
	//과제 2
	void string_copy(char *a, char *b, int size)
	{

		int i;

		for (i = 0; i < size; i++) {

			if (*(b + i) == *(a + i)) {

				printf("%c", *(b + i));
			}
			

		}
		printf("\n");

	}



	int main()
	{
	int a[5] = { 1,2,3,4,5 };
	int b[5];


	arr_copy(a, b, 5);

	char c[26] = "String is difficult";
	char d[26] = "string is not inefficinet";

	string_copy(c, d, 26);


	return 0;

	}
	


