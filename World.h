#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include <list>
#include <iostream>
#include <memory>

class Terminal;
class Repeater;
class Message;
class CommunicationNode;

class World {
private:
    const char* _name;
    std::list<Message*> _messageList;
    std::list<std::shared_ptr<CommunicationNode>> _communicationNodeList;

public:
    explicit World(const char* name);
    std::shared_ptr<Terminal> newTerminal(const char* name, float x, float y);
    std::shared_ptr<Repeater> newRepeater(const char* name, float x, float y);
    void runOneStep();
    void queueMessage(Message* message);

    friend std::ostream& operator<<(std::ostream &os, const World& world);
};

std::ostream& operator<<(std::ostream &os, const World& w);

#endif