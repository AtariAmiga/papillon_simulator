#include <stdio.h>

#include "Emitter.h"
#include "World.h"

int main() {
    struct World* w = World_new("The world");

    struct Emitter* v = Emitter_new("Vincent", w);
    struct Emitter* a = Emitter_new("Antoine", w);

    Emitter_send_message(v, "Hello Antoine", a);

    Emitter_println(v);
    World_println(w);
    return 0;
}
