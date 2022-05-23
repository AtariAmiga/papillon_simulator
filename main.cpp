#include "Terminal.h"
#include "Repeater.h"
#include "World.h"

#include <iostream>

int main() {
    auto* w = new World("The world");

    Terminal* v = w->newTerminal("Vincent", 0, 0);
    Terminal* a = w->newTerminal("Antoine", 1500, 0);
    Repeater* r1 = w->newRepeater("Repeater1", 750, 0);

    v->sendMessage("Hello Antoine", "Antoine");
    a->sendMessage("Hello Vincent", "Vincent");

    w->runOneStep();
    r1->runOneStep(); // todo: include this in World
    w->runOneStep();

    std::cout << std::flush;
    return 0;
}