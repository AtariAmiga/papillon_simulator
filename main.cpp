#include "Terminal.h"
#include "Repeater.h"
#include "World.h"

#include <iostream>
#include <memory>

int main() {
    auto* w = new World("W");

    auto v = w->newTerminal("Vince", 0, 0);
    auto t = w->newTerminal("Tonio", 1500, 0);
    w->newRepeater("R1", 750, 0);
    w->newRepeater("R2", 900, 0);
    w->newRepeater("R3", 1200, 0);

    v->sendMessage("Hi Tonio", "Tonio");
    t->sendMessage("Hi Vince", "Vince");

    for( int i = 0; i < 5; i++ ) {
        w->runOneStep();
        std::cout << std::flush;
    }

    return 0;
}
