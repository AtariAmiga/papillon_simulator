#include "NEW.h"
#include <math.h>
#include "Location.h"

struct Location* Location_new(float x, float y) {
    struct Location* this = NEW(Location);

    this->x = x;
    this->y = y;

    return this;
}

float distance(struct Location* a, struct Location* b) {
    float dx = (a->x - b->x);
    float dy = (a->y - b->y);
    return sqrtf(dx*dx + dy*dy);
}

void Location_println(struct Location* this) {
    assert( NULL != this);
    printf( "(%f, %f)", this->x, this->y);
}
