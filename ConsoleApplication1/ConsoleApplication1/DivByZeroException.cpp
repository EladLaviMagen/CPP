#include "DivByZeroException.h"


DivByZeroException::DivByZeroException() {
    m_error = ERROR_STRING;
}


const char* DivByZeroException::what() const noexcept {
    return m_error.c_str();
}