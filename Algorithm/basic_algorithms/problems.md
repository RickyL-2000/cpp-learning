# 疑难杂症

## bug

mergeSorting.cpp 不知道为什么，反正就是有bug

BUILD-MAX-HEAP.cpp  
这个问题感觉就很奇怪...跳到一个vector头文件并说有一个 Segmentation fault ？ 不是很懂... 一时半会儿还是先用<algorithm>里先成的函数吧...
感觉是 MAX_HEAPIFY 函数的问题，要不找个时间把迭代器全部改成下标吧

BUILD-MAX-HEAP(index).cpp
把上一个程序用下标重新写了一遍，以为是迭代器有某个地方搞错了，然而并不是这样...尽管没有再报错了，但是数组貌似没有被排序啊......