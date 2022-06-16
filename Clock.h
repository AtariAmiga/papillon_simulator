#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <ctime>

class Clock {
public:
    Clock(time_t initialTime, float driftSpeedPercent);

    time_t updateTime(int dtInMs);

    friend std::ostream& operator<<(std::ostream &os, const Clock& c);

    void syncTime(time_t time);

    time_t currentTime() const;

    time_t toTime() const;

private:
    double _currentTime; // Kept as double, as it can drift by less than 1 ms
    float _driftSpeedPercent;
};

std::ostream& operator<<(std::ostream &os, const Clock& c);

#endif // CLOCK_H
