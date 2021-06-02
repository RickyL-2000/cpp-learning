#include <iostream>
#include <string>
int main()
{
    int a = 0, b = 0; // rmmmmmm
    std::cout << "Enter two integers a, b that a > b: "
              << std::endl;
    std::cin >> a >> b; 
    for (; a >= b; --a)
        std::cout << a << std::endl;
    return 0;
}