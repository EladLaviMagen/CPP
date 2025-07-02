#pragma once
#include <exception>
#include <string>

#define ANOTHER_INSTANCE_ERROR_MESSAGE "ANOTHER INSTANCE IS ALREADY RUNNING"

class AnotherInstanceRunningException : std::exception {
public:
	AnotherInstanceRunningException() {
		m_error = ANOTHER_INSTANCE_ERROR_MESSAGE;
	}
	const char* what() {
		return m_error.c_str();
	}
private:
	std::string m_error;
};
