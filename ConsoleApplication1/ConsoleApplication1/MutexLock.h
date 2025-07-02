#pragma once

#include <Windows.h>
#include "AnotherInstanceRunningException.h"

class MutexLock
{
public:
	/*
	* C'tor for MutexLock
	* :Param name: Name of mutex
	*/
	MutexLock(LPCSTR name);
	~MutexLock();
private:
	HANDLE m_mutex;
};