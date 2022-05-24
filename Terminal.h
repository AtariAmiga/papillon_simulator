#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED

#include <iostream>
#include "CommunicationNode.h"

class World;
class Message;
class Location;

class Terminal : public CommunicationNode {
public:
    Terminal(const char* name, struct World* owner, float x, float y);
    void sendMessage(const char* text, const char* recipient) const;

    void runOneStep() override;

    friend std::ostream &operator<<(std::ostream &os, const Terminal* terminal);

private:
    int _nextMessageNum = 1;
};

std::ostream &operator<<(std::ostream &os, const Terminal* terminal);

#endif