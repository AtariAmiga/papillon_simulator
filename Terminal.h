#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED

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

    void println() const;
};

#endif