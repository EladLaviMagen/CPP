#pragma once
#include <stdio.h>
#include "regKey.h"

#define SUBKEY "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
#define PROGRAM_NAME "Management Program"

/*
* Gets the path of the running program
* :Param buffer: [OUT] buffer which path will be put into - max size is MAX_PATH
* :Param len: [IN] maximum size of buffer
*/
void getPath(char* buffer, int len);

/*
* Performs the regex setup if needed
*/
void setupRegex();
