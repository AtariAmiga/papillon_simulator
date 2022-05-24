#ifndef COMMUNICATION_NODE_INCLUDED
#define COMMUNICATION_NODE_INCLUDED

#include <list>

class World;
class Message;
class Location;

class CommunicationNode {
public:
    std::list<Message*> messageList;

    Location* location;
    const char* name;
    World* worldOwner;

    virtual void receiveMessage(Message *message);
    virtual void runOneStep() = 0;
};


#endif
