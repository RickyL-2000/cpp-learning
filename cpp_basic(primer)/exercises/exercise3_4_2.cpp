#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Enter two strings:" << endl;
    string a, b;
    cin >> a >> b;
    if (a.size() == b.size())
        cout << "Equal Length" << endl;
    else
        if (a.size() > b.size())
            cout << a << endl;
        else
            cout << b << endl;
    return 0;
}