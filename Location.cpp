#include "Location.h"
#include <cmath>
#include <iostream>

Location::Location(float x, float y) {
    _x = x;
    _y = y;
}

Location* Location::clone() const {
    return new Location(_x, _y);
}

std::ostream& operator<<(std::ostream &os, const Location* location) {
    return os << "(" << location-> _x << ", " << location->_y << ")";
}

float locationDistance(const Location* a, const Location* b) {
    float dx = (a->_x - b->_x);
    float dy = (a->_y - b->_y);
    return sqrtf(dx*dx + dy*dy);
}