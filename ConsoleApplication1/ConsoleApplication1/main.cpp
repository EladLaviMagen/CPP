#include <iostream>

#define SPACE " "
#define MAX_PAD 5

void pad(int number);

int main() {
    for (int i = 1; i <= 11; i++) {
        for (int j = 1; j <= 11; j++) {
            std::cout << i * j;
            pad(i * j);
        }
        std::cout << std::endl;
    }
    return 0;
}

///IMPORTANT NOTE, THIS FUNCTION IS FOR VISUAL PURPOSES ALONE
/*
* Outputs spaces to cout to provide padding inbetween outputs for better visual output
* :Param number: number to be printed
* :Return: None
*/
void pad(int number) {
    std::string spaces = "";
    int numberLength = 0;
    //Calculating length of number
    while (number != 0) {
        number /= 10;
        numberLength++;
    }
    //Outputting the proper amount of padding spaces based on number length
    for (int i = 0; i < MAX_PAD - numberLength; i++) {
        std::cout << SPACE;
    }
}
