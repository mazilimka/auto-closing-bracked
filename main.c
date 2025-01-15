#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

bool isEnglishLayout();
void insertParenthesis();
void insertQuotation();
void insertQurlyParenthesis();
void insertSquareParenthesis();
void insertSingleQuotes();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    while (1) {
        if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) && (GetAsyncKeyState('9') & 0x8000)) 
            insertParenthesis();
        if (isEnglishLayout()) {
            if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) && (GetAsyncKeyState(VK_OEM_7) & 0x8000))
                insertQuotation();
            if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) && (GetAsyncKeyState(VK_OEM_4) & 0x8000))
                insertQurlyParenthesis();
            if (GetAsyncKeyState(VK_OEM_4) & 0x8000) {
                insertSquareParenthesis();
            }
            if (GetAsyncKeyState(VK_OEM_7) & 0x8000)
                insertSingleQuotes();
        }
        Sleep(100);
    }
    return 0;
}

bool isEnglishLayout() {
    HKL layout = GetKeyboardLayout(0);
    LANGID langId = LOWORD(layout);
    DWORD layoutId = HIWORD(layout);
    return (layout == (HKL)0xfffffffff0c00409);
}

void insertQuotation() {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;

    input.ki.wVk = VK_SHIFT;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);

    input.ki.wVk = VK_OEM_7;
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);

    input.ki.wVk = VK_SHIFT;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);

    input.ki.wVk = VK_OEM_7;
    input.ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, &input, sizeof(INPUT));
    // Sleep(50);

    input.ki.wVk = VK_LEFT; 
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
}

void insertSingleQuotes() {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;

    input.ki.wVk = VK_OEM_7;
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);

    input.ki.wVk = VK_OEM_7;
    input.ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, &input, sizeof(INPUT));
    // Sleep(50);

    input.ki.wVk = VK_LEFT; 
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
}

void insertSquareParenthesis() {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;

    input.ki.wVk = VK_OEM_6;
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);

    input.ki.wVk = VK_OEM_6;
    input.ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, &input, sizeof(INPUT));
    // Sleep(50);

    input.ki.wVk = VK_LEFT; 
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
}

void insertQurlyParenthesis() {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;

    input.ki.wVk = VK_SHIFT;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);

    input.ki.wVk = VK_OEM_6;
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);

    input.ki.wVk = VK_SHIFT;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);

    input.ki.wVk = VK_OEM_6;
    input.ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, &input, sizeof(INPUT));
    // Sleep(50);

    input.ki.wVk = VK_LEFT; 
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
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