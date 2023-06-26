#include <stdio.h>

int main()
{
    char heart[] = "I love Kelly!";
    const char* head = "I love Kelly";

    for (int i = 0; i < 6; i++)
        putchar(heart[i]);
    putchar('\n');

    for (int i = 0; i < 6; i++)
        putchar(head[i]);
    putchar('\n');

    // pointer addition
    for (int i = 0; i < 6; i++)
        putchar(*(heart + i));
    putchar('\n');

    for (int i = 0; i < 6; i++)
        putchar(*(head + i));
    putchar('\n');

    while (*head != '\0')
        putchar(*(head++));

    head = heart;

    heart[7] = 'H'; // note: character
    *(heart + 7) = 'K';

    putchar('\n');

    const char* word = "Goggle";
    puts(word);
    // Note: const char* word = "Goggle"; is recommended

    const char* str1 = "when all the lights are low, ...";
    const char* copy;

    copy = str1;

    printf("%s %p %p\n", str1, str1, &str1);
    printf("%s %p %p\n", copy, copy, &copy);

    // Note: strcpy(),strcpy()

    return 0;
}
