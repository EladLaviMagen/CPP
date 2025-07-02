#include "regutils.h"


LSTATUS regGetVal(HKEY hkey, LPCSTR valueName, char* buffer, LPDWORD type, LPDWORD len) {
	return RegGetValueA(hkey, NULL, valueName, RRF_RT_REG_SZ, type, buffer, len);
}


void regSetVal(HKEY hkey, LPCSTR valueName, char* value) {
	LSTATUS res = RegSetValueExA(hkey, valueName, 0, REG_SZ, (BYTE*)value, strlen(value) + 1);
    if (res != ERROR_SUCCESS) {
        throw RegexException(res);
    }
}


void getError(LSTATUS err, WCHAR* buffer) {
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, err, 0, buffer, MAX_PATH, NULL);
}