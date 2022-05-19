#include <stdio.h>

#include "Terminal.h"
#include "World.h"

int main() {
    setbuf(stdout, NULL);

    struct World* w = World_new("The world");

    struct Terminal* v = World_newTerminal(w, "Vincent");
    struct Terminal* a = World_newTerminal(w, "Antoine");

    Terminal_send_message(v, "Hello Antoine", "Antoine");
    Terminal_send_message(a, "Hello Vincent", "Vincent");

    World_runOneStep(w);

    return 0;
}
