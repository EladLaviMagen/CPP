#include "MutexLock.h"

MutexLock::MutexLock(LPCSTR name) {
    m_mutex = CreateMutexA(NULL, TRUE, name);
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        CloseHandle(m_mutex);
        throw AnotherInstanceRunningException();
    }

}

MutexLock::~MutexLock() {
    ReleaseMutex(m_mutex);
    CloseHandle(m_mutex);
}
