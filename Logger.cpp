#include "Logger.h"
#include <iostream>

Logger logger(std::cout);

Logger::Logger(std::ostream& str):
    std::ostream(&buffer),
    buffer(str, _currentTime, _lastTimeLogged, _indent),
    _indent(1),
    _currentTime(0),
    _lastTimeLogged(-1)
{
}

void Logger::updateTime(time_t t) {
    _currentTime = t;
}

void Logger::stepIn() {
    _indent++;
}

void Logger::stepOut() {
    _indent--;
}