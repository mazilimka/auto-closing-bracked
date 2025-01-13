#include <windows.h>
#include <stdio.h>
#include <stdbool.h>


// int main() {
//     bool isPressed = false;
//     // KEYEVENTF_SCANCODE = true
//     HWND hwnd = GetForegroundWindow();

//     if (hwnd == NULL) {
//         printf("Foreground app is not exist\n");
//         return 1;
//     }

//     printf("Press '(' to insert parentheses... \n");
//     while (1) {
//         if (((GetAsyncKeyState('9') & 0x8000) && (GetAsyncKeyState(VK_SHIFT) & 0x8000))) {
//             isPressed = true;
//             break;
//         }
//         Sleep(100);
//     }
//     // if (isPressed == false)
//     //     main();
    
//     INPUT input = {0};
//     input.type = INPUT_KEYBOARD;

//     input.ki.wVk = VK_SHIFT;
//     SendInput(1, &input, sizeof(INPUT));

//     input.ki.wVk = '9';
//     input.ki.dwFlags = 0; 
//     SendInput(1, &input, sizeof(INPUT));

//     input.ki.wVk = VK_SHIFT;
//     input.ki.dwFlags = KEYEVENTF_KEYUP; 
//     SendInput(1, &input, sizeof(INPUT));

//     Sleep(50);

//     input.ki.wVk = VK_SHIFT; 
//     SendInput(1, &input, sizeof(INPUT));
//     Sleep(50);

//     input.ki.wVk = '0';
//     input.ki.dwFlags = 0; 
//     SendInput(1, &input, sizeof(INPUT));

//     Sleep(50);

//     // input.ki.wVk = VK_SHIFT;
//     // input.ki.dwFlags = KEYEVENTF_KEYUP; 
//     // SendInput(1, &input, sizeof(INPUT));

//     Sleep(50);
//     // input.ki.wVk = VK_SHIFT; 
//     // SendInput(1, &input, sizeof(INPUT));

//     input.ki.wVk = VK_LEFT; 
//     input.ki.dwFlags = 0; 
//     SendInput(1, &input, sizeof(INPUT));

//     Sleep(50);
//     // input.ki.dwFlags = KEYEVENTF_KEYUP; 
//     // SendInput(1, &input, sizeof(INPUT));

//     // printf("END\n");
//     isPressed = false;
//     main();
//     return 0;
// }

int main() {
    HWND hwnd = GetForegroundWindow();

    if (hwnd == NULL) {
        printf("Foreground app is not exist\n");
        return 1;
    }

    printf("Press '(' to insert parentheses... \n");
    while (1) {
        // Проверяем состояние клавиш '9' и 'Shift'
        if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) && (GetAsyncKeyState('9') & 0x8000)) {
            break;
        }
        Sleep(100);
    }

    // Создаем структуру INPUT для отправки событий ввода
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;

    // Отправляем нажатие '9' (открывающая скобка)
    input.ki.wVk = '9';
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50); // Задержка 50 мс

    // Отпускаем '9'
    input.ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50); // Задержка 50 мс

    // Отправляем нажатие '0' (закрывающая скобка)
    input.ki.wVk = '0';
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50); // Задержка 50 мс

    // Отпускаем '0'
    input.ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50); // Задержка 50 мс

    // Перемещаем курсор влево
    input.ki.wVk = VK_LEFT; 
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50); // Задержка 50 мс

    main();
}