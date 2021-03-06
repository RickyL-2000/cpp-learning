#include <iostream>
#include <vector>
using namespace std;

class DisjSet {
private:
    size_t maxsize;
    vector<int> parent;
public:
    DisjSet(int n) : maxsize(n), parent(vector<int>(maxsize)) {
        for (size_t i = 0; i < maxsize; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return parent[x] < 0 ? x : parent[x] = find(parent[x]);
    }

    bool merge(int x1, int x2) {
        if ((x1 = find(x1)) == (x2 = find(x2))) return false;
        if (parent[x1] < parent[x2]) {
            parent[x1] += parent[x2];
            parent[x2] = x1;
        } else {
            parent[x2] += parent[x1];
            parent[x1] = x2;
        }
        return true;
    }
};