#include <iostream>
#include "time.h"

using namespace std;

// split string by delimiter
string *split(string str, char delimiter) {
    string *result = new string[100];
    int i = 0;
    for (char c: str) {
        if (c == delimiter) {
            i++;
            continue;
        }
        result[i] += c;
    }
    return result;
}

// subtract two times
Time subtract_time(Time time1, Time time2) {
    int hours = time1.hours - time2.hours;
    int minutes = time1.minutes - time2.minutes;
    if (minutes < 0) {
        hours--;
        minutes += 60;
    }
    return Time(hours, minutes);
}

int main() {
    // Variables
    string name;
    string *lineSplit;
    string timeIn, timeOut;
    int hoursIn, hoursOut, minutesIn, minutesOut;

    cout << "Demo of Time Keeping Application" << endl;
    cout << endl;

    // Enter product name
    cout << "Enter name of rental product (enter quit to exit):";
    getline(cin, name);

    // Check enter quit to exit
    if (name == "quit") return 0;

    // Enter check in time
    cout << "Enter the time of check-int (h m)";
    getline(cin, timeIn);

    lineSplit = split(timeIn, ' ');

    // Convert time string to int
    hoursIn = stoi(lineSplit[0]);
    minutesIn = stoi(lineSplit[1]);

    // Enter check out time
    cout << "Enter the time of check-out (h m)";
    getline(cin, timeOut);
    lineSplit = split(timeOut, ' ');
    hoursOut = stoi(lineSplit[0]);
    minutesOut = stoi(lineSplit[1]);

    // Create time object
    Time timeInObj(hoursIn, minutesIn);
    Time timeOutObj(hoursOut, minutesOut);

    // Print result with 24h format
    cout << "Single line of rental invoice using 24 hour clock:" << endl;
    cout << name << endl;
    cout << "\ts:wide and Pin Point\t\t" << timeInObj.getTime24h() << "\t" << timeOutObj.getTime24h() << "\t"
         << subtract_time(timeInObj, timeOutObj).getTime24h() << endl;

    // Print result with AM/PM format
    cout << "Single line of rental invoice using AM/PM clock:" << endl;
    cout << name << endl;
    cout << "\ts:wide and Pin Point\t\t" << timeInObj.getTimeAMPM() << "\t" << timeOutObj.getTimeAMPM() << "\t"
         << subtract_time(timeInObj, timeOutObj).getTimeAMPM() << endl;

    return 0;
}