#include <iostream>
#include <string>


int main() {
    std::string numberStr = "";
    std::cout << "Please enter your number : ";
    std::cin >> numberStr;
    int number = std::atoi(numberStr.c_str());
    if (number < 0 || std::to_string(number) != numberStr) {
        std::cout << "INVALID INPUT";
        return 1;
    }
    std::cout << "G-Root : " << std::sqrt(number);
    return 0;
}

