#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    vector<string> NamesofLis = {"Alex", "John", "Tom"};
    map<string, vector<string>> families = {{"Li", NamesofLis}};

    //实现添加新的家庭
    vector<string> NamesofFans = {"Bruce", "George", "Ryan"};
    families["Fan"] = NamesofFans;

    //将新的家庭中的名字输出
    for (vector<string>::size_type i = 0; i < families["Fan"].size(); ++i) {
        cout << families["Fan"][i] << ' ';
    }
    cout << endl;

    //实现添加新的家庭成员
    families["Li"].push_back("Ricky");

    for (string name : families["Li"]) { //另一种遍历vector的方法
        cout << name << ' ';
    }
    cout << endl;


    return 0;
}