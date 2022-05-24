#include "Terminal.h"
#include "Repeater.h"
#include "World.h"

#include <iostream>

int main() {
    auto* w = new World("The world");

    Terminal* v = w->newTerminal("Vincent", 0, 0);
    Terminal* a = w->newTerminal("Antoine", 1500, 0);
    w->newRepeater("Repeater1", 750, 0);
    w->newRepeater("Repeater2", 900, 0);
    w->newRepeater("Repeater3", 1200, 0);

    v->sendMessage("Hello Antoine", "Antoine");
    a->sendMessage("Hello Vincent", "Vincent");

    for( int i = 0; i < 5; i++ ) {
        w->runOneStep();
        std::cout << std::flush;
    }

    return 0;
}
