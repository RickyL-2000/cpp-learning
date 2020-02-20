#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10e4 + 50;
int n;
int nums[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums + n);
    
}