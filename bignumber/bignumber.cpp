#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>         
using namespace std;

int main() {
    int x = 2;
    for(int i = 1; i>0; ++i){
        x *= 2;
        cout << x <<"\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    
}