/* This program includes exercise 1.4, 1.5, 1.6 */

#include <iostream>
int main()
{
    std::cout << "Please Enter two integers:"; 
    std::cout << std::endl;
    int x = 0, y = 0;
    std::cin >> x;
    std::cin >> y;
    std::cout << "The product of these two numbers is ";
    std::cout << x*y;
    std::cout << std::endl;
    /* 
    every statement must follow std::cout
    HOWEVER, if there is no ";" following, this prefix can be ignored
    e.g.
    std::cout << x
              << y
              << std::endl;
     */
    return 0;
}