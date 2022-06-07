#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>

class Location {
private:
    float _x;
    float _y;

public:
    Location(float x, float y);
    Location(const Location& l);

    friend std::ostream& operator<<(std::ostream &os, const Location& location);
    friend float locationDistance(const Location &a, const Location &b);
};

std::ostream& operator<<(std::ostream &os, const Location& l);

float locationDistance(const Location &a, const Location &b);

#endif // LOCATION_H