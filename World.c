#include "NEW.h"

#include "World.h"

struct World* World_new(char* name) {
    struct World* i = NEW(World);

    i->name = name;
    i->messageList = List_new();

    return i;
}

void World_queueMessage(struct World* this, struct Emitter* emitter, const char* message, struct Emitter* recipient) {
    // todo
}

void World_println(struct World* this) {
    assert(this != NULL);
    printf("World '%s'\n", this->name);
}