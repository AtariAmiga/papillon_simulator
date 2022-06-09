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
private:
    const char* _name;
    std::list<std::shared_ptr<TextMessage>> _messageList;
    std::list<std::shared_ptr<CommunicationNode>> _communicationNodeList;

    Clock _exactClock;

public:
    explicit World(const char *name);
    const char* name() { return _name; }
    void simulateTime(int dtInMs);
    std::shared_ptr<Terminal> newTerminal(const char* name, float x, float y);
    std::shared_ptr<Repeater> newRepeater(const char* name, float x, float y);
    void runOneStep();
    void queueMessage(const std::shared_ptr<TextMessage>& message);
};

#endif // WORLD_H