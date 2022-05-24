#ifndef COMMUNICATION_NODE_INCLUDED
#define COMMUNICATION_NODE_INCLUDED

#include <list>

class World;
class Message;
class Location;

class CommunicationNode {
protected:
    std::list<Message*> messageList;

    Location* _location;
    const char* name;
    World* worldOwner;

public:
    virtual void receiveMessage(Message *message);
    virtual void runOneStep() = 0;

    const Location* location() const { return _location; }
};


#endif
