#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>  
#include <cstdlib>
#include <ctime> 
#include <random> 
#include <thread>
#include <chrono>
#include <ctime>   
using namespace std;

char opt[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string board = "|*|*|*|\n| | | |\n|_|_|_|";
int money = 0;
//slot1:9 slot2:11 slot3:13
int main() { 
    while(true){
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist6(0,9); // distribution in range [1, 6]
        int slot1 = dist6(rng); 
        int slot2 = dist6(rng);
        int slot3 = dist6(rng);
        board[9] = opt[slot1];
        board[11] = opt[slot2];
        board[13] = opt[slot3];
        if (board[9] == board[11] && board[11] == board[13]){
            money += 100;
        }
        cout << board << "\n";
        cout << "Money: " << money << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    };
}
