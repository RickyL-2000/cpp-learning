//迭代器练习
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums;
    int num;
    std::cout << "Enter some integers:" << std::endl;
    while (std::cin >> num) {
        nums.push_back(num);
    }
    for (auto iter = nums.begin(); iter != nums.end(); iter++) {
        *iter *= 2;
    }
    auto iter = nums.begin();
    while (iter != nums.end()) {
        std::cout << *iter << ' ';
        iter++;
    }
    std::cout << std::endl;
    return 0;
}