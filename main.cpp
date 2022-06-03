#include "Terminal.h"
#include "Repeater.h"
#include "World.h"

#include <iostream>
#include <memory>

int main() {
    auto* w = new World("W", 0);

    auto v = w->newTerminal("Vince", 0, 0);
    auto t = w->newTerminal("Tonio", 1500, 0);
    w->newRepeater("R1", 750, 0);
    w->newRepeater("R2", 900, 0);
    w->newRepeater("R3", 1200, 0);

    w->queueMessage(v->emitMessage("Hi Tonio", "Tonio") );
    w->queueMessage(v->emitMessage("Hello John", "John") );
    w->queueMessage(t->emitMessage("Hi Vince", "Vince") );

    for( int i = 0; i < 5; i++ ) {
        w->simulateTime(1);
        w->runOneStep();
        std::cout << std::flush;
    }

    return 0;
}
