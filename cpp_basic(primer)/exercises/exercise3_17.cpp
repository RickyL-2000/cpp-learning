#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main()
{
    std::cout << "Enter a group of words: " << std::endl;
    std::vector<std::string> words;
    std::string word;
    while (std::cin >> word) {
        for (auto &ch : word) {
            if (isalpha(ch))
                ch = toupper(ch);
        }
        words.push_back(word);
    }
    for (int i = 0; i < words.size(); i++) {
        std::cout << words[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}