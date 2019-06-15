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
        if (!line.empty())
        //逻辑非运算符(!)
            if (line.size() > 80)
                cout << "Over Sized";
            else
                cout << line << endl; 
    return 0;
}