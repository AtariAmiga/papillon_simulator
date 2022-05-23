#include <stdio.h>

#include "Terminal.h"
#include "Repeater.h"
#include "World.h"

int main() {
    setbuf(stdout, NULL);

    struct World* w = World_new("The world");

    struct Terminal* v = World_newTerminal(w, "Vincent", 0, 0);
    struct Terminal* a = World_newTerminal(w, "Antoine", 1500, 0);
    struct Repeater* r1 = World_newRepeater(w, "Repeater1", 750, 0);

    Terminal_send_message(v, "Hello Antoine", "Antoine");
    Terminal_send_message(a, "Hello Vincent", "Vincent");

    World_runOneStep(w);

    return 0;
}
