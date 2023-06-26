 #include <stdio.h>

 int main()
 {
    const char* mythings[5] = {
        "Dancing in rhe rain",
        "Counting apples",
        "Watching movies with friends",
        "Writing sad letters",
        "Studying the language",
    };

    const char yourthings[5][50] = {
    "I broke up with her last week",
    "I told her that we should break up.",
    "But now I regret it.",
    "Why did I say that to her?",
    "I have no choice. I have to overcome this with determination."
};

const char* temp1 = "Dancing in the rain";
const char* temp2 = "I broke up with her last week";

printf("%s %p %p\n", mythings[0], (void*)temp1, (void*)temp2);
printf("%s %p %p\n", yourthings[0], (void*)yourthings[0], (void*)yourthings[1]);
printf("\n");

int i = 0;
printf("%-30s %-30s\n", mythings[i], yourthings[i]);
printf("\nsizeof mythings: %zd, sizeof yourthings: %zd\n",
       sizeof(mythings), sizeof(yourthings));

for (int i = 0; i < 100; i++)
    printf("%c", mythings[0][1]);
printf("\n\n");

for (int i = 0; i < 100; i++)
    printf("%c", mythings[0][1]);
printf("\n");

return 0;
 }