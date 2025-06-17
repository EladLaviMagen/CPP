#include <iostream>

#define END 10

int main() {
    int number = 0;
    std::cout << "Please enter your number : ";
    std::cin >> number;
    if (number < 0 || std::cin.peek() != END) {
        std::cout << "INVALID INPUT";
        return 1;
    }
    std::cout << "G-Root : " << std::sqrt(number);
    return 0;
}

