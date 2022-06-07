#include "Clock.h"
#include <random>


Clock::Clock(time_t initialTime, float driftSpeedPercent) {
    _timeInMsAsDouble = (double) initialTime;
    _driftSpeedPercent = driftSpeedPercent;
}

time_t Clock::updateTime(int dtInMs) {
    _timeInMsAsDouble += ((double) dtInMs)*(1 + _driftSpeedPercent/100.0);

    return (time_t) _timeInMsAsDouble;
}