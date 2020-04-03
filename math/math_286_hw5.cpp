#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double x = 0.5;
    double y = M_PI/6;
    double Tx, Ty;
    int count = 0;

    while (true) {
        Tx = 0.01 * x * x + sin(y);
        Ty = cos(x) + 0.01 * y * y;
        count++;
        printf("%d x: %.9lf y: %.9lf\n", count, Tx, Ty);
        if (abs(Tx - x) <= 0.000000001 && abs(Ty - y) <= 0.000000001) {
            break;
        } 
        x = Tx;
        y = Ty;
    }

    return 0;
}