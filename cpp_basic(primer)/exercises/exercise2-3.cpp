#include <iostream>
int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    int i = 11, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl; 
    /* 
    我故意修改了i的值，发现i-u的时候套用的是i的类型，
    u-i的时候套用的是u的类型。
    */
    return 0;
}