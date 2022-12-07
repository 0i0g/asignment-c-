#include <iostream>

using namespace std;

class Time {
public:
    int hours;
    int minutes;

    Time(int hours, int minutes);

    string getTime24h();

    string getTimeAMPM();
};
