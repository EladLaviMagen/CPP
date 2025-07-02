#pragma once
#include "exceptions.h"
#include <Windows.h>

class RegKey
{
public:
	/*
	* C'tor for RegKey
	* :Param subkey: subkey within the registry (Program works in HKEY_CURRENT_USER)
	* :Param access: desired access
	*/
	RegKey(const std::string valueName, REGSAM access);

	/*
	* Wrapper for RegGetValue - get value of an entry in the registry
	* :Param valueName: [IN] name of value within the key in the registry
	* :Param buffer: [OUT] buffer to hold the result in, max size is MAX_PATH, can be NULL if value itself isn't needed
	* :Param type: [OUT] type of data extracted, can be NULL if not required
	* :Param len: [IN/OUT] Pointer to dword holding the max length of param buffer, can be NULL only if buffer is NULL
	* :Return: LSTATUS result code, will be ERROR_SUCCESS on success and will be a different value upon error
	* (See getError function to get description of error from code)
	*/
	LSTATUS regGetVal(std::string valueName, std::string& buffer, LPDWORD type, LPDWORD len) const;

	/*
	* Wrapper function for RegSetValue - sets the value of an entry in the registry (can create entries too)
	* :Param valueName: [IN] name of value within the key in the registry
	* :Param value: [IN] value to insert
	*/
	void regSetVal(const std::string valueName, std::string value) const;

	~RegKey();

	/*
	* Returns m_hkey
	*/
	HKEY getKey();
private:
	HKEY m_hkey;
};

