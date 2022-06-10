#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <set>
#include "CommunicationNode.h"

class World;
class TextMessage;
class Location;

class Terminal : public CommunicationNode {
public:
    Terminal(const char *name, float x, float y);
    void newMessage(const char* text, const char* recipient);

    void runOneStep(std::list<std::shared_ptr<TextMessage>> &emittedMessageList) override;

private:
    std::list<std::shared_ptr<TextMessage>> _messageToEmitList;
    std::set<std::string> _receivedMessageIds; // todo: replace by a queue, because should not be infinite in an embedded device!
    int _nextMessageNum = 1;

    std::string nextMessageUniqueId();
};

#endif // TERMINAL_H