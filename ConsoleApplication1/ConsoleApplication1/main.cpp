#include <stdio.h>
#include "setup.h"
#include "MutexLock.h"

#define MUTEX_NAME "mutex_single_program"
#define MESSAGE "MANAGEMENT PROGRAM IS UP"
#define SLEEP_TIME 3600000


void showMessageBox(LPCSTR text, LPCSTR title);

int main()
{   
    try 
    {
        MutexLock mutex(MUTEX_NAME);
        setupRegex();
        showMessageBox(MESSAGE, PROGRAM_NAME);
        Sleep(SLEEP_TIME);
    }
    catch (AnotherInstanceRunningException ex){
        printf("%s", ex.what());
    }
    catch (RegexException ex) {
        printf("%s", ex.what());
    }
    return 0;
}

/*
* A wrapper function for MessageBoxA
* :Param text: Text to be shown in the textbox
* :Param title: Title of textbox
*/
void showMessageBox(LPCSTR text, LPCSTR title) {
    MessageBoxA(NULL, text, title, MB_OK);
}
