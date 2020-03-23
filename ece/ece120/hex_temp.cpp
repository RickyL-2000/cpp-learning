#include <iostream>
using namespace std;

int main() {
    int x = !(0x3F | (0x8B & 0x99));
    printf("%d", x);
    return 0;
}