#pragma once
#include <exception>
#include <string>

#define DIVBYZERO_ERROR_STRING "DIVISION BY 0 NOT ALLOWED"

class DivByZeroException : public std::exception {
  public:
    /*
     * C'tor for DivByZeroException, intializes m_error with the error message
     */
    DivByZeroException();

    /*
     * Returns what was the error of the exception as a const char
     */
    const char* what() const noexcept override;
  private:
    std::string m_error; 

};