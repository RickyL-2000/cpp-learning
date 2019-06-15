#include <iostream>
int main()
{
    int a = 10, b = 15;
    int *i = nullptr, *j = nullptr, *k = &b;
    std::cout << *k << std::endl;
    i = &b;
    j = k;
    b = 20;
    std::cout << *i << std::endl;
    std::cout << *j << std::endl;
    return 0;
}