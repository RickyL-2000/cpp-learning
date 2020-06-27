# 41_firstMissingPositive

## my sol 1     20/6/27     15 min

8 ms    54.43%

6.8 mb  100%

啊这，这道题居然是hard？不是用一个set两边遍历就完了吗？

虽然说这个算法可能不算通常意义上的O(n)...不过我觉得强行说O(n)也是可以的

``` C++
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int minval = INT_MAX;
        set<int> check;
        for (int num : nums) {
            // if (num > 0 && num < minval) {
            //     minval = num;
            // }
            check.insert(num);
        }
        // if (minval > 1) return 1;
        int ret = 1;
        while (check.find(ret) != check.end()) {
            ret++;
        }
        return ret;
    }
};

int main() {}
```

