#include <cctype>
#include <iostream>
#include <string>

bool isNumber(std::string str);

int main() {
    std::string number = "";
    std::cout << "Please enter your number : ";
    std::getline(std::cin, number);
    if (!isNumber(number)) {
        std::cout << "INVALID INPUT" << std::endl;
        return 1;
    }
    std::cout << "G-Root : " << std::sqrt(std::stoi(number));
    return 0;
}

/*
 * Checks if a string only has digits
 * :Param str: [IN] The string to check
 * :Return: True if string represents a number, false otherwise
 */
bool isNumber(std::string str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}
