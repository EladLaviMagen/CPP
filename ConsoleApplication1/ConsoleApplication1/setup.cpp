#include "setup.h"

void getPath(char* buffer, int len) {
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
}

void setupRegex() {
    RegKey key(SUBKEY, KEY_ALL_ACCESS);
    CHAR path[MAX_PATH];
    getPath(path, MAX_PATH);
    CHAR currentValue[MAX_PATH];
    CHAR name[MAX_PATH];
    DWORD type = REG_SZ;
    DWORD len = MAX_PATH;
    LSTATUS res = regGetVal(key.getKey(), PROGRAM_NAME, currentValue, &type, &len);
    if (res == ERROR_FILE_NOT_FOUND || strcmp(path, currentValue) != 0) {
        regSetVal(key.getKey(), PROGRAM_NAME, path);
    }
}
    