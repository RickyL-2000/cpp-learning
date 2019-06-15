#include <iostream>
int main()
{
    std::cout << "Please Enter Some Numbers: " << std::endl;
    int currval = 0, val = 0, counter = 0; 
    if (std::cin >> currval) {
        while (std::cin >> val) {
            if (val == currval)
                counter += 1;
        }
    }
}