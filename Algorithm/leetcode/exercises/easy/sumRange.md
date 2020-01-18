# Range Sum Query - Immutable

## my solution 1    20/1/18     30 min

FAIL!

考虑到sumRange函数会被调用非常多次，就用了一个矩阵来缓存，结果堆溢出了...

```
int INF = 1000000000;

class NumArray {
public:
    vector<vector<int>> dp;

    NumArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            dp.push_back({});
            for (int j = i; j < nums.size(); j++) {
                if (j == i) dp[i].push_back(nums[j]);
                else {
                    dp[i].push_back(dp[i][j-1] + nums[j]);
                }
            }
        }
    }
    
    int sumRange(int i, int j) {
        return dp[i][j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```

## my solution 2    20/1/18