#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::cout << "Enter a string of chars containing punctuations (# to quit):" << std::endl;
    std::string str;
    while (std::cin >> str && str[0] != '#') {
        std::string newStr;
        decltype(str.size()) i, newi = 0;
        for (i = 0; i < str.size(); i++) {
            std::cout << "This is turn " << i << std::endl; // debug
            if (isalnum(str[i])) {
                std::cout << "Now " << str[i] << " is a char" << std::endl; //debug
                newStr[newi] = str[i];
                std::cout << "Now the " << newi << " turn of newStr is " << newStr[newi] << std::endl; //debug
                std::cout << "Now newstr is " << newStr << std::endl;
                newi++;
            }
        }
        std::cout << newStr << std::endl;    //debug
        for (newi = 0; newi < newStr.size(); newi++)  //debug
            std::cout << newStr[newi] << std::endl;   //debug
        std::cout << "Enter the next string: " << std::endl;  //不知道为什么，就是无法输出正确的字符串 :(
    }
    std::cout << "Done." << std::endl;
    return 0;
}