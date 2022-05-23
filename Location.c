#include "NEW.h"
#include <math.h>
#include "Location.h"

struct Location* Location_new(float x, float y) {
    struct Location* self = NEW(Location);

    self->x = x;
    self->y = y;

    return self;
}

struct Location* Location_clone(struct Location* location) {
    struct Location* self = NEW(Location);

    self->x = location->x;
    self->y = location->y;

    return self;
}

float distance(struct Location* a, struct Location* b) {
    float dx = (a->x - b->x);
    float dy = (a->y - b->y);
    return sqrtf(dx*dx + dy*dy);
}

void Location_print(struct Location* self) {
    assert( NULL != self);
    printf( "(%f, %f)", self->x, self->y);
}
