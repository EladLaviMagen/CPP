#pragma once
#include "regutils.h"

class RegKey
{
public:
	/*
	* C'tor for RegKey
	* :Param subkey: subkey within the registry (Program works in HKEY_CURRENT_USER)
	* :Param access: desired access
	*/
	RegKey(LPCSTR subkey, REGSAM access);
	~RegKey();

	/*
	* Returns m_hkey
	*/
	HKEY getKey();
private:
	HKEY m_hkey;
};

