#ifndef REPEATER_H
#define REPEATER_H

#include <iostream>
#include <map>
#include "CommunicationNode.h"
#include "SchedulerConfiguration.h"

class World;
class Location;

class Repeater : public CommunicationNode {
public:
    Repeater(const char* name, float x, float y, const SchedulerConfiguration& sc, int talkTimeSlot);
    void runOneStep(std::list<std::shared_ptr<TextMessage>> &emittedMessageList) override;

private:
    std::map<std::string, int> _forwardedMessageCount; // todo: should not be infinite in an embedded device!
};

#endif // REPEATER_H
