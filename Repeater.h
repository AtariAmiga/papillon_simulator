#ifndef REPEATER_H_INCLUDED
#define REPEATER_H_INCLUDED

#include "World.h"

struct Repeater {
    struct List* messageList;
    struct Location* location;
    char* name;
    struct World* worldOwner;
};

struct Repeater* Repeater_new(char *name, struct World* owner, float x, float y);
void Repeater_receive_message(struct Repeater* self, struct Message* message);
void Repeater_runOneStep(struct Repeater* self);

void Repeater_println(struct Repeater* self);

#endif
