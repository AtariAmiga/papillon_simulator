#include "nodes/Terminal.h"
#include "nodes/Repeater.h"
#include "world/World.h"
#include "Logger.h"
#include "nodes/SchedulerConfiguration.h"

#include <iostream>
#include <memory>

int main() {
    int n = 0;
    World w("W");
    SchedulerConfiguration sc(100, 50, 20);

//    auto talkSlot = [&n, &sc]() {return (n++) % sc._totalTalkSlots; };
    auto talkSlot = []() {return 0; };

    auto* v(new Terminal("Vince", 0, 0, sc, talkSlot()));
    auto* t(new Terminal("Tonio", 1500, 0, sc, talkSlot()));
    w.addCommunicationNode(v);
    w.addCommunicationNode(t);

    w.addCommunicationNode(new Repeater("R1", 750, 0, sc, talkSlot()));
    w.addCommunicationNode(new Repeater("R2", 900, 0, sc, talkSlot()));
    w.addCommunicationNode(new Repeater("R3", 1200, 0, sc, talkSlot()));

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
