#include <iostream>
int main()
{
    int ia[3][4] = {};
    for (auto &row : ia) {
        for (auto col : row)
            std::cout << col << ' ';
        std::cout << "\n";
    }
    std::cout << std::endl;
    return 0;
}