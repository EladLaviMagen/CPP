#pragma once
#include <exception>
#include <string>

#define ERROR_STRING "DIVISION BY 0 NOT ALLOWED"

class DivByZeroException : public std::exception {
  private:
    std::string m_error; 

  public:
    /*
    * C'tor for DivByZeroException, intializes m_error with the error message
    */
    DivByZeroException();
    
    /*
    * Returns what was the error of the exception as a const char
    */
    const char* what() const noexcept override;
};