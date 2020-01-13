#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "2";
    int i = *(s.begin()) - '1';
    cout << i << endl;
    return 0;
}