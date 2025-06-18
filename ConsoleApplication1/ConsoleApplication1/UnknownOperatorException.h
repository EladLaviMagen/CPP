#pragma once
#include <exception>
#include <string>
class UnknownOperatorException : public std::exception {
  private:
    std::string m_error;

  public:
    /*
    * C'tor for UnknownOperatorException
    * :Param error: The error that occured, should contain the operator attempted to perform action with
    */
    UnknownOperatorException(std::string& error);
    
    /*
     * Returns what was the error of the exception as a const char
     */
    const char* what() const noexcept override;
};
