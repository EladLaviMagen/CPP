#pragma once

#include <Windows.h>
#include <stdio.h>
#include <exception>
#include <string>

/*
* Wrapper for RegGetValue - get value of an entry in the registry
* :Param hkey: [IN] hkey for the registry value, should be exact key, function doesn't get sub_key
* :Param valueName: [IN] name of value within the key in the registry
* :Param buffer: [OUT] buffer to hold the result in, max size is MAX_PATH, can be NULL if value itself isn't needed
* :Param type: [OUT] type of data extracted, can be NULL if not required
* :Param len: [IN/OUT] Pointer to dword holding the max length of param buffer, can be NULL only if buffer is NULL
* :Return: LSTATUS result code, will be ERROR_SUCCESS on success and will be a different value upon error 
* (See getError function to get description of error from code)
*/
LSTATUS regGetVal(HKEY hkey, LPCSTR valueName, char* buffer, LPDWORD type, LPDWORD len);

/*
* Wrapper function for RegSetValue - sets the value of an entry in the registry (can create entries too)
* :Param hkey: [IN] hkey for the registry value
* :Param valueName: [IN] name of value within the key in the registry
* :Param value: [IN] value to insert
*/
void regSetVal(HKEY hkey, LPCSTR valueName, char* value);

/*
* Gets the error description of a failed function and inputs it into pointer
* :Param err: [IN] the error code
* :Param buff: [OUT] the buffer to input the error description in - max buffer size is MAX_PATH
*/
void getError(LSTATUS err, WCHAR* buffer);


class RegexException : std::exception {
public:
	RegexException(LSTATUS err) {
		getError(err, m_error);
	}
	const char* what() {
		return (char*)m_error;
	}
private:
	WCHAR m_error[MAX_PATH];
};