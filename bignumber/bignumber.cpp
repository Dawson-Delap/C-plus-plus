#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>         
using namespace std;

int main() {
    int x = 2;
    for(int i = 1; i>0; ++i){
        x += 1010101010;
        cout << x;
    }
    
}