#ifndef REPEATER_H_INCLUDED
#define REPEATER_H_INCLUDED

#include <iostream>
#include "CommunicationNode.h"

class World;
class Location;

class Repeater : public CommunicationNode {
public:
    Repeater(const char *name, struct World* owner, float x, float y);
    void runOneStep() override;

    friend std::ostream &operator<<(std::ostream &os, const Repeater* repeater);
};

std::ostream &operator<<(std::ostream &os, const Repeater* repeater);


#endif
