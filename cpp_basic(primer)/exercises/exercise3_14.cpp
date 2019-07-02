#include <iostream>
#include <vector>

int main()
{
    int num;
    std::vector<int> nums;
    std::cout << "Enter a couple of numbers: " << std::endl;
    while (std::cin >> num) {
        nums.push_back(num);
    }
    std::cout << "Your numbers:" << std::endl;
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}