#include <iostream>
int main()
{
    int currVal = 0, val = 0; //currVal是正在处理的数，val是下一个数
    if (std::cin >> currVal) {  // 读取第一个数，并确保确实有数据可以处理
        int cnt = 1;  //当前值的个数
        while (std::cin >> val) { //读取剩余的数
            if (val == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl; 
                currVal = val;  //将新值赋给currVal，与开头的if语句呼应
                cnt = 1; //重置计数器
            }
        }
        // NOTE 记住打印文件中最后一个值的个数
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
    }
    return 0;
}