#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s("Helloe World!!!");
    for (auto &c : s)
        //c是一个引用，因此赋值语句将改变s中字符的值
        c = toupper(c);
    cout << s << endl;
    return 0;
}