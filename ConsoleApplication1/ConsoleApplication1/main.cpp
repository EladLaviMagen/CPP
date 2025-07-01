#include <Windows.h>
#include <stdio.h>

#define MUTEX_NAME "mutex_single_program"
#define MESSAGE "MANAGEMENT PROGRAM IS UP"
#define PROGRAM_NAME "Management Program"

int main()
{   
    HANDLE mutex = CreateMutexA(NULL, TRUE, MUTEX_NAME);
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        printf("An instance is already running!");
        getchar();
        return 1;
    }
    MessageBoxA(NULL, MESSAGE, PROGRAM_NAME, MB_OK);
    Sleep(100);
    BOOL check = ReleaseMutex(mutex);
    check = CloseHandle(mutex);
    return 0;
}
