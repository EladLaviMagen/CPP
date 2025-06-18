#include <iostream>
#include "ComplexNumber.h"

int main()
{
    ComplexNumber first;
    ComplexNumber second(5, 2);
    std::cout << first << std::endl;
    first.setReal(1);
    first.setImg(3);
    std::cout << first << std::endl;
    std::cout << second << std::endl;

    std::cout << first * second;

    return 0;
}
