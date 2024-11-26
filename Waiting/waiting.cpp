#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    struct tm date;
    time_t now;
    time_t before;
    int hour;
    int min;
    int sec;
    int x = 0;
    char output[50];
    char input[50];
    char gittime[50];
    struct tm datetime;

    cout << "Time to shutdown in military time \nHour: ";
    cin >> hour;
    cout << "Minute: ";
    cin >> min;
    cout << "Second: ";
    cin >> sec;

    datetime.tm_hour = hour;
    datetime.tm_min = min;
    datetime.tm_sec = sec;
    strftime(input, sizeof(input), "%I:%M:%S %p", &datetime);

    datetime.tm_hour = hour;
    datetime.tm_min = min-1;
    datetime.tm_sec = sec;
    strftime(gittime, sizeof(gittime), "%I:%M:%S %p", &datetime);
    while (true) {
        time_t current_time = time(NULL);
        struct tm *local_current_time = localtime(&current_time);
        strftime(output, sizeof(output), "%I:%M:%S %p", local_current_time);

        if (x >= 3600) {
            if (x/3600 <= 9 && x/60%60 <= 9 && x%60 <= 9){ //hours, min, sec
                cout << "\nWaited:          0" << x / 3600 << ":0" << x / 60 % 60 << ":0" << x % 60 << "\n";
            }else if (x/3600 <= 9 && x/60%60 <= 9){ //hours, min
                cout << "\nWaited:          0" << x / 3600 << ":0" << x / 60 % 60 << ":" << x % 60 << "\n";
            }else if (x/3600 <= 9 && x%60 <= 9){ // hours, sec
                cout << "\nWaited:          0" << x / 3600 << ":" << x / 60 % 60 << ":0" << x % 60 << "\n";
            }else if (x/60%60 <= 9 && x%60 <= 9){ // min, sec 
                cout << "\nWaited:          " << x / 3600 << ":0" << x / 60 % 60 << ":0" << x % 60 << "\n";
            }else if (x/3600 <=9){ // hours 
                cout << "\nWaited:          0" << x / 3600 << ":" << x / 60 % 60 << ":" << x % 60 << "\n";
            }else if (x/60%60 <= 9){ // min
                cout << "\nWaited:          " << x / 3600 << ":0" << x / 60 % 60 << ":" << x % 60 << "\n";
            }else if (x%60 <= 9){ // min, sec 
                cout << "\nWaited:          " << x / 3600 << ":" << x / 60 % 60 << ":0" << x % 60 << "\n";
            }else{
                cout << "\nWaited:          " << x / 3600 << ":" << x / 60 % 60 << ":" << x % 60 << "\n";
            }
        } else if (x >= 60) {
            if (x/60 <= 9 && x%60 <=9){
                cout << "\nWaited:          00:0" << x / 60 << ":0" << x % 60 << "\n";
            }else if (x/60 <= 9){
                cout << "\nWaited:          00:0" << x / 60 << ":" << x % 60 << "\n";
            }else if (x%60 <= 9){
                cout << "\nWaited:          00:" << x / 60 << ":0" << x % 60 << "\n";
            }else{
                cout << "\nWaited:          00:" << x / 60 << ":" << x % 60 << "\n";
            }
        } else {
            if (x > 9){
                cout << "\nWaited:          00:00:" << x << "\n";
            }else{
                cout << "\nWaited:          00:00:0" << x << "\n";
            }
        }
        
        cout << "Current time:    " << output << "\n";
        cout << "Shutting Down:   " << input << "\n";
        // Create a timestamp for right now
        time(&now);

        // Create a timestamp
        date = *localtime(&now);
        date.tm_hour = hour;
        date.tm_min = min;
        date.tm_sec = sec;
        before = mktime(&date);

        double secs = (difftime(now, before)*-1);

            if (floor(secs / 3600) <= 9 && floor(fmod(secs/60,60)) <= 9 && fmod(secs,60) <= 9){ //hours, min, sec
                cout << "Time Left:       0" << floor(secs / 3600) << ":0" << floor(fmod(secs/60,60)) << ":0" << fmod(secs,60);
            }else if (floor(secs / 3600) <= 9 && floor(fmod(secs/60,60)) <= 9){ //hours, min
                cout << "Time Left:       0" << floor(secs / 3600) << ":0" << floor(fmod(secs/60,60)) << ":" << fmod(secs,60);
            }else if (floor(secs / 3600) <= 9 && fmod(secs,60) <= 9){ // hours, sec
                cout << "Time Left:       0" << floor(secs / 3600) << ":" << floor(fmod(secs/60,60)) << ":0" << fmod(secs,60);
            }else if (floor(fmod(secs/60,60)) <= 9 && fmod(secs,60) <= 9){ // min, sec 
                cout << "Time Left:       " << floor(secs / 3600) << ":0" << floor(fmod(secs/60,60)) << ":0" << fmod(secs,60);
            }else if (floor(secs / 3600) <=9){ // hours 
                cout << "Time Left:       0" << floor(secs / 3600) << ":" << floor(fmod(secs/60,60)) << ":" << fmod(secs,60);
            }else if (floor(fmod(secs/60,60)) <= 9){ // min
                cout << "Time Left:       " << floor(secs / 3600) << ":0" << floor(fmod(secs/60,60)) << ":" << fmod(secs,60);
            }else if (fmod(secs,60) <= 9){ // min, sec 
                cout << "Time Left:       " << floor(secs / 3600) << ":" << floor(fmod(secs/60,60)) << ":0" << fmod(secs,60);
            }else{
                cout << "Time Left:       " << floor(secs / 3600) << ":" << floor(fmod(secs/60,60)) << ":" << fmod(secs,60);
            }
        

        if (strcmp(gittime, output) == 0) {
            system("GitHub Desktop.lnk");
        }
        if (strcmp(output, input) == 0) {
            system("shutdown /s /t 0");
            break;
        }

        x++;

        
            
        this_thread::sleep_for(chrono::seconds(1));
    }
    
}