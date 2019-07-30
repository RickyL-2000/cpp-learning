#include <iostream>
#include <vector>
using namespace std;
vector<int> maxSubArray(vector<int>&);

int main() {
    int num;
    cin >> num;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    vector<int> ans = maxSubArray(nums);
    for (int a : ans) {
        cout << a << endl;
    }
    return 0;
}

vector<int> maxSubArray(vector<int>& nums) {
    int thisSum = nums[0], maxSum = nums[0];
    int left = nums[0], right = nums[0];
    for (size_t i = 1; i != nums.size(); ++i) {
        if (thisSum > 0) {
            thisSum += nums[i];
            right = nums[i];
        } else {
            thisSum = nums[i];
            left = nums[i];
            right = left;
        }
        if (thisSum > maxSum) {
            maxSum = thisSum;
        }
    }
    if (maxSum < 0) {
        return {0, *nums.begin(), *nums.end()};
    }
    return {maxSum, left, right};
}