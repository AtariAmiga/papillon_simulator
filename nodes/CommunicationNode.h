#ifndef COMMUNICATION_NODE_H
#define COMMUNICATION_NODE_H

#include "../world/Location.h"
#include "../Clock.h"
#include "NodeScheduler.h"

#include <list>
#include <iostream>
#include <memory>

class World;
class TextMessage;

class CommunicationNode {
protected:
    static int _nextNodeUniqueID;

    std::list<std::shared_ptr<TextMessage>> _messageReceivedList;

    const int _nodeUniqueID;

    Location _location;
    const char* _name;

    Clock _nodeClock;
    NodeScheduler _scheduler;

public:
    CommunicationNode(const char *name, float x, float y, int talkTimeSlot);

    const char* name();

    void simulateTime(int dtInMs);
    virtual void receiveMessage(const std::shared_ptr<TextMessage>& message);
    virtual void runOneStep(std::list<std::shared_ptr<TextMessage>>& emittedMessageList) = 0;

    const Location& location() const { return _location; }

    friend std::ostream& operator<<(std::ostream &os, const std::shared_ptr<CommunicationNode>& n);
};

std::ostream& operator<<(std::ostream &os, const std::shared_ptr<CommunicationNode>& n);

#endif // COMMUNICATION_NODE_H
