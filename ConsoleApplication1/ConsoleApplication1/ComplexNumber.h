#pragma once
#include <iostream>

class ComplexNumber {
  public:
    /*
    * Empty C'tor for ComplexNumber, initializes instance with value 0
    */
    ComplexNumber();

    /*
    * C'tor for ComplexNumber Initializes instance with value a + bi
    * :Param a: The real value
    * :Param b: The imaginary value
    */
    ComplexNumber(double a, double b);

    //Getters for real and imaginary values
    double getReal() const;
    double getImg() const;

    //Setters for real and imaginary values
    void setReal(double value);
    void setImg(double value);

    /*
    * Comparison operator for Complex number
    * :Param other: the number to compare to
    * :Return: True if values (real and imaginary) are equal, false otherwise
    */
    bool operator==(const ComplexNumber& other) const;

    /*
    * Output stream operator, allows for simpler printing of class and it's values
    * :Param out: Output stream
    * :Param number: Complex number to output
    */
    friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& number);

    /*
    * Addition operator for Complex Numbers
    * :Param other: The number to add
    * :Return: A new instance, with the value of the result of the addition
    */
    ComplexNumber operator+(const ComplexNumber& other) const;

    /*
     * Subtruction operator for Complex Numbers
     * :Param other: The number to subtruct
     * :Return: A new instance, with the value of the result of the subtruction
     */
    ComplexNumber operator-(const ComplexNumber& other) const;

    /*
     * Multiplication operator for Complex Numbers
     * :Param other: The number to multiply
     * :Return: A new instance, with the value of the result of the multiplication
     */
    ComplexNumber operator*(const ComplexNumber& other) const;

  private:
    double m_realVal;
    double m_imaginaryVal;
    
};
