#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <random>
#include <windows.h>
#include <algorithm>
using namespace std;
string help  =  " A B C  D E F  G H I\n";
string board =  "[_|_|_][_|_|_][_|_|_]\n"
                "[_|_|_][_|_|_][_|_|_]\n"
                "[_|_|_][_|_|_][_|_|_]\n"
                "---------------------\n"
                "[_|_|_][_|_|_][_|_|_]\n"
                "[_|_|_][_|_|_][_|_|_]\n"
                "[_|_|_][_|_|_][_|_|_]\n"
                "---------------------\n"
                "[_|_|_][_|_|_][_|_|_]\n"
                "[_|_|_][_|_|_][_|_|_]\n"
                "[_|_|_][_|_|_][_|_|_]\n";
map<string, int> places = {
    {"A1",   1}, {"B1",   3}, {"C1",   5}, {"D1",   8}, {"E1",  10}, {"F1",  12}, {"G1",  15}, {"H1",  17}, {"I1",  19},
    {"A2",  23}, {"B2",  25}, {"C2",  27}, {"D2",  30}, {"E2",  32}, {"F2",  34}, {"G2",  37}, {"H2",  39}, {"I2",  41},
    {"A3",  45}, {"B3",  47}, {"C3",  49}, {"D3",  52}, {"E3",  54}, {"F3",  56}, {"G3",  59}, {"H3",  61}, {"I3",  63},

    {"A4",  89}, {"B4",  91}, {"C4",  93}, {"D4",  96}, {"E4",  98}, {"F4", 100}, {"G4", 103}, {"H4", 105}, {"I4", 107},
    {"A5", 111}, {"B5", 113}, {"C5", 115}, {"D5", 118}, {"E5", 120}, {"F5", 122}, {"G5", 125}, {"H5", 127}, {"I5", 129},
    {"A6", 133}, {"B6", 135}, {"C6", 137}, {"D6", 140}, {"E6", 142}, {"F6", 144}, {"G6", 147}, {"H6", 149}, {"I6", 151},

    {"A7", 177}, {"B7", 179}, {"C7", 181}, {"D7", 184}, {"E7", 186}, {"F7", 188}, {"G7", 191}, {"H7", 193}, {"I7", 195},
    {"A8", 199}, {"B8", 201}, {"C8", 203}, {"D8", 206}, {"E8", 208}, {"F8", 210}, {"G8", 213}, {"H8", 215}, {"I8", 217},
    {"A9", 221}, {"B9", 223}, {"C9", 225}, {"D9", 228}, {"E9", 230}, {"F9", 232}, {"G9", 235}, {"H9", 237}, {"I9", 239},
};
string place;

int turn = 1;
void player() {
    string play1;
    string play2;   
    if (turn == 1){
        cout << "\nPlayer X place: ";
        cin >> play1;
        if (places.find(play1) != places.end() && board[places[play1]] == '_') {
            board[places[play1]] = 'X';
            turn = 0;
        } else {
            cout << "Invalid move, try again.\n";
            player();
        }
    }else if (turn == 0){
        cout << "\nPlayer O place: ";
        cin >> play2;
        if (places.find(play2) != places.end() && board[places[play2]] == '_') {
            board[places[play2]] = 'O';
            turn = 1;
        } else {
            cout << "Invalid move, try again.\n";
            player();
        }
    }
}
char biga1;
void biga1x(){
    board[places["A1"]] = '\\';
    board[places["B1"]] = ' ';
    board[places["C1"]] = '/';
    board[places["A2"]] = ' ';
    board[places["B2"]] = 'X';
    board[places["C2"]] = ' ';
    board[places["A3"]] = '/';
    board[places["B3"]] = ' ';
    board[places["C3"]] = '\\';
    biga1 = 'X';
}
char biga2;
void biga2x(){
    board[places["A4"]] = '\\';
    board[places["B4"]] = ' ';
    board[places["C4"]] = '/';
    board[places["A5"]] = ' ';
    board[places["B5"]] = 'X';
    board[places["C5"]] = ' ';
    board[places["A6"]] = '/';
    board[places["B6"]] = ' ';
    board[places["C6"]] = '\\';
    biga2 = 'X';
}
char biga3;
void biga3x(){
    board[places["A7"]] = '\\';
    board[places["B7"]] = ' ';
    board[places["C7"]] = '/';
    board[places["A8"]] = ' ';
    board[places["B8"]] = 'X';
    board[places["C8"]] = ' ';
    board[places["A9"]] = '/';
    board[places["B9"]] = ' ';
    board[places["C9"]] = '\\';
    biga3 = 'X';
}
char bigb1;
void bigb1x(){
    board[places["D1"]] = '\\';
    board[places["E1"]] = ' ';
    board[places["F1"]] = '/';
    board[places["D2"]] = ' ';
    board[places["E2"]] = 'X';
    board[places["F2"]] = ' ';
    board[places["D3"]] = '/';
    board[places["E3"]] = ' ';
    board[places["F3"]] = '\\';
    bigb1 = 'X';
}
char bigb2;
void bigb2x(){
    board[places["D4"]] = '\\';
    board[places["E4"]] = ' ';
    board[places["F4"]] = '/';
    board[places["D5"]] = ' ';
    board[places["E5"]] = 'X';
    board[places["F5"]] = ' ';
    board[places["D6"]] = '/';
    board[places["E6"]] = ' ';
    board[places["F6"]] = '\\';
    bigb2 = 'X';
}
void winspace(){
// BIG A1
    if (board[places["A1"]] == 'X' && board[places["B2"]] == 'X' && board[places["C3"]] == 'X'){
        biga1x();
    }else if (board[places["C1"]] == 'X' && board[places["B2"]] == 'X' && board[places["A3"]] == 'X'){
        biga1x();
    }
    else if (board[places["A1"]] == 'X' && board[places["A2"]] == 'X' && board[places["A3"]] == 'X'){
        biga1x();
    }else if (board[places["B1"]] == 'X' && board[places["B2"]] == 'X' && board[places["B3"]] == 'X'){
        biga1x();
    }else if (board[places["C1"]] == 'X' && board[places["C2"]] == 'X' && board[places["C3"]] == 'X'){
        biga1x();
    }
    else if (board[places["A1"]] == 'X' && board[places["B1"]] == 'X' && board[places["C1"]] == 'X'){
        biga1x();
    }else  if (board[places["A2"]] == 'X' && board[places["B2"]] == 'X' && board[places["C2"]] == 'X'){
        biga1x();
    }else if (board[places["A3"]] == 'X' && board[places["B3"]] == 'X' && board[places["C3"]] == 'X'){
        biga1x();
    }
// BIG A2
    if (board[places["A4"]] == 'X' && board[places["B5"]] == 'X' && board[places["C6"]] == 'X'){
        biga2x();
    }else if (board[places["C4"]] == 'X' && board[places["B5"]] == 'X' && board[places["A6"]] == 'X'){
        biga2x();
    }
    else if (board[places["A4"]] == 'X' && board[places["A5"]] == 'X' && board[places["A6"]] == 'X'){
        biga2x();
    }else if (board[places["B4"]] == 'X' && board[places["B5"]] == 'X' && board[places["B6"]] == 'X'){
        biga2x();
    }else if (board[places["C4"]] == 'X' && board[places["C5"]] == 'X' && board[places["C6"]] == 'X'){
        biga2x();
    }
    else if (board[places["A4"]] == 'X' && board[places["B4"]] == 'X' && board[places["C4"]] == 'X'){
        biga2x();
    }else  if (board[places["A5"]] == 'X' && board[places["B5"]] == 'X' && board[places["C5"]] == 'X'){
        biga2x();
    }else if (board[places["A6"]] == 'X' && board[places["B6"]] == 'X' && board[places["C6"]] == 'X'){
        biga2x();
    }
// BIG A3
    if (board[places["A7"]] == 'X' && board[places["B8"]] == 'X' && board[places["C9"]] == 'X'){
        biga3x();
    }else if (board[places["C7"]] == 'X' && board[places["B8"]] == 'X' && board[places["A9"]] == 'X'){
        biga3x();
    }
    else if (board[places["A7"]] == 'X' && board[places["A8"]] == 'X' && board[places["A9"]] == 'X'){
        biga3x();
    }else if (board[places["B7"]] == 'X' && board[places["B8"]] == 'X' && board[places["B9"]] == 'X'){
        biga3x();
    }else if (board[places["C7"]] == 'X' && board[places["C8"]] == 'X' && board[places["C9"]] == 'X'){
        biga3x();
    }
    else if (board[places["A7"]] == 'X' && board[places["B7"]] == 'X' && board[places["C7"]] == 'X'){
        biga3x();
    }else  if (board[places["A8"]] == 'X' && board[places["B8"]] == 'X' && board[places["C8"]] == 'X'){
        biga3x();
    }else if (board[places["A9"]] == 'X' && board[places["B9"]] == 'X' && board[places["C9"]] == 'X'){
        biga3x();
    }
// BIG B1
    if (board[places["D1"]] == 'X' && board[places["E2"]] == 'X' && board[places["F3"]] == 'X'){
        bigb1x();
    }else if (board[places["F1"]] == 'X' && board[places["E2"]] == 'X' && board[places["D3"]] == 'X'){
        bigb1x();
    }
    else if (board[places["D1"]] == 'X' && board[places["D2"]] == 'X' && board[places["D3"]] == 'X'){
        bigb1x();
    }else if (board[places["E1"]] == 'X' && board[places["E2"]] == 'X' && board[places["E3"]] == 'X'){
        bigb1x();
    }else if (board[places["F1"]] == 'X' && board[places["F2"]] == 'X' && board[places["F3"]] == 'X'){
        bigb1x();
    }
    else if (board[places["D1"]] == 'X' && board[places["E1"]] == 'X' && board[places["F1"]] == 'X'){
        bigb1x();
    }else  if (board[places["D2"]] == 'X' && board[places["E2"]] == 'X' && board[places["F2"]] == 'X'){
        bigb1x();
    }else if (board[places["D3"]] == 'X' && board[places["E3"]] == 'X' && board[places["F3"]] == 'X'){
        bigb1x();
    }
// BIG B2
    if (board[places["D4"]] == 'X' && board[places["E5"]] == 'X' && board[places["F6"]] == 'X'){
        bigb2x();
    }else if (board[places["F4"]] == 'X' && board[places["E5"]] == 'X' && board[places["D6"]] == 'X'){
        bigb2x();
    }
    else if (board[places["D4"]] == 'X' && board[places["D5"]] == 'X' && board[places["D6"]] == 'X'){
        bigb2x();
    }else if (board[places["E4"]] == 'X' && board[places["E5"]] == 'X' && board[places["E6"]] == 'X'){
        bigb2x();
    }else if (board[places["F4"]] == 'X' && board[places["F5"]] == 'X' && board[places["F6"]] == 'X'){
        bigb2x();
    }
    else if (board[places["D4"]] == 'X' && board[places["E4"]] == 'X' && board[places["F4"]] == 'X'){
        bigb2x();
    }else  if (board[places["D5"]] == 'X' && board[places["E5"]] == 'X' && board[places["F5"]] == 'X'){
        bigb2x();
    }else if (board[places["D6"]] == 'X' && board[places["E6"]] == 'X' && board[places["F6"]] == 'X'){
        bigb2x();
    }
    
}

int main(){
    cout << help;
    cout << board;
    while(true){
        player();
        winspace();
        cout << help;
        cout << board;
    }
    
}