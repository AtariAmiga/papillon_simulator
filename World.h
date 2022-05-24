#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include <list>
#include <iostream>

class Terminal;
class Repeater;
class Message;
class CommunicationNode;

class World {
private:
    const char* _name;
    std::list<Message*> messageList;
    std::list<CommunicationNode*> communicationNodeList;

public:
    explicit World(const char* name);
    Terminal* newTerminal(const char* name, float x, float y);
    Repeater* newRepeater(const char* name, float x, float y);
    void runOneStep();
    void queueMessage(struct Message* message);

    friend std::ostream& operator<<(std::ostream &os, const World* world);
};

std::ostream& operator<<(std::ostream &os, const World* world);

#endif