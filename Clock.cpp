#include "Clock.h"
#include <random>


Clock::Clock(time_t initialTime, float driftSpeedPercent) {
    _currentTime = (double) initialTime;
    _driftSpeedPercent = driftSpeedPercent;
}

time_t Clock::updateTime(int dtInMs) {
    _currentTime += dtInMs*(1 + _driftSpeedPercent / 100.0);
    return (time_t) _currentTime;
}

void Clock::syncTime(time_t time) {
    _currentTime = (double) time;
}

std::ostream& operator<<(std::ostream &os, const Clock& c) {
    return os << c.currentTime();
}

time_t Clock::currentTime() const {
    return (time_t) std::round(_currentTime);
}

time_t Clock::toTime() const {
    return _currentTime;
}
