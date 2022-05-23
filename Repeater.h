#ifndef REPEATER_H_INCLUDED
#define REPEATER_H_INCLUDED

#include <list>
#include <iostream>

class World;
class Location;

class Repeater {
public:
    std::list<Message*> messageList;
    Location* location{};
    const char* name;
    World* worldOwner;

    Repeater(const char *name, struct World* owner, float x, float y);
    void receiveMessage(Message *message);
    void runOneStep();
};

std::ostream &operator<<(std::ostream &os, const Repeater* repeater);


#endif
