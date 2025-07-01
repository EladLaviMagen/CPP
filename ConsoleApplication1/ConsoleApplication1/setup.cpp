#include "setup.h"

HANDLE checkMutex(const char* mutexName) {
    HANDLE mutex = CreateMutexA(NULL, TRUE, mutexName);
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        CloseHandle(mutex);
        return NULL;
    }
    return mutex;
}

void showError(LSTATUS err) {
    WCHAR buff[MAX_PATH];
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, err, 0, buff, MAX_PATH, NULL);
    printf("%s", buff);
}

BOOL setupRegex() {
    HKEY hkey = HKEY_CURRENT_USER;
    LSTATUS res = RegOpenKeyExA(hkey, SUBKEY, 0, KEY_ALL_ACCESS, &hkey);
    if (res != ERROR_SUCCESS || hkey == NULL) {
        showError(res);
        return FALSE;
    }
    CHAR path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    CHAR currentValue[MAX_PATH];
    CHAR name[MAX_PATH];
    DWORD type = REG_SZ;
    DWORD len = 260;
    res = RegGetValueA(hkey, NULL, PROGRAM_NAME, RRF_RT_REG_SZ, &type, currentValue, &len);
    if (res == ERROR_FILE_NOT_FOUND || strcmp(path, currentValue) != 0) {
        res = RegSetValueExA(hkey, PROGRAM_NAME, 0, REG_SZ, (BYTE*)path, strlen(path) + 1);
        if (res != ERROR_SUCCESS) {
            RegCloseKey(hkey);
            showError(res);
            return FALSE;
        }
    }
    RegCloseKey(hkey);
    return TRUE;
}
    