#include "nodes/Terminal.h"
#include "nodes/Repeater.h"
#include "world/World.h"
#include "Logger.h"

#include <iostream>
#include <memory>

int main() {
    int n = 0;
    World w("W");

    auto* v(new Terminal("Vince", 0, 0, (n++) % 10));
    auto* t(new Terminal("Tonio", 1500, 0, (n++) % 10));
    w.addCommunicationNode(v);
    w.addCommunicationNode(t);

    w.addCommunicationNode(new Repeater("R1", 750, 0, (n++) % 10));
    w.addCommunicationNode(new Repeater("R2", 900, 0, (n++) % 10));
    w.addCommunicationNode(new Repeater("R3", 1200, 0, (n++) % 10));

    v->newMessage("Hi Tonio", "Tonio");
    v->newMessage("Hello John", "John");
    t->newMessage("Hi Vince", "Vince");

    for( int i = 0; i < 50; i++ ) {
        w.simulateTime(5);
        w.runOneStep();
        logger << std::flush;
    }

    return 0;
}
