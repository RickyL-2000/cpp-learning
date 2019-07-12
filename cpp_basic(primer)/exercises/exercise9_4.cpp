#include <iostream>
#include <vector>
using namespace std;
bool find(vector<int>, int);

int main()
{
    cout << "Enter some integers (enter # to end it):" << endl;
    vector<int> nums;
    int num, target;
    while (cin >> num && num != '#') {
        nums.push_back(num);
    }
    cout << "Enter your target integer (enter # to end it):" << endl;
    while (cin >> target && target != '#') {
        ;
    }
    if (find(nums, target)) {
        cout << target << " is in your numbers." << endl;
    } else {
        cout << target << " is not in your numbers." << endl;
    }
    return 0;
}

bool find(vector<int> nums, int target) {
    auto beg = nums.begin(), end = nums.end();
    bool check = false;
    for (; beg != end; ++beg) {
        if (*beg == target) {
            check = true;
            return check;
        }
    }
    return check;
}