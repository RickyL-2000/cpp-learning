# 树

## 应用实例

### 二分查找

```
typedef struct LNode *List;
struct LNode {
    ElementType Element[MAXSIZE];
    int Length;
};
// 二分查找
int BinarySearch (List Tbl, ElementType K) {
    int left, right, mid, NotFound = -1;
    left = 1;
    right = Tbl->Length;
    while (left <= right) {
        mid = (left+right)/2;
        if (L < Tbl->Element[mid])      right = mid - 1;
        elseif (K > Tbl->Element[mid])  left = mid + 1;
        else                            return mid;
    }
    return NotFound;
}