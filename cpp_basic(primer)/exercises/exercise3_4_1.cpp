#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Please Enter Two Strings:" << endl;
    string a, b;
    cin >> a >> b;
    if (a == b) 
        cout << "These two strings are the same." << endl;
    else
        if (a > b)
            cout << a;
        else
            cout << b;
    return 0;
}