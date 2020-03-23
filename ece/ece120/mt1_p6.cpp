#include <iostream>
#include <math.h>

int main()
{
    /* declare variabes */
    int X, Y, i, sum = 0;
    /* ask user to input X and Y */
    printf("Please input two positive integers X, Y such that X > Y: ");
    /* collect user input */
    scanf("%d %d", &X, &Y);
    /* check if X is larger than Y. If not, print erro message and exit */
    if (X <= Y) {
        printf("Error: X is less or equal than Y!\n");
        return 0;
    }
    /* compute the above function */
    for (i = 1; i <= Y; i++) {
        sum += (int)pow((double)(X-i), (double)i);
    }
    /* print result */
    printf("The result is %d\n", sum);
    return 0;
}