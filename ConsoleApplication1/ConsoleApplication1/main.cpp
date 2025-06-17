#include <iostream>
#include <string>

#define SPACE " "

std::string pad(int number);

int main() {
    for (int i = 1; i <= 11; i++) {
        for (int j = 1; j <= 11; j++) {
            std::cout << i * j << pad(i * j);
        }
        std::cout << std::endl;
    }
    return 0;
}

std::string pad(int number) {
    std::string spaces = "";
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    for (int i = 0; i < 5 - count; i++) {
        spaces += " ";
    }
    return spaces;
}
