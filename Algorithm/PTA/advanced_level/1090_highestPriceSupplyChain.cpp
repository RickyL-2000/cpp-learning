#include <iostream>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;

const int MAXN = 10010;
int n, root, paths = 0, maxLevel;
double p, r;
int sup[MAXN], level[MAXN], tempLevel[MAXN];

int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    // fill(level, level + n, -1);
    r /= 100.0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &sup[i]);
        if (sup[i] < 0) root = i;
    }

    stack<int> stk;
    for (int i = 0; i < n; i++) {
        int index = i, temp;
        while (sup[index] != -1 && level[index] == 0) {
            stk.push(index);
            index = sup[index];
        }
        if (!stk.empty()) {
            temp = stk.top();
            stk.pop();
            level[temp] = sup[index] + 1;
        }
        while (!stk.empty()) {
            level[stk.top()] = level[temp] + 1;
            temp = stk.top();
            stk.pop();
        }
        if (level[temp] > maxLevel) {
            paths = 1;
            maxLevel = level[temp];
        }
        if (level[temp] == maxLevel) {
            paths++;
        }
    }

    printf("%.2lf %d", p * pow(1 + r, maxLevel - 1), paths);

    return 0;    
}