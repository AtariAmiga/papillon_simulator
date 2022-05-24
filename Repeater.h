#ifndef REPEATER_H_INCLUDED
#define REPEATER_H_INCLUDED

#include <iostream>
#include <map>
#include "CommunicationNode.h"

class World;
class Location;

class Repeater : public CommunicationNode {
public:
    Repeater(const char *name, struct World* owner, float x, float y);
    void runOneStep() override;

private:
    std::map<std::string, int> _forwardedMessageCount;
};

#endif
