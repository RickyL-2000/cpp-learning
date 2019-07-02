//用迭代器为分数划段
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter the grades:" << std::endl;
    std::vector<int> scores(11, 0);
    int grade;
    auto iter = scores.begin();
    while (std::cin >> grade) {
        if (grade <= 100) {
            ++*(iter + grade/10);
        }
    }
    while (iter != scores.end()) {
        std::cout << *(iter++) << ' '; //果然这里的++可以这么用
    }
    std::cout << std::endl;
    return 0;
}