#include <stdio.h>

#include "Emitter.h"
#include "World.h"

int main() {
    printf("Hello, World!\n");
    struct World* w = World_new("The world");
    struct Emitter* e = Emitter_new("Vincent");
    Emitter_println(e);
    World_println(w);
    return 0;
}
