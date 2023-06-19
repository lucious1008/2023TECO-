// double year2016[MONTHS] = {-3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1,16.1, 6.8, 1.2};
// double year2017[MONTHS] = {-1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9};
// double year2018[MONTHS] = {-4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6};
#include <stdio.h>

#define YEARS 3
#define MONTHS 12
// 2차원배열 사용하여 기온 나타내기
int main() {
    double temperature[YEARS][MONTHS] = {
        {-3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2},
        {-1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9},
        {-4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6}
    };

    printf("[Temperature Data]\n");

    printf("Year index : ");
    for (int m = 0; m < MONTHS; ++m) {
        printf("\t%d", m + 1);
    }
    printf("\n");

    for (int y = 0; y < YEARS; ++y) {
        printf("Year %d     : ", y);
        for (int m = 0; m < MONTHS; ++m) {
            printf("\t%.1f", temperature[y][m]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}
