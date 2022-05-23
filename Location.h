#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

#include <iostream>

class Location {
public:
    float x;
    float y;

    Location(float x, float y);
    Location* clone() const;

};

std::ostream &operator<<(std::ostream &os, const Location* location);

float locationDistance(const Location* a, const Location* b);

#endif