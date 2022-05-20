#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "Terminal.h"
#include "List.h"
#include "Message.h"

struct World {
    char* name;
    struct List* messageList;
    struct List* terminalList;
    struct List *repeaterList;
};

struct World* World_new(char* name);
struct Terminal* World_newTerminal(struct World* this, char* name);
struct Repeater* World_newRepeater(struct World* this, char* name);
void World_println(struct World* this);
void World_runOneStep(struct World* this);
void World_queueMessage(struct World* this, struct Message* message);

#endif