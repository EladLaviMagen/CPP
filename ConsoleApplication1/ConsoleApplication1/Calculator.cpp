#include "Calculator.h"


double Calculator::add(double firstNum, double secondNum) {
    return firstNum + secondNum;
}

double Calculator::subtruct(double firstNum, double secondNum) {
    return firstNum - secondNum;
}

double Calculator::multiply(double firstNum, double secondNum) {
    return firstNum * secondNum;
}

double Calculator::divide(double firstNum, double secondNum) {
    if (secondNum == 0) {
        throw DivByZeroException();
    }
    return firstNum / secondNum;
}

double Calculator::calculate(double firstNum, char action, double secondNum) {
    switch (action) {
    case ADD: {
        return add(firstNum, secondNum);
        break;
    }
    case SUBTRUCT: {
        return subtruct(firstNum, secondNum);
        break;
    }
    case MULTIPLY: {
        return multiply(firstNum, secondNum);
        break;
    }
    case DIVIDE: {
        return divide(firstNum, secondNum);
        break;
    }
    default: {
        std::string error = "Calculator has no implemetation for operator : ";
        error += action;
        throw UnknownOperatorException(error);
    }
    }
}
