#include <iostream>


int main() {
    int number = -1;
    std::cout << "Please enter your number : ";
    std::cin >> number;
    if (number < 0) {
        std::cout << "INVALID INPUT";
        return 1;
    }
    std::cout << "G-Root : " << std::sqrt(number);
    return 0;
}

