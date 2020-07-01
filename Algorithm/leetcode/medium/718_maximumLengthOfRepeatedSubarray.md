# 718_maximumLengthOfRepeatedSubarray

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
 

Note:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


## my sol 1     20/7/1      20 min

FAIL

这个代码在本地是能跑成功的，但是在oj上不行。又是那个愚蠢的编译器预检查，说我溢出了。

明明是不会溢出的。

用的是二维dp方法。

> 718_maximumLengthOfRepeatedSubarray.cpp

``` C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1010][1010];

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        fill(dp[0], dp[0] + 1010 * 1010, 0);
        
        int m = A.size(), n =B.size();
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> A = {1,2,3,2,1}, B = {3,2,1,4,7};
    Solution s;
    cout << s.findLength(A, B) << endl;
    return 0;
}
```


