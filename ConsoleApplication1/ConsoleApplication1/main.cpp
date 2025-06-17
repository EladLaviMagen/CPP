#include <iostream>
#include <string>



std::string pad(int number);

int main() {
    for (int i = 1; i <= 11; i++) {
        for (int j = 1; j <= 11; j++) {
            std::cout << i * j << pad(i * j);
        }
        std::cout << std::endl;
    }
}

std::string pad(int number) {
    std::string spaces = "";
    while (number != 0) {
        number /= 10;
        spaces[spaces.length() - 1] = '\0';
    }
    return spaces;
}
