#include "Clock.h"
#include <random>


Clock::Clock(time_t initialTime, float driftSpeedPercent) {
    _currentTime = (double) initialTime;
    _driftSpeedPercent = driftSpeedPercent;
    _externalTimeSum = 0;
    _externalTimeCount = 0;
    _skewCorrection = 0;
}

time_t Clock::updateTime(int dtInMs) {
    _currentTime += dtInMs*(1 + _driftSpeedPercent / 100.0) + _skewCorrection;
    return (time_t) _currentTime;
}

void Clock::setCurrentTime(time_t time) {
    _currentTime = (double) time;
}

std::ostream& operator<<(std::ostream &os, const Clock& c) {
    return os << c.currentTime();
}

time_t Clock::currentTime() const {
    return (time_t) std::round(_currentTime);
}

void Clock::syncTime(time_t externalTime) {
    _externalTimeSum += externalTime;
    _externalTimeCount++;
}

double Clock::syncTimeStop() {
    _skewCorrection = (_externalTimeSum / _externalTimeCount) - _currentTime;
    _externalTimeSum = 0;
    _externalTimeCount = 0;

    return _skewCorrection;
}
