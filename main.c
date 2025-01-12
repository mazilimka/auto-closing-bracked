#include <windows.h>
#include <stdio.h>
#include <stdbool.h>


int main() {
    HWND hwnd = GetForegroundWindow();

    if (hwnd == NULL) {
        printf("Foreground app is not exist\n");
        return 1;
    }
    // Sleep(2000);

    printf("Press '(' to insert parentheses... \n");
    while (1) {
        if (GetAsyncKeyState('(') & 0x8000) {
            break;
        }
        Sleep(50);
    }

    INPUT input = {0};
    input.type = INPUT_KEYBOARD;

    input.ki.wVk = VK_SHIFT;
    SendInput(1, &input, sizeof(INPUT));

    input.ki.wVk = '9';
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));

    // input.ki.dwFlags = KEYEVENTF_KEYUP; 
    // SendInput(1, &input, sizeof(INPUT));

    input.ki.wVk = VK_SHIFT; 
    SendInput(1, &input, sizeof(INPUT));

    input.ki.wVk = '0';
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));

    // input.ki.dwFlags = KEYEVENTF_KEYUP; 
    // SendInput(1, &input, sizeof(INPUT));

    input.ki.wVk = VK_SHIFT; 
    SendInput(1, &input, sizeof(INPUT));

    input.ki.wVk = VK_LEFT; 
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));

    // input.ki.dwFlags = KEYEVENTF_KEYUP; 
    // SendInput(1, &input, sizeof(INPUT));

    // printf("END\n");
    // main();
    return 0;
}
