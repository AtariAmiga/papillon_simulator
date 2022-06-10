#ifndef REPEATER_H
#define REPEATER_H

#include <iostream>
#include <map>
#include "CommunicationNode.h"

class World;
class Location;

class Repeater : public CommunicationNode {
public:
    Repeater(const char *name, float x, float y);
    void runOneStep(std::list<std::shared_ptr<TextMessage>> &emittedMessageList) override;

private:
    std::map<std::string, int> _forwardedMessageCount; // todo: should not be infinite in an embedded device!
};

#endif // REPEATER_H
