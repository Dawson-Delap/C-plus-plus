#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>         
using namespace std;

int main() {
    int x = 0;
    for(int i = 1; i>0; ++i){
        x += 100;
        cout << x <<"\n";
    }
    
}