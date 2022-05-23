#ifndef REPEATER_H_INCLUDED
#define REPEATER_H_INCLUDED

#include <list>
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
    
    void println() const;
};

#endif
