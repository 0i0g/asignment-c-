#include "time.h"

Time::Time(int hours, int minutes) {
    if (hours > 23 || hours < 0) {
        throw invalid_argument("Invalid hours. (0-23)");
    }
    if (minutes > 59 || minutes < 0) {
        throw invalid_argument("Invalid minutes (0-59)");
    }
    this->hours = hours;
    this->minutes = minutes;
}

string Time::getTime24h() {
    return to_string(hours) + ":" + to_string(minutes);
}

string Time::getTimeAMPM() {
    string suffix = "AM";
    int hoursFixed = hours;
    if (hours > 12) {
        suffix = "PM";
        hoursFixed = hours - 12;
    }
    return to_string(hoursFixed) + ":" + to_string(minutes) + " " + suffix;
}
