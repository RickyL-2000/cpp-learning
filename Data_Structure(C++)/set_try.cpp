#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    cout<<"set 的 size 值为 ："<<s.size()<<endl;
    cout<<"set 的 maxsize的值为 ："<<s.max_size()<<endl;
    cout<<"set 中的第一个元素是 ："<<*s.begin()<<endl;
    cout<<"set 中的最后一个元素是:"<<*s.end()<<endl;
    s.clear();
    if(s.empty())
    {
        cout<<"set 为空 ！！！"<<endl;
    }
    cout<<"set 的 size 值为 ："<<s.size()<<endl;
    cout<<"set 的 maxsize的值为 ："<<s.max_size()<<endl;
    return 0;
}