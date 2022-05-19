#include "NEW.h"

#include "World.h"
#include "Message.h"

struct World* World_new(char* name) {
    struct World* this = NEW(World);

    this->name = name;
    this->messageList = List_new();

    return this;
}

void World_queueMessage(struct World* this, struct Message* message) {
    List_insertFirst( this->messageList, message );
}

void World_println(struct World* this) {
    assert(this != NULL);
    printf("World '%s'\n", this->name);
}