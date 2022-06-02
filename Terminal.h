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
    Terminal(const char* name, World* owner, float x, float y);
    void sendMessage(const char* text, const char* recipient) const;

    void runOneStep(int dtInMs) override;

private:
    std::set<std::string> _receivedMessageIds; // todo: replace by a queue, because should not be infinite in an embedded device!
    int _nextMessageNum = 1;
};

#endif