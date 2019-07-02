#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter a group of integers:" << std::endl;
    std::vector<int> nums, ans;
    int num;
    while (std::cin >> num) {
        nums.push_back(num);
    }
    for (int i = 0; i < nums.size()/2; i++) {
        ans.push_back(nums[i]+nums[nums.size()-i-1]);
    }
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << ' ';
    }
    if (nums.size() % 2 != 0) {
        std::cout << nums[nums.size()/2];
    }
    std::cout << std::endl;
    return 0;
}