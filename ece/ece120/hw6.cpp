#include <stdio.h>
int main() {
    unsigned int w, x, y, z, a, b;
    unsigned int g;
    printf("k-map1      yz \n");
    printf("       00 01 11 10 \n");
    printf("     ______________\n");
    for (w = 0; w < 2; w++) {
        for (a = 0; a < 2; a++) {
            x = (w ^ a) & 1;
            printf("wx=%u%u | ", w, x);
            for (y = 0; y < 2; y++) {
                for (b = 0; b < 2; b++) {
                    z = (y ^ b) & 1;
                    g = (x & ~y) | (~w & z);
                    g &= 1;
                    printf("%u  ", g);
                }
            }
            printf("\n");
        }
    }
    printf("\n");
    printf("k-map2      yz \n");
    printf("       00 01 11 10 \n");
    printf("     ______________\n");
    for (w = 0; w < 2; w++) {
        for (a = 0; a < 2; a++) {
            x = (w ^ a) & 1;
            printf("wx=%u%u | ", w, x);
            for (y = 0; y < 2; y++) {
                for (b = 0; b < 2; b++) {
                    z = (y ^ b) & 1;
                    g = (~w & x & y & ~z) | w | (~x);
                    g &= 1;
                    printf("%u  ", g);
                }
            }
            printf("\n");
        }
    }
    return 0;
}