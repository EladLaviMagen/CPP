#include <iostream>
#include <iomanip>

#define SPACE " "
#define MAX_PAD 5
#define BOARD_SIZE 11

int main() {
    for (int i = 1; i <= BOARD_SIZE; i++) {
        for (int j = 1; j <= BOARD_SIZE; j++) {
            std::cout << std::setw(MAX_PAD) << i * j;
        }
        std::cout << std::endl;
    }
    return 0;
}
