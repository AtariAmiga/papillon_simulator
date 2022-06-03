#include "Location.h"
#include <cmath>
#include <iostream>

Location::Location(float x, float y) {
    _x = x;
    _y = y;
}

Location::Location(const Location& l) {
    _x = l._x;
    _y = l._y;
}

std::ostream& operator<<(std::ostream &os, const Location& l) {
    return os << "(" << l._x << ", " << l._y << ")";
}

float locationDistance(const Location &a, const Location &b) {
    float dx = (a._x - b._x);
    float dy = (a._y - b._y);
    return sqrtf(dx*dx + dy*dy);
}