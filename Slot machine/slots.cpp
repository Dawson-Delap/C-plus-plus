#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <windows.h> 
#include <map>  
#include <cstdlib>
#include <ctime>     

using namespace std;

const vector<int> opt = {'0','1','2','3','4','5','6','7','8','9'};
string board = "|*|*|*|\n| | | |\n|_|_|_|";

//slot1:9 slot2:11 slot3:13

int main() { 
    int money = 0;
    srand (time(NULL));
    int slot1 = rand() % 10; 
    int slot2 = rand() % 10;
    int slot3 = rand() % 10;
    board[9] = opt[slot1];
    board[11] = opt[slot2];
    board[13] = opt[slot3];
    if (board[9] == board[11] && board[11] == board[13]){
        money += 100;
    }
    cout << board << "\n";
    cout << "Money: " << money << "\n";
    system("pause");
    main();
}
