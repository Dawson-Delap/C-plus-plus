#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <windows.h> 
#include <map>       
using namespace std;
string board;
map<string, int> places;
int total;
int turn;
void player() {
    string play1;
    string play2;   
    if (turn == 1){
        cout << "\nPlayer 1 place (a-c rows, 1-3 columns): ";
        cin >> play1;
        if (places.find(play1) != places.end() && board[places[play1]] == '_') {
            board[places[play1]] = 'X';
            turn = 0;
            total += 1;
        } else {
            cout << "Invalid move, try again.\n";
            player();
        }
    }else if (turn == 0){
        cout << "\nPlayer 2 place (a-c rows, 1-3 columns): ";
        cin >> play2;
        if (places.find(play2) != places.end() && board[places[play2]] == '_') {
            board[places[play2]] = 'O';
            turn = 1;
            total += 1;
        } else {
            cout << "Invalid move, try again.\n";
            player();
        }
    }
}
void win(string winner){
    cout << winner;
    if(GetAsyncKeyState(VK_BACK) & 0x8000){  
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
    }
}
int main() {
    board = "_|_|_\n_|_|_\n_|_|_"; // 0, 2, 4 for first row; 6, 8, 10 for second; 12, 14, 16 for third
    places = { {"a1", 0}, {"a2", 2}, {"a3", 4}, {"b1", 6}, {"b2", 8}, {"b3", 10}, {"c1", 12}, {"c2", 14}, {"c3", 16} };
    total = 0;
    turn = 1;
    cout << "Backspace to exit when game over\n";
    cout << board;
    while(true){
        if (board[0] == 'X' && board[2] == 'X' && board[4] == 'X'){
            win("Player 1 Wins!!!");
        }else if (board[6] == 'X' && board[8] == 'X' && board[10] == 'X'){
            win("Player 1 Wins!!!");
        }else if (board[12] == 'X' && board[14] == 'X' && board[16] == 'X'){
            win("Player 1 Wins!!!");
        }else if (board[0] == 'X' && board[6] == 'X' && board[12] == 'X'){
            win("Player 1 Wins!!!");
        }else if (board[2] == 'X' && board[8] == 'X' && board[14] == 'X'){
            win("Player 1 Wins!!!");
        }else if (board[4] == 'X' && board[10] == 'X' && board[16] == 'X'){
            win("Player 1 Wins!!!");
        }else if (board[0] == 'X' && board[8] == 'X' && board[16] == 'X'){
            win("Player 1 Wins!!!");
        }else if (board[4] == 'X' && board[8] == 'X' && board[12] == 'X'){
            win("Player 1 Wins!!!");
        }else if (board[0] == 'O' && board[2] == 'O' && board[4] == 'O'){
            win("Player 2 Wins!!!");
        }else if (board[6] == 'O' && board[8] == 'O' && board[10] == 'O'){
            win("Player 2 Wins!!!");
        }else if (board[12] == 'O' && board[14] == 'O' && board[16] == 'O'){
            win("Player 2 Wins!!!");
        }else if (board[0] == 'O' && board[6] == 'O' && board[12] == 'O'){
            win("Player 2 Wins!!!");
        }else if (board[2] == 'O' && board[8] == 'O' && board[14] == 'O'){
            win("Player 2 Wins!!!");
        }else if (board[4] == 'O' && board[10] == 'O' && board[16] == 'O'){
            win("Player 2 Wins!!!");
        }else if (board[0] == 'O' && board[8] == 'O' && board[16] == 'O'){
            win("Player 2 Wins!!!");
        }else if (board[4] == 'O' && board[8] == 'O' && board[12] == 'O'){
            win("Player 2 Wins!!!");
        }else if (total == 9){
            win("TIE!!");
        }else{
            player(); 
            cout << board;
        }
    }
    return 0;
}