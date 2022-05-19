#include "NEW.h"

#include "World.h"
#include "Message.h"
#include "Terminal.h"

struct World* World_new(char* name) {
    struct World* this = NEW(World);

    this->name = name;
    this->messageList = List_new();
    this->emitterList = List_new();

    return this;
}

struct Terminal* World_newTerminal(struct World* this, char* name) {
    struct Terminal* emitter = Terminal_new(name, this);
    List_insertFirst(this->emitterList, emitter);
    return emitter;
}

void World_queueMessage(struct World* this, struct Message* message) {
    List_insertFirst( this->messageList, message );
}

void World_runOneStep(struct World* this) {
    struct Message *message;
    while( (message = List_removeFirst(this->messageList)) != NULL ) {
        Message_println(message);

        struct ListNode* node = this->emitterList->head;
        while( node != NULL ) {
            Terminal_println((struct Terminal*) node->data);
            if( message->recipient == (struct Terminal*) node->data ) {
                printf("transferring message\n");
            }
            node = node->next;
        }
    }
}

void World_println(struct World* this) {
    assert(this != NULL);
    printf("World '%s'\n", this->name);
}