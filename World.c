#include "NEW.h"

#include "World.h"
#include "Message.h"
#include "Terminal.h"
#include "Repeater.h"

struct World* World_new(char* name) {
    struct World* this = NEW(World);

    this->name = name;
    this->messageList = List_new();
    this->terminalList = List_new();
    this->repeaterList = List_new();

    return this;
}

struct Terminal* World_newTerminal(struct World* this, char* name) {
    struct Terminal* emitter = Terminal_new(name, this);
    List_insertFirst(this->terminalList, emitter);
    return emitter;
}

struct Repeater* World_newRepeater(struct World* this, char* name) {
    struct Repeater* repeater = Repeater_new(name, this);
    List_insertFirst(this->repeaterList, repeater);
    return repeater;
}

void World_queueMessage(struct World* this, struct Message* message) {
    List_insertFirst( this->messageList, message );
}

void World_runOneStep(struct World* this) {
    struct Message *message;
    while( (message = List_removeFirst(this->messageList)) != NULL ) {
        Message_println(message);

        struct ListNode* terminalNode = this->terminalList->head;
        while(terminalNode != NULL ) {
            struct Terminal* terminal = terminalNode->data;
            Terminal_receive_message( terminal, message );
            terminalNode = terminalNode->next;
        }
    }
}

void World_println(struct World* this) {
    assert(this != NULL);
    printf("World '%s'\n", this->name);
}