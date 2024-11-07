#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>         
using namespace std;

int main() {
    int x = 2;
    while(true){
        x += 1010101010;
        cout << x;
    }
    
}