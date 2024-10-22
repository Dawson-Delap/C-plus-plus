#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>         
using namespace std;

int main() {
    int x = 0;
    for(int i = 1; i>0; ++i){
        x += 1;
        if (x >= 60){
            cout << "You have waited: "<< x/60 <<" minutes and " << x%60 <<" seconds\n";
        }else{
        cout << "You have waited: "<< x <<"seconds\n";
        }
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
    
}