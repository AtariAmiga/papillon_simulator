#include "Clock.h"
#include <random>


Clock::Clock(time_t initialTime, float driftSpeedPercent) {
    _initialTime = initialTime;
    _currentTime = initialTime;
    _cumulatedDelta = 0;
    _driftSpeedPercent = driftSpeedPercent;

}

time_t Clock::updateTime(int dtInMs) {
    _cumulatedDelta += dtInMs;
    _currentTime = _initialTime + (time_t) (_cumulatedDelta*(1 + _driftSpeedPercent / 100.0));
    return _currentTime;
}

std::ostream& operator<<(std::ostream &os, Clock& c) {
    return os << c._currentTime;
}