#include <windows.h>
#include <stdio.h>
#include <stdbool.h>


int main() {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    while (1) {
        // Проверяем состояние клавиш '9' и 'Shift'
        if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) && (GetAsyncKeyState('9') & 0x8000)) {
            break;
        }
        Sleep(80);
    }

    //Отправляем нажатие '0' (закрывающая скобка)
    input.ki.wVk = '0';
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(100);

    // Отпускаем '0'
    input.ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);

    // Перемещаем курсор влево
    input.ki.wVk = VK_LEFT; 
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(100);
    
    main();
}