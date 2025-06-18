#pragma once
#include "DivByZeroException.h"
#include "UnknownOperatorException.h"

#define ADD '+'
#define SUBTRUCT '-'
#define MULTIPLY '*'
#define DIVIDE ':'

class Calculator {
  public:
    /*
    * Adds 2 numbers
    * :Param firstNum: The first number
    * :Param secondNum: The second number
    * :Return: the result
    */
    static double add(double firstNum, double secondNum);

    /*
    * Subtructs 2 numbers
    * :Param firstNum: The first number - the one to subtruct from
    * :Param secondNum: The second number - the number being subtructed
    * :Return: the result
    */
    static double subtruct(double firstNum, double secondNum);

    /*
    * Multiply 2 numbers
    * :Param firstNum: The first number 
    * :Param secondNum: The second number
    * :Return: the result
    */
    static double multiply(double firstNum, double secondNum);

    /*
    * Divides 2 numbers
    * :Param firstNum: The first number - The dividend
    * :Param secondNum: The second number - The divisor
    * :Return: the result, DivByZeroException could be thrown if there is an attempt to divide by 0
    */
    static double divide(double firstNum, double secondNum);

    /*
    * Calculates <firstNum> <action> <secondNum> if possible
    * :Param firstNum: The first number 
    * :param action: action to perform
    * :Param secondNum: The second number
    * :Return: The result of the equation above, will throw exceptions if division by 0 attempted or an unknown operator entered
    */
    static double calculate(double firstNum, char action, double secondNum);
};
