#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    int mork;
    cout << "1 for left click\n0 for key of choice\n";
    cin >> mork;
    if (mork == 1){
        cout << "Left Alt to Click";
        while (true) {
            for (int keyCode = 0; keyCode < 256; ++keyCode) {
                if (GetAsyncKeyState(keyCode) & 0x8000) {
                    if (keyCode == 18){
                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                    }
                }
            }
            // Add a delay if you want
    }

    }
    if (mork == 0){
        char key;
        cout << "what key? !!!!!!CAPITALIZE!!!!!!\n";
        cin >> key;
        cout << "Press F8 for presses \n";
        while (true) {
            if (GetAsyncKeyState(VK_F8) & 0x8000) {  
                
                INPUT inputs[2] = {};
                ZeroMemory(inputs, sizeof(inputs));

                inputs[0].type = INPUT_KEYBOARD;
                inputs[0].ki.wVk = key;  

                inputs[1].type = INPUT_KEYBOARD;
                inputs[1].ki.wVk = key;
                inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; 

                UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
                if (uSent != ARRAYSIZE(inputs)) {
                    cout << "Error sending input.\n";
                } else {
                    continue;
                }
            }
        }
    }
    return 0;
}