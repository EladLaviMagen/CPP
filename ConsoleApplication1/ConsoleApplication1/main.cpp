#include <iostream>
#include "Calculator.h"

#define EXIT 'E'
#define INPUT_END 10

int main()
{
    char action = ' ';
    double firstNumber = 0;
    double secondNumber = 0;
    do {
        std::cout << "Please enter your equation in this form : <FIRSTNUM> <OPERATOR> <SECONDNUM>" << std::endl;
        std::cout << "(Enter 'E' as <OPERATOR> to leave)" << std::endl;
        std::cin >> firstNumber >> action >> secondNumber;
        if (action != EXIT) {
            if (std::cin.peek() != INPUT_END) {
                std::cout << "Really pushing it now";
                return 1;
            }
            try {
                std::cout << "Result is : " << Calculator::calculate(firstNumber, action, secondNumber) << std::endl;
            }
            catch (DivByZeroException& error) {
                std::cout << error.what() << std::endl;
            }
            catch (UnknownOperatorException& error) {
                std::cout << error.what() << std::endl;
            }
        }
    } while (action != EXIT);
    std::cout << "Goodbye!" << std::endl;
    return 0;
}
