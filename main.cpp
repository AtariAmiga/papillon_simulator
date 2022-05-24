#include "Terminal.h"
#include "Repeater.h"
#include "World.h"

#include <iostream>

int main() {
    auto* w = new World("W");

    Terminal* v = w->newTerminal("Vince", 0, 0);
    Terminal* t = w->newTerminal("Tonio", 1500, 0);
    w->newRepeater("R1", 750, 0);
    w->newRepeater("R2", 900, 0);
    w->newRepeater("R3", 1200, 0);

    v->sendMessage("Hi Tonio", "Vince");
    t->sendMessage("Hi Vince", "Tonio");

    for( int i = 0; i < 5; i++ ) {
        w->runOneStep();
        std::cout << std::flush;
    }

    return 0;
}
