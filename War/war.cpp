#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <random>
#include <windows.h>
#include <algorithm>
using namespace std;

map<string, int> cards = {
    // clubs
    {"2 C",2}, {"3 C",3},{"4 C",4},{"5 C",5},{"6 C",6},{"7 C",7},{"8 C",8},{"9 C",9},{"10C",10},{"J C",10},{"Q C",10},{"K C",10},{"A C",11},
    // spades
    {"2 S",2},{"3 S", 3},{"4 S", 4},{"5 S", 5},{"6 S", 6},{"7 S", 7},{"8 S", 8},{"9 S", 9},{"10S", 10},{"J S", 10},{"Q S", 10},{"K S", 10},{"A S", 11},
    // diamonds
    {"2 D", 2},{"3 D", 3},{"4 D", 4},{"5 D", 5},{"6 D", 6},{"7 D", 7},{"8 D", 8},{"9 D", 9},{"10D", 10},{"J D", 10},{"Q D", 10},{"K D", 10},{"A D", 11},
    // hearts
    {"2 H", 2},{"3 H", 3},{"4 H", 4},{"5 H", 5},{"6 H", 6},{"7 H", 7},{"8 H", 8},{"9 H", 9},{"10H", 10},{"J H", 10},{"Q H", 10},{"K H", 10},{"A H", 11}
};

vector<string> cardsindex = {
    "2 C","3 C","4 C","5 C","6 C","7 C","8 C","9 C","10C","J C","Q C","K C","A C",
    "2 S","3 S","4 S","5 S","6 S","7 S","8 S","9 S","10S","J S","Q S","K S","A S",
    "2 D","3 D","4 D","5 D","6 D","7 D","8 D","9 D","10D","J D","Q D","K D","A D",
    "2 H","3 H","4 H","5 H","6 H","7 H","8 H","9 H","10H","J H","Q H","K H","A H"
};
int dealertot;
int playertot;
int infinite = 1;
string over;
int cont;
int inficheck = 1;
int main() {
    if (inficheck == 1){
    cout << "Infinite deck? 1=yes 0=no\n";
    cin >> infinite;
    inficheck = 0;
    main();
    }
    cout << "Space to continue Backspace to stop\n";
    if (cardsindex.size() > 0){
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist(0, cardsindex.size() - 1);
        string card1 = cardsindex[dist(rng)];
        string card2 = cardsindex[dist(rng)];


        string board = "-----\n|" + card1 + "|\n-----\n|" + card2 + "|\n-----";
        cout << board << endl;
        if (cards[card1] > cards[card2]){
            dealertot += 1;
        }else if (cards[card2] > cards[card1]){
            playertot += 1;
        }
        

        cout << "Dealer: " << " (Score: " << dealertot << ")\n";
        cout << "Player: " << " (Score: " << playertot << ")\n";
        if (infinite == 0){
            cardsindex.erase(find(cardsindex.begin(), cardsindex.end(), card1));
            cardsindex.erase(find(cardsindex.begin(), cardsindex.end(), card2));
        }
        cont = 1;
        while (cont == 1){
                    if (GetAsyncKeyState(VK_SPACE) & 0x8000){
                        cont = 0;
                        Sleep(100);
                        main();
                        
                    }else if(GetAsyncKeyState(VK_BACK) & 0x8000){
                        INPUT inputs[4] = {};
                        ZeroMemory(inputs, sizeof(inputs));
                        // key down
                        inputs[0].type = INPUT_KEYBOARD;
                        inputs[0].ki.wVk = VK_MENU;  // Virtual-Key Code

                        // key down
                        inputs[1].type = INPUT_KEYBOARD;
                        inputs[1].ki.wVk = VK_F4;  // Virtual-Key Code

                        // key up
                        inputs[2].type = INPUT_KEYBOARD;
                        inputs[2].ki.wVk = VK_F4;
                        inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;  // Mark as key release

                        // key up
                        inputs[3].type = INPUT_KEYBOARD;
                        inputs[3].ki.wVk = VK_MENU;
                        inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;  // Mark as key release

                        // Send the input events
                        UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
                        if (uSent != ARRAYSIZE(inputs)) {
                            cout << "Error sending input.\n";
                        } else {
                            // Debugging: Confirm that input was sent
                            cout << "Simulated key press" << endl;
                        }

                        // Add a small delay between events for better registration
                        Sleep(100);
                        cont = 0;
                    }
                
            
            
        }
    }
    while (infinite == 0){
        if (GetAsyncKeyState(VK_SPACE) & 0x8000){
                            cont = 0;
                            Sleep(100);
                            main();
                            
            }else if(GetAsyncKeyState(VK_BACK) & 0x8000){
                INPUT inputs[4] = {};
                ZeroMemory(inputs, sizeof(inputs));
                // key down
                inputs[0].type = INPUT_KEYBOARD;
                inputs[0].ki.wVk = VK_MENU;  // Virtual-Key Code

                // key down
                inputs[1].type = INPUT_KEYBOARD;
                inputs[1].ki.wVk = VK_F4;  // Virtual-Key Code

                // key up
                inputs[2].type = INPUT_KEYBOARD;
                inputs[2].ki.wVk = VK_F4;
                inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;  // Mark as key release

                // key up
                inputs[3].type = INPUT_KEYBOARD;
                inputs[3].ki.wVk = VK_MENU;
                inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;  // Mark as key release

                // Send the input events
                UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
                if (uSent != ARRAYSIZE(inputs)) {
                    cout << "Error sending input.\n";
                } else {
                    // Debugging: Confirm that input was sent
                    cout << "Simulated key press" << endl;
                }

                // Add a small delay between events for better registration
                Sleep(100);
                cont = 0;
            }
    }
    return 0;
}