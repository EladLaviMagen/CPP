#include <stdio.h>
#include "setup.h"

#define MUTEX_NAME "mutex_single_program"
#define MESSAGE "MANAGEMENT PROGRAM IS UP"

int main()
{
    HANDLE mutex = checkMutex(MUTEX_NAME);
    if (mutex == NULL) {
        printf("Another instance is already running\n");
        getchar();
        return 1;
    }
    BOOL result = setupRegex();
    if (result == FALSE) {
        printf("There was an error setting up Regex entry\n");
        return 1;
    }
    MessageBoxA(NULL, MESSAGE, PROGRAM_NAME, MB_OK);
    Sleep(3600000);
    BOOL check = ReleaseMutex(mutex);
    check = CloseHandle(mutex);
    return 0;
}
