#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string line;
    while (getline(cin,line))  
    //每次读入一整行，直至到达文件末尾(换行符或者结束符)
        cout << line <<endl; 
    //因为getline会把一行末尾的换行符删去，我们得手动地加上换行操作符
    //用endl结束当前行并刷新显示缓冲区
    return 0;
}