#include "MutexLock.h"

MutexLock::MutexLock(std::string name) {
    m_mutex = CreateMutexA(NULL, TRUE, name.c_str());
    int res = GetLastError();  
    if (res == ERROR_ALREADY_EXISTS) {
        throw AnotherInstanceRunningException();
    }
    else if (m_mutex == NULL) {
        throw MutexException(res);
    }
    m_name = name;
}


MutexLock::~MutexLock() {
    ReleaseMutex(m_mutex);
    CloseHandle(m_mutex);
}
