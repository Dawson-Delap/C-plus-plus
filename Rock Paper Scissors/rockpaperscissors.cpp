#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string x;
    const string rps[3] = {"Rock", "Paper", "Scissors"};
    srand (time(NULL));
    int num = rand() % 3;
    string player;
    cout << "Choose Rock Paper or Scissors (Needs To Be Capitilized): ";
    cin >> player;
    cout << player << "\n" << "VS \n";
    cout << rps[num] << "\n";
    if (player == "Rock" && rps[num] == "Scissors"){
        cout << "Player Wins!!";
    }
    else if (player == "Paper" && rps[num] == "Rock"){
        cout << "Player Wins!!";
    }
    else if (player == "Scissors" && rps[num] == "Paper"){
        cout << "Player Wins!!";
    }
    else{
        cout << "Bot Wins ;(";
    }
    cout << "\nType something to quit ";
    cin >> x;
    
}
