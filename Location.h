#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

class Location {
public:
    float x;
    float y;

    Location(float x, float y);
    Location* clone() const;
    void print() const;
};

float locationDistance(const Location* a, const Location* b);

#endif