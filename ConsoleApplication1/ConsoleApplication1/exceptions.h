#pragma once
#include <exception>
#include <string>
#include <Windows.h>

const std::string ANOTHER_INSTANCE_ERROR_MESSAGE = "ANOTHER INSTANCE IS ALREADY RUNNING";
const std::string REGEX_ERROR_START = "Regex failed with code : ";
const std::string MUTEX_ERROR_START = "Mutex failed with code : ";
const std::string WSA_ERROR_START = "WSA failed with code : ";
const std::string WSA_STARTUP_FAILED = "WSA STARTUP FAILED";

class AnotherInstanceRunningException : std::exception {
public:
	AnotherInstanceRunningException() {
		m_error = ANOTHER_INSTANCE_ERROR_MESSAGE;
	}
	const char* what() const {
		return m_error.c_str();
	}
private:
	std::string m_error;
};


class RegexException : std::exception {
public:
	RegexException(LSTATUS err) {
		m_error = REGEX_ERROR_START + std::to_string(err);
	}
	const char* what() const {
		return m_error.c_str();
	}
private:
	std::string m_error;
};


class MutexException : std::exception {
public:
	MutexException(int err) {
		m_error = MUTEX_ERROR_START + std::to_string(err);
	}
	const char* what() const {
		return m_error.c_str();
	}
private:
	std::string m_error;
};


