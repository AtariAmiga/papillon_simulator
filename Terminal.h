#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED

#include <iostream>

class World;
class Message;
class Location;

class Terminal {
public:
    Location* location;
    const char* name;
    World* owner;

    Terminal(const char* name, struct World* owner, float x, float y);
    void sendMessage(const char* text, const char* recipient) const;
    void receiveMessage(struct Message* message) const;
};

std::ostream &operator<<(std::ostream &os, const Terminal* terminal);

#endif