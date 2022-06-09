#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <ctime>

class Clock {
public:
    Clock(time_t initialTime, float driftSpeedPercent);

    time_t updateTime(int dtInMs);

    friend std::ostream& operator<<(std::ostream &os, Clock& c);

private:
    time_t _initialTime;
    int _cumulatedDelta;
    float _driftSpeedPercent;
    time_t _currentTime;
};

std::ostream& operator<<(std::ostream &os, Clock& c);

#endif // CLOCK_H
