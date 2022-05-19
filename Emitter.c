#include "NEW.h"

#include "Emitter.h"

struct Emitter* Emitter_new(char* name) {
    struct Emitter* i = NEW(Emitter);
    i->name = name;
    return i;
}

void Emitter_println(struct Emitter* this) {
    assert(this != NULL);
    printf("Emitter '%s'\n", this->name);
}