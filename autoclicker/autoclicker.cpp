#include <iostream>
#include <windows.h>
using namespace std;
int main(){
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

    return 0;
}