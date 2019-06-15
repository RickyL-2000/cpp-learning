#include <iostream>
int main()
{
    std::cout << "Please enter two integers a, b that a > b "
              << std::endl;
    int a = 0, b = 0;
    std::cin >> a >> b;
    while (a >= b){
        std::cout << a << std::endl;
        --a;
    }
    return 0;
}