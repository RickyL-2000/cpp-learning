#include <iostream>
int main() {
    int x, y, z, f;
    printf("\nTruth Table\n");
    printf("x y z   f\n");
    for (x = 0; x <= 1; x++) {
        for (y = 0; y <= 1; y++) {
            for (z = 0; z <= 1; z++) {
                f = (~x & ~y) | (~y & ~z) | (~x & z);
                f &= 1;
                printf("%d %d %d   %d\n", x, y, z, f);
            }
        }
    }

    // int A, B, C, D, G;
    // printf("\nTruth Table\n");
    // printf("A B C D   G\n");
    // for (A = 0; A <= 1; A++) {
    //     for (B = 0; B <= 1; B++) {
    //         for (C = 0; C <= 1; C++) {
    //             for (D = 0; D <= 1; D++) {
    //                 G = (~B|~D)&(~B|~C)&(~A|~B)&(~C|~D);
    //                 G &= 1;
    //                 printf("%d %d %d %d   %d\n", A, B, C, D, G);
    //             }
    //         }
    //     }
    // }

    return 0;
}