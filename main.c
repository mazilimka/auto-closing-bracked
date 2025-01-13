#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

void insertParenthesis();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    while (1) {
        if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) && (GetAsyncKeyState('9') & 0x8000)) {
            insertParenthesis();
        }
        Sleep(100);
    }
    return 0;
}

void insertParenthesis() {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;

    input.ki.wVk = VK_SHIFT;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);

    input.ki.wVk = '0';
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);

    input.ki.wVk = VK_SHIFT;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);

    input.ki.wVk = '0';
    input.ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, &input, sizeof(INPUT));
    // Sleep(50);

    input.ki.wVk = VK_LEFT; 
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
}