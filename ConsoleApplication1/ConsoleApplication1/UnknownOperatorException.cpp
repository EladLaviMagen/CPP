#include "UnknownOperatorException.h"

UnknownOperatorException::UnknownOperatorException(std::string& error) {
    m_error = error;
}

// std::exception::what() returns a const char*, so we must as well
const char* UnknownOperatorException::what() const noexcept {
    return m_error.c_str();
}
