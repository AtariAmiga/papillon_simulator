#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include "NEW.h"

#include "Emitter.h"

struct Emitter* Emitter_new(char* name) {
    struct Emitter* e = NEW(Emitter);
    e->name = name;
    return e;
}

void Emitter_print(struct Emitter* this) {
    assert(this != NULL);
    printf("Emitter '%s'", this->name);
}