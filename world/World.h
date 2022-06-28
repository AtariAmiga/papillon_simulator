#ifndef WORLD_H
#define WORLD_H

#include "../Clock.h"

#include <list>
#include <iostream>
#include <memory>
#include <ctime>

class Terminal;
class Repeater;
class TextMessage;
class CommunicationNode;

class World {
public:
    explicit World(const char *name);
    const char* name() { return _name; }
    time_t simulateTime(int dtInMs);
    void addCommunicationNode(CommunicationNode *node);

    void runOneStep();

private:
    const char* _name;
    std::list<std::shared_ptr<TextMessage>> _messageList;
    std::list<std::shared_ptr<CommunicationNode>> _communicationNodeList;

    Clock _exactClock;
};

#endif // WORLD_H