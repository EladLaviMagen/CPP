#pragma once

#include <Windows.h>
#include "AnotherInstanceRunningException.h"

class MutexLock
{
public:
	MutexLock(LPCSTR name);
	~MutexLock();
private:
	HANDLE m_mutex;
};