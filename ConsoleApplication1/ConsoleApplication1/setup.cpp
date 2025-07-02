#include "setup.h"

std::string getPath() {
    std::string buffer;
    buffer.resize(MAX_PATH);
    GetModuleFileNameA(NULL, &(buffer[0]), MAX_PATH);
    return buffer;
}

void setupRegex() {
    RegKey key(SUBKEY, KEY_ALL_ACCESS);
    std::string path = getPath();
    std::string currentValue;
    DWORD type = REG_SZ;
    DWORD len = MAX_PATH;
    LSTATUS res = key.regGetVal(PROGRAM_NAME, currentValue, &type, &len);
    if (res == ERROR_FILE_NOT_FOUND || path != currentValue) {
        key.regSetVal(PROGRAM_NAME, path);
    }
}
    