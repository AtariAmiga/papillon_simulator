#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

#include <iostream>

class Location {
private:
    float _x;
    float _y;

public:
    Location(float x, float y);
    Location* clone() const;

    friend std::ostream &operator<<(std::ostream &os, const Location* location);
    friend float locationDistance(const Location* a, const Location* b);
};

std::ostream &operator<<(std::ostream &os, const Location* location);

float locationDistance(const Location* a, const Location* b);

#endif