#include "Location.h"
#include <cmath>
#include <iostream>

Location::Location(float x, float y) {
    this->x = x;
    this->y = y;
}

Location* Location::clone() const {
    return new Location(this->x, this->y);
}

std::ostream& Location::operator<<(std::ostream &os) const {
    return os << "(" << this-> x << ", " << this->y << ")";
}

float locationDistance(const Location* a, const Location* b) {
    float dx = (a->x - b->x);
    float dy = (a->y - b->y);
    return sqrtf(dx*dx + dy*dy);
}