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
struct Terminal* World_newTerminal(struct World* self, char* name);
struct Repeater* World_newRepeater(struct World* self, char* name);
void World_println(struct World* self);
void World_runOneStep(struct World* self);
void World_queueMessage(struct World* self, struct Message* message);

#endif