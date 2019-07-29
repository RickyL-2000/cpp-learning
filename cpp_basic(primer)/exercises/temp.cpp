#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums(10,1);
    for (auto i = nums.begin(); i != nums.end(); ++i) {
        cout << *i << endl;
    }
    return 0;
}