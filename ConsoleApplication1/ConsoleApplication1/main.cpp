#include <iostream>
#include <iomanip>

#define SPACE " "
#define MAX_PAD 5
#define ELEVEN 11

int main() {
    for (int i = 1; i <= ELEVEN; i++) {
        for (int j = 1; j <= ELEVEN; j++) {
            std::cout << std::setw(5) << i * j;
        }
        std::cout << std::endl;
    }
    return 0;
}
