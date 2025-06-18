#include <iostream>
#include "ComplexNumber.h"

int main()
{
    ComplexNumber first;
    ComplexNumber second(5, 2);
    std::cout << first << std::endl;
    first.setReal(5);
    first.setImg(2);
    std::cout << first << std::endl;
    std::cout << second << std::endl;

    bool a = first == second;
    std::cout << a;

    return 0;
}
