#include "ComplexNumber.h"

ComplexNumber::ComplexNumber() {
    this->m_realVal = 0;
    this->m_imaginaryVal = 0;
}

ComplexNumber::ComplexNumber(double a, double b) {
    this->m_realVal = a;
    this->m_imaginaryVal = b;
}

double ComplexNumber::getReal() const {
    return this->m_realVal;
}

double ComplexNumber::getImg() const {
    return this->m_imaginaryVal;
}

void ComplexNumber::setReal(double value) {
    this->m_realVal = value;
}

void ComplexNumber::setImg(double value) {
    this->m_imaginaryVal = value;
}

bool ComplexNumber::operator==(const ComplexNumber& other) const {
    return this->getImg() == other.getImg() && this->getReal() == other.getReal();
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    return ComplexNumber(this->getReal() + other.getReal(), this->getImg() + other.getImg());
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    return ComplexNumber(this->getReal() - other.getReal(), this->getImg() - other.getImg());
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    double real = this->getReal() * other.getReal()
        //Subtructing this because i * i = -1
        - this->getImg() * other.getImg();
    double imaginary = this->getImg() * other.getReal()
        + this->getReal() * other.getImg();
    return ComplexNumber(real, imaginary);
}

std::ostream& operator<<(std::ostream& out, const ComplexNumber& number) {
    if (number.getImg() == 0) {
        return out << number.getReal();
    }
    else if (number.getReal() == 0) {
        return out << number.getImg() << "i";
    }
    return out << number.getReal() << " + " << number.getImg() << "i";
}