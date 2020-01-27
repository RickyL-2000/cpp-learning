# Forwards on Weibo

## my sol 1     20/1/26     30 min

我真的是...

这个题目也太难读懂了好吧，花了三十分钟写完发现可能没有读懂题意，结果读了我快一个小时也没有看懂...

> forwardsOnWeibo.cpp

```
/**
 * 看起来是一道经典的dfs题 
 */
#include <iostream>
#include <algorithm>
using namespace std;
/**
 * edge[][] - matrix
 */

int edge[1010][1010];
bool visited[1010];
int num, levels;

int dfs(int index, int level) {
    int sum = 1;
    visited[index] = true;
    for (int i = 1; i <= num; i++) {
        if (visited[i] == false && edge[i][index] == 1 && level <= levels + 1) {
            sum += dfs(i, level+1);
        }
    }
    return sum;
}

int main() {
    scanf("%d %d", &num, &levels);
    for (int i = 1; i <= num; i++) {
        int m, t;   // t - the person that user[i] follows
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &t);
            edge[i][t] = 1;
        }
    }
    int k, ans;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int query;
        scanf("%d", &query);
        fill(visited+1, visited + num+1, false);
        ans = dfs(query, 0);
        printf("%d\n", ans);
    }

    return 0;
}
```

## ref sol 1

https://blog.csdn.net/qq_42815188/article/details/100834988

> forwardsOnWeibo2.cpp

现在没有条件使用纸笔，过几天再好好看看这道题！