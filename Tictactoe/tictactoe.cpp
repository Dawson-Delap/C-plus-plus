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


int main() {
    
    board = "_|_|_\n_|_|_\n_|_|_"; // 0, 2, 4 for first row; 6, 8, 10 for second; 12, 14, 16 for third
    places = { {"a1", 0}, {"a2", 2}, {"a3", 4}, {"b1", 6}, {"b2", 8}, {"b3", 10}, {"c1", 12}, {"c2", 14}, {"c3", 16} };
    total = 0;
    turn = 1;
    cout << board;

    while (total < 9){
        if (board[0] == 'X' && board[2] == 'X' && board[4] == 'X'){
            cout << "Player 1 Wins!!!";
        }else 
        if (board[6] == 'X' && board[8] == 'X' && board[10] == 'X'){
            cout << "Player 1 Wins!!!";
        }else
        if (board[12] == 'X' && board[14] == 'X' && board[16] == 'X'){
            cout << "Player 1 Wins!!!";
        }else
        if (board[0] == 'X' && board[6] == 'X' && board[12] == 'X'){
            cout << "Player 1 Wins!!!";
        }else
        if (board[2] == 'X' && board[8] == 'X' && board[14] == 'X'){
            cout << "Player 1 Wins!!!";
        }else
        if (board[4] == 'X' && board[10] == 'X' && board[16] == 'X'){
            cout << "Player 1 Wins!!!";
        }else
        if (board[0] == 'X' && board[8] == 'X' && board[16] == 'X'){
            cout << "Player 1 Wins!!!";
        }else
        if (board[4] == 'X' && board[8] == 'X' && board[12] == 'X'){
            cout << "Player 1 Wins!!!";
        }else
        
        if (board[0] == 'O' && board[2] == 'O' && board[4] == 'O'){
            cout << "Player 2 Wins!!!";
        }else 
        if (board[6] == 'O' && board[8] == 'O' && board[10] == 'O'){
            cout << "Player 2 Wins!!!";
        }else
        if (board[12] == 'O' && board[14] == 'O' && board[16] == 'O'){
            cout << "Player 2 Wins!!!";
        }else
        if (board[0] == 'O' && board[6] == 'O' && board[12] == 'O'){
            cout << "Player 2 Wins!!!";
        }else
        if (board[2] == 'O' && board[8] == 'O' && board[14] == 'O'){
            cout << "Player 2 Wins!!!";
        }else
        if (board[4] == 'O' && board[10] == 'O' && board[16] == 'O'){
            cout << "Player 2 Wins!!!";
        }else
        if (board[0] == 'O' && board[8] == 'O' && board[16] == 'O'){
            cout << "Player 2 Wins!!!";
        }else
        if (board[4] == 'O' && board[8] == 'O' && board[12] == 'O'){
            cout << "Player 2 Wins!!!";
        }
        else{
        player(); 
        cout << board;
        }
        
    }
    cout << "\nTIE! \n";
    system("pause");
    return 0;
}
