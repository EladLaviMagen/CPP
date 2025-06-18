#include "DivByZeroException.h"


DivByZeroException::DivByZeroException() {
    m_error = DIV_BY_ZERO_ERROR_STRING;
}


const char* DivByZeroException::what() const noexcept {
    return m_error.c_str();
}