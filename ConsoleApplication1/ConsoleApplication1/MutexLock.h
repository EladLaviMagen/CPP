#pragma once

#include <Windows.h>
#include "exceptions.h"
#include <string>

class MutexLock
{
public:
	/*
	* C'tor for MutexLock
	* :Param name: Name of mutex
	*/
	MutexLock(std::string name);
	
	/*
	* Copy constructor - will give restricted accesss handle to the mutex object
	* :Param other: MutexLock to copy
	*/
	~MutexLock();
private:
	MutexLock(const MutexLock& other);
	HANDLE m_mutex;
	std::string m_name;
};