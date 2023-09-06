#include <iostream>
#include <string>

int main() {
    std::string str1 = "";  // Using an empty string literal
    std::string str2;       // Using the default constructor

    if (str1.empty()) {
        std::cout << "str1 is an empty string." << std::endl;
    }

    if (str2.empty()) {
        std::cout << "str2 is an empty string." << std::endl;
    }

    return 0;
}
