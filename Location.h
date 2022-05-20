#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

struct Location {
    float x;
    float y;
};

struct Location* Location_new(float x, float y);
float distance(struct Location* a, struct Location* b);
void Location_println(struct Location* self);

#endif