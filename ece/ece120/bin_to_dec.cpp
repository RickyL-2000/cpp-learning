#include <iostream>
#include <string>
using namespace std;

const int PLACE = 8;

int main() {
    string str;
    cout << "unsigned or signed? enter u or s: ";
    cin >> str;
    if (str == "u") {
        cout << "Please enter a number: ";
        while (cin >> str && str != "q") {
            int dec = 0;
            for (size_t i = 0; i < str.length(); i++) {
                int d = str[i] == '1';
                dec *= 2;
                dec += d;
            }
            printf("decimal: %d\n", dec);
            cout << "Please enter a number: ";
        }
    } else {
        cout << "Please enter a number (default 8 places): ";
        while (cin >> str && str != "q") {
            char sign = str[0];
            char flag = sign == '1' ? '0' : '1';
            int dec = 0;
            for (size_t i = 1; i < str.length(); i++) {
                int d = str[i] == flag;
                dec *= 2;
                dec+= d;
            }
            if (sign == '1') {
                dec = -dec - 1;
            }
            printf("decimal: %d\n", dec);
            cout << "Please enter a number (default 8 places): ";
        }
    }
    return 0;
}