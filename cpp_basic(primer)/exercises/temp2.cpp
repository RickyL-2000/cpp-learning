#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vect = {1,2,3};
    for (int i = 0; i < 3; ++i) {
        std::cout << vect[i] << ' ';
    }
    std::cout <<std::endl;
    return 0;
}