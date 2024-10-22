#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>         
using namespace std;

int main() {
    int x = 1;
    for(int i = 1; i>0; ++i){
        x += 2;
        cout << x <<"\n";
        //std::this_thread::sleep_for (std::chrono::seconds(1));
    }
    
}