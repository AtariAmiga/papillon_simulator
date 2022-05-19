#include "NEW.h"

#include "Emitter.h"
#include "World.h"

struct Emitter* Emitter_new(char* name, struct World* owner) {
    struct Emitter* i = NEW(Emitter);
    i->name = name;
    i->owner = owner;
    return i;
}

void Emitter_println(struct Emitter* this) {
    assert(this != NULL);
    printf("Emitter '%s'\n", this->name);
}