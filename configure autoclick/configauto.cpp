#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    cout << "Press Left Shift for clicks or presses.\n";

    while (true) {
        if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {  
            
            INPUT inputs[2] = {};
            ZeroMemory(inputs, sizeof(inputs));

            inputs[0].type = INPUT_KEYBOARD;
            inputs[0].ki.wVk = VK_CONTROL;  

            inputs[1].type = INPUT_KEYBOARD;
            inputs[1].ki.wVk = VK_CONTROL;
            inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; 

            UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
        }
    }

    return 0;
}