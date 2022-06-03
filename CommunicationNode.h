#ifndef COMMUNICATION_NODE_INCLUDED
#define COMMUNICATION_NODE_INCLUDED

#include "Location.h"

#include <list>
#include <iostream>
#include <memory>

class World;
class Message;

class CommunicationNode {
protected:
    static int _nextNodeUniqueID;

    std::list<std::shared_ptr<Message>> _messageList;

    const int _nodeUniqueID;

    Location _location;
    const char* _name;

    time_t _nodeTime;

public:
    CommunicationNode(const char *name, float x, float y);

    const char* name();

    void simulateTime(int dtInMs);
    virtual void receiveMessage(const std::shared_ptr<Message>& message);
    virtual std::list<std::shared_ptr<Message>> runOneStep() = 0;

    const Location& location() const { return _location; }

    friend std::ostream& operator<<(std::ostream &os, const std::shared_ptr<CommunicationNode>& n);
};

std::ostream& operator<<(std::ostream &os, const std::shared_ptr<CommunicationNode>& n);

#endif
