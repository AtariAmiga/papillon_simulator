#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "Emitter.h"
#include "List.h"
#include "Message.h"

struct World {
    char* name;
    struct List* messageList;
};

struct World* World_new(char* name);
void World_println(struct World* this);
void World_runOneStep(struct World* this);
void World_queueMessage(struct World* this, struct Message* message);

#endif