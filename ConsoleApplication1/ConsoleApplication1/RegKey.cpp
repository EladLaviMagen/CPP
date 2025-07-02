#include "regKey.h"

RegKey::RegKey(LPCSTR subkey, REGSAM access)
{
	m_hkey = HKEY_CURRENT_USER;
	LSTATUS res = RegOpenKeyExA(m_hkey, subkey, 0, access, &m_hkey);
	if (res != ERROR_SUCCESS || m_hkey == NULL) {
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
