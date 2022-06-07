#ifndef CLOCK_H
#define CLOCK_H


#include <ctime>

class Clock {
public:
    Clock(time_t initialTime, float driftSpeedPercent);

    time_t updateTime(int dtInMs);

private:
    double _timeInMsAsDouble;
    float _driftSpeedPercent;
};


#endif // CLOCK_H
