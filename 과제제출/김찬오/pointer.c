		#include <stdio.h>
		
		void stringCopy(char* dest, const char* src) {
		    while (*src != '\0') {
		        *dest = *src;
		        src++;
		        dest++;
		    }
		    *dest = '\0';
		}
		
		int main() {
		    char str1[] = "Hello, world!";
		    char str2[20];
		
		    // str2�� str1�� �����մϴ�.
		    stringCopy(str2, str1);
		
		    printf("%s\n", str2);
		
		    return 0;
		}
