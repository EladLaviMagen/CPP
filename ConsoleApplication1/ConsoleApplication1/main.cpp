#include <iostream>
#include <stdio.h>
//#include "Communicator.h"
#include "setup.h"
#include "MutexLock.h"


const std::string MUTEX_NAME = "mutex_single_program";
const std::string MESSAGE = "MANAGEMENT PROGRAM IS UP";
const int SLEEP_TIME = 3600000;


void showMessageBox(std::string text, std::string title);

int main()
{   
    try 
    {
        MutexLock mutex(MUTEX_NAME);
        setupRegex();
        showMessageBox(MESSAGE, PROGRAM_NAME);
        Sleep(SLEEP_TIME);
    }
    catch (const AnotherInstanceRunningException ex ){
        std::cout << ex.what() << std::endl;
    }
    catch (const RegexException ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (const MutexException ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}

/*
* A wrapper function for MessageBoxA
* :Param text: Text to be shown in the textbox
* :Param title: Title of textbox
*/
void showMessageBox(std::string text, std::string title) {
    MessageBoxA(NULL, text.c_str(), title.c_str(), MB_OK);
}
