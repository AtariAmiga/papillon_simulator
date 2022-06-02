#ifndef REPEATER_H_INCLUDED
#define REPEATER_H_INCLUDED

#include <iostream>
#include <map>
#include "CommunicationNode.h"

class World;
class Location;

class Repeater : public CommunicationNode {
public:
    Repeater(const char *name, float x, float y);
    std::list<std::shared_ptr<Message>> runOneStep(int dtInMs) override;

private:
    std::map<std::string, int> _forwardedMessageCount; // todo: should not be infinite in an embedded device!
};

#endif
