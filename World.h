#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include <list>
#include <iostream>
#include <memory>
#include <ctime>

class Terminal;
class Repeater;
class Message;
class CommunicationNode;

class World {
private:
    const char* _name;
    std::list<std::shared_ptr<Message>> _messageList;
    std::list<std::shared_ptr<CommunicationNode>> _communicationNodeList;

    time_t _exactTime;

public:
    explicit World(const char* name, time_t time);
    const char* name() { return _name; }
    std::shared_ptr<Terminal> newTerminal(const char* name, float x, float y);
    std::shared_ptr<Repeater> newRepeater(const char* name, float x, float y);
    void runOneStep(int dtInMs);
    void queueMessage(const std::shared_ptr<Message>& message);
};

#endif