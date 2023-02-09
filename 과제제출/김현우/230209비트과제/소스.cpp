#include <stdio.h>

    int main(){
    
        int n = 0;

       for (int i = 0; i < (1 << n); ++i)

        {

        for (int j = 0; j < n; ++j)

        {

            printf("{");

        if (i & (1 << j))

            printf("%d, ", j);

        printf("}\n");

    }

}
}