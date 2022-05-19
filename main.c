#include <stdio.h>

#include "Emitter.h"
#include "World.h"

int main() {
    setbuf(stdout, NULL);

    struct World* w = World_new("The world");

    struct Emitter* v = World_newEmitter(w, "Vincent");
    struct Emitter* a = World_newEmitter(w, "Antoine");

    Emitter_send_message(v, "Hello Antoine", a);
    Emitter_send_message(a, "Hello Vincent", v);

    World_runOneStep(w);

    return 0;
}
