#include <iostream>
#include <string>

int main() {
    for (int i = 0; i < 10; i++) {
        std::string s = std::to_string(i) + ".txt";
        printf("%s\n", s.c_str());
    }

    return 0;
}