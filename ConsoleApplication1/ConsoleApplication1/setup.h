#pragma once
#include <Windows.h>
#include <stdio.h>

#define SUBKEY "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
#define PROGRAM_NAME "Management Program"

/*
* Function checks and retrieves mutex
* :Param mutexName: The name of the mutex to check
* :Return: HANDLE for mutex or NULL if already taken
*/
HANDLE checkMutex(const char* mutexName);

/*
* Shows what error occured in functionm
* :Param err: error code
*/
void showError(LSTATUS err);

/*
* Performs the regex setup if needed
* :Return: TRUE if setup was successful and program is set up properly in regex, FALSE otherwise
* (Error message will printed upon failure)
*/
BOOL setupRegex();
