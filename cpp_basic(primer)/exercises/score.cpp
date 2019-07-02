#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter a group of scores:" << std::endl;
    std::vector<unsigned> scores(11, 0);
    unsigned grade;
    while (std::cin >> grade) {
        if (grade <= 100)
            ++scores[grade/10];
    }
    std::cout << "All the levels are:" << std::endl;
    for (int i = 0; i < 11; i++) {
        std::cout << scores[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}