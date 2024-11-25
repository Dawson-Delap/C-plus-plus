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
            cout << "\nWaited: " << x / 3600 << " hours and " << x / 60 % 60 << " minutes and " << x % 60 << " seconds\n";
        } else if (x >= 60) {
            cout << "\nWaited: " << x / 60 << " minutes and " << x % 60 << " seconds\n";
        } else {
            cout << "\nWaited: " << x << " seconds\n";
        }
        
        cout << "Current time: " << output << "\n";
        cout << "Shutting Down at " << input << "\n";
        // Create a timestamp for right now
        time(&now);

        // Create a timestamp
        date = *localtime(&now);
        date.tm_hour = hour;
        date.tm_min = min;
        date.tm_sec = sec;
        before = mktime(&date);


        cout << floor((difftime(now, before)*-1)/60) << " Minutes Left";

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