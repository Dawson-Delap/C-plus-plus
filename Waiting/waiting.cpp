#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstring>

using namespace std;

int main() {
    int x = 0;
    char output[50];
    char input[50];
    struct tm datetime;

    
    datetime.tm_hour = 14;
    datetime.tm_min = 33;
    strftime(input, sizeof(input), "%I:%M %p", &datetime);

    while (true) {
        time_t timestamp = time(NULL);
        struct tm current_time = *localtime(&timestamp);
        strftime(output, sizeof(output), "%I:%M %p", &current_time);
        if (x >= 3600){
            cout << "You have waited: " << x/3600 << "hours and" << x/3600 % 60 << " minutes and " << x % 60 << " seconds\n"
        }
        else if (x >= 60) {
            cout << "You have waited: " << x / 60 << " minutes and " << x % 60 << " seconds\n";
        } else {
            cout << "You have waited: " << x << " seconds\n";
        }
        cout << "Current time: " << output << "\n";

        if (strcmp(output, input) == 0) {
            system("c:\\windows\\system32\\shutdown /s");
            break;
        }

        
        x++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}