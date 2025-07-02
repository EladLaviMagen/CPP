#include "regKey.h"

RegKey::RegKey(const std::string subkey, REGSAM access)
{
	m_hkey = HKEY_CURRENT_USER;
	LSTATUS res = RegOpenKeyExA(m_hkey, subkey.c_str(), 0, access, &m_hkey);
	if (res != ERROR_SUCCESS || m_hkey == NULL) {
		throw RegexException(res);
	}
}

LSTATUS RegKey::regGetVal(std::string valueName, std::string& buffer, LPDWORD type, LPDWORD len) const {
	buffer.resize(MAX_PATH);
	LSTATUS res = RegGetValueA(m_hkey, NULL, valueName.c_str(), RRF_RT_REG_SZ, type, &(buffer[0]), len);
	if (res != ERROR_FILE_NOT_FOUND && res != ERROR_SUCCESS) {
		throw RegexException(res);
	}
	return res;
}


void RegKey::regSetVal(std::string valueName, std::string value) const {
	LSTATUS res = RegSetValueExA(m_hkey, valueName.c_str(), 0, REG_SZ, (BYTE*)value.c_str(), value.length() + 1);
	if (res != ERROR_SUCCESS) {
		throw RegexException(res);
	}
}

RegKey::~RegKey()
{
	RegCloseKey(m_hkey);
}

HKEY RegKey::getKey()
{
	return m_hkey;
}
