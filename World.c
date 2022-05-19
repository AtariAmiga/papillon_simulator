#include "NEW.h"

#include "World.h"

struct World* World_new(char* name) {
    struct World* i = NEW(World);
    i->name = name;
    return i;
}

void World_println(struct World* this) {
    assert(this != NULL);
    printf("World '%s'\n", this->name);
}