#include "ComplexNumber.h"

ComplexNumber::ComplexNumber() {
    this->m_realVal = 0;
    this->m_imaginaryVal = 0;
}

ComplexNumber::ComplexNumber(double a, double b) {
    this->m_realVal = a;
    this->m_imaginaryVal = b;
}

ComplexNumber::~ComplexNumber() {
    this->m_realVal = 0;
    this->m_imaginaryVal = 0;
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
    return this->m_imaginaryVal == other.getImg() && this->m_realVal == other.getReal();
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    return ComplexNumber(this->m_realVal + other.getReal(), this->m_imaginaryVal + other.getImg());
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    return ComplexNumber(this->m_realVal - other.getReal(), this->m_imaginaryVal - other.getImg());
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    double real = this->m_realVal * other.getReal();
    //Subtructing this result from real because i * i = -1
    real -= this->m_imaginaryVal * other.getImg();
    double imaginary = this->m_imaginaryVal * other.getReal();
    imaginary += this->m_realVal * other.getImg();
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