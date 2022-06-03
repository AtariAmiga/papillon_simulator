#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED

#include <iostream>
#include <set>
#include "CommunicationNode.h"

class World;
class Message;
class Location;

class Terminal : public CommunicationNode {
public:
    Terminal(const char *name, float x, float y);
    // todo: rename to sendMessage, and have runOneStep return the message created
    std::shared_ptr<Message> emitMessage(const char* text, const char* recipient) const;

    std::list<std::shared_ptr<Message>> runOneStep() override;

private:
    std::set<std::string> _receivedMessageIds; // todo: replace by a queue, because should not be infinite in an embedded device!
    int _nextMessageNum = 1;
};

#endif