/* Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. 
For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; 
if K=4, you must output 4→3→2→1→5→6. */

/* Each input file contains one test case. 
For each case, the first line contains the Address of the first node, a positive N (≤10^
​5) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. 
The Address of a node is a 5-digit nonnegative integer, and NULL is represented by -1. */

/* Then N lines follow, each describes a node in the format:
    Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node. */

/* For each case, output the resulting ordered linked list. Each node occupies a line, 
 and is printed in the same format as in the input. */

#include <stdio.h>

// 链表结构
struct Node {
    int Address, Data, NextAddress;
    struct Node *Pre, *Next;
};
typedef struct Node *List;
// 输入的临时存储结构
typedef struct Node *Raw;
// 排序时的临时存储结构
typedef struct Node *Temp;

// 函数声明

// 主函数
int main() {
    int HeadAddress;
    scanf("%d ", &HeadAddress);
    if (HeadAddress == -1) {
        printf("-1"); // 检查表是否为空
        return 0;
    }

    int size, K;
    scanf("%d %d", &size, &K);

// TODO ...中间的函数...

    return 0;
}

// 读取Raw的函数，返回乱序的链表
List ReadRaw(int size) {
    Raw R = NULL, Rrear = NULL, Rnew = NULL;   // 乱序的
    // 把输入全部保存为乱序的链表
    for (; size > 0; --size) {
        Rnew = (Raw) malloc(sizeof (struct Node));
        scanf("%d %d %d", Rnew->Address, Rnew->Data, Rnew->NextAddress);
        if (R == NULL) {
            R = Rnew; 
            Rrear = R; 
            Rrear->Pre = NULL;
            Rrear->Next = NULL; 
        } else {
            Rrear->Next = Rnew;
            Rnew->Pre = Rrear;  // 建立双向联系
            Rnew->Next = NULL;
            Rrear = Rnew;
        }
    }
}

void Print(List L) {}  // TODO

List Reverse (Raw *R, int K, int HeadAddress, int size) {  // 表头：指针的指针
    Temp T = NULL, Trear = NULL;  // 存储 K 大小数据的临时链表
    Raw P_R = *R;  // 游走指针
    List L = NULL, Lrear = NULL;  // 用于返回的答案链表
    int cache = HeadAddress; // 用于存储上一个乱序结点的 NextAddress
    int check = 1, count = K;
    while (check) {
        P_R = *R;
        for (; P_R; P_R = P_R->Next) {
            if (cache == P_R->Address) {
                // 将元素从原乱序链表抽离 （只修改两边数据指向本元素的指针）
                if (P_R->Pre && P_R->Next) {
                    (P_R->Pre)->Next = P_R->Next;
                    (P_R->Next)->Pre = P_R->Pre;
                } else if (P_R->Pre == NULL) {  // 说明 P_R 此时指向乱序表的表头
                    *R = P_R->Next;  // 修改乱序表的表头位置
                    (*R)->Pre = NULL;
                } else if (P_R->Next == NULL) { // 说明 P_R 此时指向乱序表的表尾
                    (P_R->Pre)->Next = NULL;
                } else if (P_R->Pre == NULL && P_R->Next == NULL) {  // 说明只剩下本元素了
                    *R = NULL;
                }
                // 将排好序的 K 个数据*转移*到 T 里面
                if (T == NULL) {    // 寻找头结点
                    T = P_R;  // FIXME: 这里可能有内存申请的问题
                    Trear = T;
                    Trear->Pre = NULL;
                    Trear->Next = NULL;
                    cache = Trear->NextAddress;  // 更新 cache
                    break;
                } else {
                    P_R->Pre = Trear;
                    Trear->Next = P_R;  // 建立双向联系
                    Trear = P_R;
                    Trear->Next = NULL;
                    cache = Trear->NextAddress;  // 更新 cache
                    break;
                }
            }
        }
        --count;
        if (count == 0) {  // K 个数据到齐
            for (; Trear; Trear = Trear->Pre) { // 到最后，T自动变成 NULL
                if (L == NULL) {
                    L = Trear;  // FIXME: 这里可能有内存申请的问题
                    L->Pre = NULL;
                    L->Next = NULL;

                }
            }
            T = NULL;
        } else if (*R == NULL) {

        }
    }
}