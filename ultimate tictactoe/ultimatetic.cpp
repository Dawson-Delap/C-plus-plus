#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <random>
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
void xwin(){
    while (true){
        cout << "X WINS";
    }
}
void owin(){
    while (true){
        cout << "O WINS";
    }
}
// BIG A
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
// BIG B
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
char bigb3;
void bigb3x(){
    board[places["D7"]] = '\\';
    board[places["E7"]] = ' ';
    board[places["F7"]] = '/';
    board[places["D8"]] = ' ';
    board[places["E8"]] = 'X';
    board[places["F8"]] = ' ';
    board[places["D9"]] = '/';
    board[places["E9"]] = ' ';
    board[places["F9"]] = '\\';
    bigb3 = 'X';
}
// BIG C
char bigc1;
void bigc1x(){
    board[places["G1"]] = '\\';
    board[places["H1"]] = ' ';
    board[places["I1"]] = '/';
    board[places["G2"]] = ' ';
    board[places["H2"]] = 'X';
    board[places["I2"]] = ' ';
    board[places["G3"]] = '/';
    board[places["H3"]] = ' ';
    board[places["I3"]] = '\\';
    bigc1 = 'X';
}
char bigc2;
void bigc2x(){
    board[places["G4"]] = '\\';
    board[places["H4"]] = ' ';
    board[places["I4"]] = '/';
    board[places["G5"]] = ' ';
    board[places["H5"]] = 'X';
    board[places["I5"]] = ' ';
    board[places["G6"]] = '/';
    board[places["H6"]] = ' ';
    board[places["I6"]] = '\\';
    bigc2 = 'X';
}
char bigc3;
void bigc3x(){
    board[places["G7"]] = '\\';
    board[places["H7"]] = ' ';
    board[places["I7"]] = '/';
    board[places["G8"]] = ' ';
    board[places["H8"]] = 'X';
    board[places["I8"]] = ' ';
    board[places["G9"]] = '/';
    board[places["H9"]] = ' ';
    board[places["I9"]] = '\\';
    bigc3 = 'X';
}
// BIG A
void biga1O(){
    board[places["A1"]] = '/';
    board[places["B1"]] = '-';
    board[places["C1"]] = '\\';
    board[places["A2"]] = '|';
    board[places["B2"]] = 'O';
    board[places["C2"]] = '|';
    board[places["A3"]] = '\\';
    board[places["B3"]] = '-';
    board[places["C3"]] = '/';
    biga1 = 'O';
}
void biga2O(){
    board[places["A4"]] = '/';
    board[places["B4"]] = '-';
    board[places["C4"]] = '\\';
    board[places["A5"]] = '|';
    board[places["B5"]] = 'O';
    board[places["C5"]] = '|';
    board[places["A6"]] = '\\';
    board[places["B6"]] = '-';
    board[places["C6"]] = '/';
    biga2 = 'O';
}
void biga3O(){
    board[places["A7"]] = '/';
    board[places["B7"]] = '-';
    board[places["C7"]] = '\\';
    board[places["A8"]] = '|';
    board[places["B8"]] = 'O';
    board[places["C8"]] = '|';
    board[places["A9"]] = '\\';
    board[places["B9"]] = '-';
    board[places["C9"]] = '/';
    biga3 = 'O';
}
// BIG B
void bigb1O(){
    board[places["D1"]] = '/';
    board[places["E1"]] = '-';
    board[places["F1"]] = '\\';
    board[places["D2"]] = '|';
    board[places["E2"]] = 'O';
    board[places["F2"]] = '|';
    board[places["D3"]] = '\\';
    board[places["E3"]] = '-';
    board[places["F3"]] = '/';
    bigb1 = 'O';
}
void bigb2O(){
    board[places["D4"]] = '/';
    board[places["E4"]] = '-';
    board[places["F4"]] = '\\';
    board[places["D5"]] = '|';
    board[places["E5"]] = 'O';
    board[places["F5"]] = '|';
    board[places["D6"]] = '\\';
    board[places["E6"]] = '-';
    board[places["F6"]] = '/';
    bigb2 = 'O';
}
void bigb3O(){
    board[places["D7"]] = '/';
    board[places["E7"]] = '-';
    board[places["F7"]] = '\\';
    board[places["D8"]] = '|';
    board[places["E8"]] = 'O';
    board[places["F8"]] = '|';
    board[places["D9"]] = '\\';
    board[places["E9"]] = '-';
    board[places["F9"]] = '/';
    bigb3 = 'O';
}
// BIG C
void bigc1O(){
    board[places["G1"]] = '/';
    board[places["H1"]] = '-';
    board[places["I1"]] = '\\';
    board[places["G2"]] = '|';
    board[places["H2"]] = 'O';
    board[places["I2"]] = '|';
    board[places["G3"]] = '\\';
    board[places["H3"]] = '-';
    board[places["I3"]] = '/';
    bigc1 = 'O';
}
void bigc2O(){
    board[places["G4"]] = '/';
    board[places["H4"]] = '-';
    board[places["I4"]] = '\\';
    board[places["G5"]] = '|';
    board[places["H5"]] = 'O';
    board[places["I5"]] = '|';
    board[places["G6"]] = '\\';
    board[places["H6"]] = '-';
    board[places["I6"]] = '/';
    bigc2 = 'O';
}
void bigc3O(){
    board[places["G7"]] = '/';
    board[places["H7"]] = '-';
    board[places["I7"]] = '\\';
    board[places["G8"]] = '|';
    board[places["H8"]] = 'O';
    board[places["I8"]] = '|';
    board[places["G9"]] = '\\';
    board[places["H9"]] = '-';
    board[places["I9"]] = '/';
    bigc3 = 'O';
}
void winspace(){
// BIG A1
    if (board[places["A1"]] == 'X' && board[places["B2"]] == 'X' && board[places["C3"]] == 'X'){
        biga1x();
    }else if (board[places["C1"]] == 'X' && board[places["B2"]] == 'X' && board[places["A3"]] == 'X'){
        biga1x();
    }
    else  if (board[places["A1"]] == 'X' && board[places["A2"]] == 'X' && board[places["A3"]] == 'X'){
        biga1x();
    }else if (board[places["B1"]] == 'X' && board[places["B2"]] == 'X' && board[places["B3"]] == 'X'){
        biga1x();
    }else if (board[places["C1"]] == 'X' && board[places["C2"]] == 'X' && board[places["C3"]] == 'X'){
        biga1x();
    }
    else  if (board[places["A1"]] == 'X' && board[places["B1"]] == 'X' && board[places["C1"]] == 'X'){
        biga1x();
    }else if (board[places["A2"]] == 'X' && board[places["B2"]] == 'X' && board[places["C2"]] == 'X'){
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
    else  if (board[places["A4"]] == 'X' && board[places["A5"]] == 'X' && board[places["A6"]] == 'X'){
        biga2x();
    }else if (board[places["B4"]] == 'X' && board[places["B5"]] == 'X' && board[places["B6"]] == 'X'){
        biga2x();
    }else if (board[places["C4"]] == 'X' && board[places["C5"]] == 'X' && board[places["C6"]] == 'X'){
        biga2x();
    }
    else  if (board[places["A4"]] == 'X' && board[places["B4"]] == 'X' && board[places["C4"]] == 'X'){
        biga2x();
    }else if (board[places["A5"]] == 'X' && board[places["B5"]] == 'X' && board[places["C5"]] == 'X'){
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
    else  if (board[places["A7"]] == 'X' && board[places["A8"]] == 'X' && board[places["A9"]] == 'X'){
        biga3x();
    }else if (board[places["B7"]] == 'X' && board[places["B8"]] == 'X' && board[places["B9"]] == 'X'){
        biga3x();
    }else if (board[places["C7"]] == 'X' && board[places["C8"]] == 'X' && board[places["C9"]] == 'X'){
        biga3x();
    }
    else  if (board[places["A7"]] == 'X' && board[places["B7"]] == 'X' && board[places["C7"]] == 'X'){
        biga3x();
    }else if (board[places["A8"]] == 'X' && board[places["B8"]] == 'X' && board[places["C8"]] == 'X'){
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
    else  if (board[places["D1"]] == 'X' && board[places["D2"]] == 'X' && board[places["D3"]] == 'X'){
        bigb1x();
    }else if (board[places["E1"]] == 'X' && board[places["E2"]] == 'X' && board[places["E3"]] == 'X'){
        bigb1x();
    }else if (board[places["F1"]] == 'X' && board[places["F2"]] == 'X' && board[places["F3"]] == 'X'){
        bigb1x();
    }
    else  if (board[places["D1"]] == 'X' && board[places["E1"]] == 'X' && board[places["F1"]] == 'X'){
        bigb1x();
    }else if (board[places["D2"]] == 'X' && board[places["E2"]] == 'X' && board[places["F2"]] == 'X'){
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
    else  if (board[places["D4"]] == 'X' && board[places["D5"]] == 'X' && board[places["D6"]] == 'X'){
        bigb2x();
    }else if (board[places["E4"]] == 'X' && board[places["E5"]] == 'X' && board[places["E6"]] == 'X'){
        bigb2x();
    }else if (board[places["F4"]] == 'X' && board[places["F5"]] == 'X' && board[places["F6"]] == 'X'){
        bigb2x();
    }
    else  if (board[places["D4"]] == 'X' && board[places["E4"]] == 'X' && board[places["F4"]] == 'X'){
        bigb2x();
    }else if (board[places["D5"]] == 'X' && board[places["E5"]] == 'X' && board[places["F5"]] == 'X'){
        bigb2x();
    }else if (board[places["D6"]] == 'X' && board[places["E6"]] == 'X' && board[places["F6"]] == 'X'){
        bigb2x();
    }
// BIG B3
    if (board[places["D7"]] == 'X' && board[places["E8"]] == 'X' && board[places["F9"]] == 'X'){
        bigb3x();
    }else if (board[places["F7"]] == 'X' && board[places["E8"]] == 'X' && board[places["D9"]] == 'X'){
        bigb3x();
    }
    else  if (board[places["D7"]] == 'X' && board[places["D8"]] == 'X' && board[places["D9"]] == 'X'){
        bigb3x();
    }else if (board[places["E7"]] == 'X' && board[places["E8"]] == 'X' && board[places["E9"]] == 'X'){
        bigb3x();
    }else if (board[places["F7"]] == 'X' && board[places["F8"]] == 'X' && board[places["F9"]] == 'X'){
        bigb3x();
    }
    else  if (board[places["D7"]] == 'X' && board[places["E7"]] == 'X' && board[places["F7"]] == 'X'){
        bigb3x();
    }else if (board[places["D8"]] == 'X' && board[places["E8"]] == 'X' && board[places["F8"]] == 'X'){
        bigb3x();
    }else if (board[places["D9"]] == 'X' && board[places["E9"]] == 'X' && board[places["F9"]] == 'X'){
        bigb3x();
    }
// BIG C1
    if (board[places["G1"]] == 'X' && board[places["H2"]] == 'X' && board[places["I3"]] == 'X'){
        bigc1x();
    }else if (board[places["I1"]] == 'X' && board[places["H2"]] == 'X' && board[places["G3"]] == 'X'){
        bigc1x();
    }
    else  if (board[places["G1"]] == 'X' && board[places["G2"]] == 'X' && board[places["G3"]] == 'X'){
        bigc1x();
    }else if (board[places["H1"]] == 'X' && board[places["H2"]] == 'X' && board[places["H3"]] == 'X'){
        bigc1x();
    }else if (board[places["I1"]] == 'X' && board[places["I2"]] == 'X' && board[places["I3"]] == 'X'){
        bigc1x();
    }
    else  if (board[places["G1"]] == 'X' && board[places["H1"]] == 'X' && board[places["I1"]] == 'X'){
        bigc1x();
    }else if (board[places["G2"]] == 'X' && board[places["H2"]] == 'X' && board[places["I2"]] == 'X'){
        bigc1x();
    }else if (board[places["G3"]] == 'X' && board[places["H3"]] == 'X' && board[places["I3"]] == 'X'){
        bigc1x();
    }
// BIG C2
    if (board[places["G4"]] == 'X' && board[places["H5"]] == 'X' && board[places["I6"]] == 'X'){
        bigc2x();
    }else if (board[places["I4"]] == 'X' && board[places["H5"]] == 'X' && board[places["G6"]] == 'X'){
        bigc2x();
    }
    else  if (board[places["G4"]] == 'X' && board[places["G5"]] == 'X' && board[places["G6"]] == 'X'){
        bigc2x();
    }else if (board[places["H4"]] == 'X' && board[places["H5"]] == 'X' && board[places["H6"]] == 'X'){
        bigc2x();
    }else if (board[places["I4"]] == 'X' && board[places["I5"]] == 'X' && board[places["I6"]] == 'X'){
        bigc2x();
    }
    else  if (board[places["G4"]] == 'X' && board[places["H4"]] == 'X' && board[places["I4"]] == 'X'){
        bigc2x();
    }else if (board[places["G5"]] == 'X' && board[places["H5"]] == 'X' && board[places["I5"]] == 'X'){
        bigc2x();
    }else if (board[places["G6"]] == 'X' && board[places["H6"]] == 'X' && board[places["I6"]] == 'X'){
        bigc2x();
    }
// BIG C3
    if (board[places["G7"]] == 'X' && board[places["H8"]] == 'X' && board[places["I9"]] == 'X'){
        bigc3x();
    }else if (board[places["I7"]] == 'X' && board[places["H8"]] == 'X' && board[places["G9"]] == 'X'){
        bigc3x();
    }
    else  if (board[places["G7"]] == 'X' && board[places["G8"]] == 'X' && board[places["G9"]] == 'X'){
        bigc3x();
    }else if (board[places["H7"]] == 'X' && board[places["H8"]] == 'X' && board[places["H9"]] == 'X'){
        bigc3x();
    }else if (board[places["I7"]] == 'X' && board[places["I8"]] == 'X' && board[places["I9"]] == 'X'){
        bigc3x();
    }
    else  if (board[places["G7"]] == 'X' && board[places["H7"]] == 'X' && board[places["I7"]] == 'X'){
        bigc3x();
    }else if (board[places["G8"]] == 'X' && board[places["H8"]] == 'X' && board[places["I8"]] == 'X'){
        bigc3x();
    }else if (board[places["G9"]] == 'X' && board[places["H9"]] == 'X' && board[places["I9"]] == 'X'){
        bigc3x();
    }
// BIG A1
    if (board[places["A1"]] == 'O' && board[places["B2"]] == 'O' && board[places["C3"]] == 'O'){
        biga1O();
    }else if (board[places["C1"]] == 'O' && board[places["B2"]] == 'O' && board[places["A3"]] == 'O'){
        biga1O();
    }
    else  if (board[places["A1"]] == 'O' && board[places["A2"]] == 'O' && board[places["A3"]] == 'O'){
        biga1O();
    }else if (board[places["B1"]] == 'O' && board[places["B2"]] == 'O' && board[places["B3"]] == 'O'){
        biga1O();
    }else if (board[places["C1"]] == 'O' && board[places["C2"]] == 'O' && board[places["C3"]] == 'O'){
        biga1O();
    }
    else  if (board[places["A1"]] == 'O' && board[places["B1"]] == 'O' && board[places["C1"]] == 'O'){
        biga1O();
    }else if (board[places["A2"]] == 'O' && board[places["B2"]] == 'O' && board[places["C2"]] == 'O'){
        biga1O();
    }else if (board[places["A3"]] == 'O' && board[places["B3"]] == 'O' && board[places["C3"]] == 'O'){
        biga1O();
    }
// BIG A2
    if (board[places["A4"]] == 'O' && board[places["B5"]] == 'O' && board[places["C6"]] == 'O'){
        biga2O();
    }else if (board[places["C4"]] == 'O' && board[places["B5"]] == 'O' && board[places["A6"]] == 'O'){
        biga2O();
    }
    else  if (board[places["A4"]] == 'O' && board[places["A5"]] == 'O' && board[places["A6"]] == 'O'){
        biga2O();
    }else if (board[places["B4"]] == 'O' && board[places["B5"]] == 'O' && board[places["B6"]] == 'O'){
        biga2O();
    }else if (board[places["C4"]] == 'O' && board[places["C5"]] == 'O' && board[places["C6"]] == 'O'){
        biga2O();
    }
    else  if (board[places["A4"]] == 'O' && board[places["B4"]] == 'O' && board[places["C4"]] == 'O'){
        biga2O();
    }else if (board[places["A5"]] == 'O' && board[places["B5"]] == 'O' && board[places["C5"]] == 'O'){
        biga2O();
    }else if (board[places["A6"]] == 'O' && board[places["B6"]] == 'O' && board[places["C6"]] == 'O'){
        biga2O();
    }
// BIG A3
    if (board[places["A7"]] == 'O' && board[places["B8"]] == 'O' && board[places["C9"]] == 'O'){
        biga3O();
    }else if (board[places["C7"]] == 'O' && board[places["B8"]] == 'O' && board[places["A9"]] == 'O'){
        biga3O();
    }
    else  if (board[places["A7"]] == 'O' && board[places["A8"]] == 'O' && board[places["A9"]] == 'O'){
        biga3O();
    }else if (board[places["B7"]] == 'O' && board[places["B8"]] == 'O' && board[places["B9"]] == 'O'){
        biga3O();
    }else if (board[places["C7"]] == 'O' && board[places["C8"]] == 'O' && board[places["C9"]] == 'O'){
        biga3O();
    }
    else  if (board[places["A7"]] == 'O' && board[places["B7"]] == 'O' && board[places["C7"]] == 'O'){
        biga3O();
    }else if (board[places["A8"]] == 'O' && board[places["B8"]] == 'O' && board[places["C8"]] == 'O'){
        biga3O();
    }else if (board[places["A9"]] == 'O' && board[places["B9"]] == 'O' && board[places["C9"]] == 'O'){
        biga3O();
    }
// BIG B1
    if (board[places["D1"]] == 'O' && board[places["E2"]] == 'O' && board[places["F3"]] == 'O'){
        bigb1O();
    }else if (board[places["F1"]] == 'O' && board[places["E2"]] == 'O' && board[places["D3"]] == 'O'){
        bigb1O();
    }
    else  if (board[places["D1"]] == 'O' && board[places["D2"]] == 'O' && board[places["D3"]] == 'O'){
        bigb1O();
    }else if (board[places["E1"]] == 'O' && board[places["E2"]] == 'O' && board[places["E3"]] == 'O'){
        bigb1O();
    }else if (board[places["F1"]] == 'O' && board[places["F2"]] == 'O' && board[places["F3"]] == 'O'){
        bigb1O();
    }
    else  if (board[places["D1"]] == 'O' && board[places["E1"]] == 'O' && board[places["F1"]] == 'O'){
        bigb1O();
    }else if (board[places["D2"]] == 'O' && board[places["E2"]] == 'O' && board[places["F2"]] == 'O'){
        bigb1O();
    }else if (board[places["D3"]] == 'O' && board[places["E3"]] == 'O' && board[places["F3"]] == 'O'){
        bigb1O();
    }
// BIG B2
    if (board[places["D4"]] == 'O' && board[places["E5"]] == 'O' && board[places["F6"]] == 'O'){
        bigb2O();
    }else if (board[places["F4"]] == 'O' && board[places["E5"]] == 'O' && board[places["D6"]] == 'O'){
        bigb2O();
    }
    else  if (board[places["D4"]] == 'O' && board[places["D5"]] == 'O' && board[places["D6"]] == 'O'){
        bigb2O();
    }else if (board[places["E4"]] == 'O' && board[places["E5"]] == 'O' && board[places["E6"]] == 'O'){
        bigb2O();
    }else if (board[places["F4"]] == 'O' && board[places["F5"]] == 'O' && board[places["F6"]] == 'O'){
        bigb2O();
    }
    else  if (board[places["D4"]] == 'O' && board[places["E4"]] == 'O' && board[places["F4"]] == 'O'){
        bigb2O();
    }else if (board[places["D5"]] == 'O' && board[places["E5"]] == 'O' && board[places["F5"]] == 'O'){
        bigb2O();
    }else if (board[places["D6"]] == 'O' && board[places["E6"]] == 'O' && board[places["F6"]] == 'O'){
        bigb2O();
    }
// BIG B3
    if (board[places["D7"]] == 'O' && board[places["E8"]] == 'O' && board[places["F9"]] == 'O'){
        bigb3O();
    }else if (board[places["F7"]] == 'O' && board[places["E8"]] == 'O' && board[places["D9"]] == 'O'){
        bigb3O();
    }
    else  if (board[places["D7"]] == 'O' && board[places["D8"]] == 'O' && board[places["D9"]] == 'O'){
        bigb3O();
    }else if (board[places["E7"]] == 'O' && board[places["E8"]] == 'O' && board[places["E9"]] == 'O'){
        bigb3O();
    }else if (board[places["F7"]] == 'O' && board[places["F8"]] == 'O' && board[places["F9"]] == 'O'){
        bigb3O();
    }
    else  if (board[places["D7"]] == 'O' && board[places["E7"]] == 'O' && board[places["F7"]] == 'O'){
        bigb3O();
    }else if (board[places["D8"]] == 'O' && board[places["E8"]] == 'O' && board[places["F8"]] == 'O'){
        bigb3O();
    }else if (board[places["D9"]] == 'O' && board[places["E9"]] == 'O' && board[places["F9"]] == 'O'){
        bigb3O();
    }
// BIG C1
    if (board[places["G1"]] == 'O' && board[places["H2"]] == 'O' && board[places["I3"]] == 'O'){
        bigc1O();
    }else if (board[places["I1"]] == 'O' && board[places["H2"]] == 'O' && board[places["G3"]] == 'O'){
        bigc1O();
    }
    else  if (board[places["G1"]] == 'O' && board[places["G2"]] == 'O' && board[places["G3"]] == 'O'){
        bigc1O();
    }else if (board[places["H1"]] == 'O' && board[places["H2"]] == 'O' && board[places["H3"]] == 'O'){
        bigc1O();
    }else if (board[places["I1"]] == 'O' && board[places["I2"]] == 'O' && board[places["I3"]] == 'O'){
        bigc1O();
    }
    else  if (board[places["G1"]] == 'O' && board[places["H1"]] == 'O' && board[places["I1"]] == 'O'){
        bigc1O();
    }else if (board[places["G2"]] == 'O' && board[places["H2"]] == 'O' && board[places["I2"]] == 'O'){
        bigc1O();
    }else if (board[places["G3"]] == 'O' && board[places["H3"]] == 'O' && board[places["I3"]] == 'O'){
        bigc1O();
    }
// BIG C2
    if (board[places["G4"]] == 'O' && board[places["H5"]] == 'O' && board[places["I6"]] == 'O'){
        bigc2O();
    }else if (board[places["I4"]] == 'O' && board[places["H5"]] == 'O' && board[places["G6"]] == 'O'){
        bigc2O();
    }
    else  if (board[places["G4"]] == 'O' && board[places["G5"]] == 'O' && board[places["G6"]] == 'O'){
        bigc2O();
    }else if (board[places["H4"]] == 'O' && board[places["H5"]] == 'O' && board[places["H6"]] == 'O'){
        bigc2O();
    }else if (board[places["I4"]] == 'O' && board[places["I5"]] == 'O' && board[places["I6"]] == 'O'){
        bigc2O();
    }
    else  if (board[places["G4"]] == 'O' && board[places["H4"]] == 'O' && board[places["I4"]] == 'O'){
        bigc2O();
    }else if (board[places["G5"]] == 'O' && board[places["H5"]] == 'O' && board[places["I5"]] == 'O'){
        bigc2O();
    }else if (board[places["G6"]] == 'O' && board[places["H6"]] == 'O' && board[places["I6"]] == 'O'){
        bigc2O();
    }
// BIG C3
    if (board[places["G7"]] == 'O' && board[places["H8"]] == 'O' && board[places["I9"]] == 'O'){
        bigc3O();
    }else if (board[places["I7"]] == 'O' && board[places["H8"]] == 'O' && board[places["G9"]] == 'O'){
        bigc3O();
    }
    else  if (board[places["G7"]] == 'O' && board[places["G8"]] == 'O' && board[places["G9"]] == 'O'){
        bigc3O();
    }else if (board[places["H7"]] == 'O' && board[places["H8"]] == 'O' && board[places["H9"]] == 'O'){
        bigc3O();
    }else if (board[places["I7"]] == 'O' && board[places["I8"]] == 'O' && board[places["I9"]] == 'O'){
        bigc3O();
    }
    else  if (board[places["G7"]] == 'O' && board[places["H7"]] == 'O' && board[places["I7"]] == 'O'){
        bigc3O();
    }else if (board[places["G8"]] == 'O' && board[places["H8"]] == 'O' && board[places["I8"]] == 'O'){
        bigc3O();
    }else if (board[places["G9"]] == 'O' && board[places["H9"]] == 'O' && board[places["I9"]] == 'O'){
        bigc3O();
    }

//BIG BOARD WIN
    if (biga1 == 'X' && bigb2 == 'X' && bigc3 == 'X'){
        xwin();
    }else if (biga3 == 'X' && bigb2 == 'X' && bigc1 == 'X'){
        xwin();
    }else if (biga1 == 'X' && biga2 == 'X' && biga3 == 'X'){
        xwin();
    }else if (bigb1 == 'X' && bigb2 == 'X' && bigb3 == 'X'){
        xwin();
    }else if (bigc1 == 'X' && bigc2 == 'X' && bigc3 == 'X'){
        xwin();
    }else if (biga1 == 'X' && bigb1 == 'X' && bigc1 == 'X'){
        xwin();
    }else if (biga2 == 'X' && bigb2 == 'X' && bigc2 == 'X'){
        xwin();
    }else if (biga3 == 'X' && bigb3 == 'X' && bigc3 == 'X'){
        xwin();
    }

    if (biga1 == 'O' && bigb2 == 'O' && bigc3 == 'O'){
        owin();
    }else if (biga3 == 'O' && bigb2 == 'O' && bigc1 == 'O'){
        owin();
    }else if (biga1 == 'O' && biga2 == 'O' && biga3 == 'O'){
        owin();
    }else if (bigb1 == 'O' && bigb2 == 'O' && bigb3 == 'O'){
        owin();
    }else if (bigc1 == 'O' && bigc2 == 'O' && bigc3 == 'O'){
        owin();
    }else if (biga1 == 'O' && bigb1 == 'O' && bigc1 == 'O'){
        owin();
    }else if (biga2 == 'O' && bigb2 == 'O' && bigc2 == 'O'){
        owin();
    }else if (biga3 == 'O' && bigb3 == 'O' && bigc3 == 'O'){
        owin();
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