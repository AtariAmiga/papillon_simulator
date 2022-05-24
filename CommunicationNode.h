#ifndef COMMUNICATION_NODE_INCLUDED
#define COMMUNICATION_NODE_INCLUDED

#include <list>
#include <iostream>

class World;
class Message;
class Location;

class CommunicationNode {
protected:
    static int _nextNodeUniqueID;

    std::list<Message*> _messageList;

    const int _nodeUniqueID;

    Location* _location;
    const char* _name;
    World* _worldOwner;

public:
    CommunicationNode(const char* name, World* worldOwner, float x, float y);

    virtual void receiveMessage(Message *message);
    virtual void runOneStep() = 0;

    const Location* location() const { return _location; }

    friend std::ostream &operator<<(std::ostream &os, const CommunicationNode* n);
};

std::ostream &operator<<(std::ostream &os, const CommunicationNode* n);

#endif
