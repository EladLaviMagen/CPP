#pragma once
#include <stdio.h>
#include "regKey.h"

const std::string SUBKEY = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
const std::string PROGRAM_NAME = "Management Program";

/*
* Gets the path of the running program
*/
std::string getPath();

/*
* Performs the regex setup if needed
*/
void setupRegex();
