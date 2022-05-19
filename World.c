#include "NEW.h"

#include "World.h"
#include "Message.h"
#include "Terminal.h"

struct World* World_new(char* name) {
    struct World* this = NEW(World);

    this->name = name;
    this->messageList = List_new();
    this->terminalList = List_new();

    return this;
}

struct Terminal* World_newTerminal(struct World* this, char* name) {
    struct Terminal* emitter = Terminal_new(name, this);
    List_insertFirst(this->terminalList, emitter);
    return emitter;
}

void World_queueMessage(struct World* this, struct Message* message) {
    List_insertFirst( this->messageList, message );
}

void World_runOneStep(struct World* this) {
    struct Message *message;
    while( (message = List_removeFirst(this->messageList)) != NULL ) {
        Message_println(message);

        struct ListNode* node = this->terminalList->head;
        while( node != NULL ) {
            struct Terminal* terminal = node->data;
            Terminal_receive_message( terminal, message );
            node = node->next;
        }
    }
}

void World_println(struct World* this) {
    assert(this != NULL);
    printf("World '%s'\n", this->name);
}