#include "Clock.h"
#include <random>

// todo: make this cleaner
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<double> dist(-5.0, 5.0);

Clock::Clock() {
    _driftSpeedPercent = dist(mt);
}