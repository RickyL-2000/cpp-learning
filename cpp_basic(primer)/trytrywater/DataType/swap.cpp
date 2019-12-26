#include <iostream>

void swap_ref(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int x = 1;
    int y = 2;
    swap_ref(x, y);
    std::cout << x << y << std::endl;
    return 0;
}