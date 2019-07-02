#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::cout << "Enter a string of chars (# to quit): " << std::endl; //endl自带换行符(endline)，所以不用自己添加换行符
    std::string str;
    while (getline(std::cin, str) && str[0] != '#') {  //由于cin遇到空格就会停止，所以要读取完整的一行的数据好像得再加一条循环
        for (char &c : str) { //用char而不用auto会怎么样？(好像什么都不会发生？)
            if (isalnum(c))
                c = 'X';
        }
        std::cout << str << std::endl;
        std::cout << "Enter the next string: " << std::endl; 
    }
    std::cout << "Done." << std::endl;
    return 0;
}