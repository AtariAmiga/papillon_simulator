#include "NEW.h"

#include "World.h"
#include "Message.h"
#include "Terminal.h"
#include "Repeater.h"

struct World* World_new(char* name) {
    struct World* self = NEW(World);

    self->name = name;
    self->messageList = List_new();
    self->terminalList = List_new();
    self->repeaterList = List_new();

    return self;
}

struct Terminal* World_newTerminal(struct World* self, char* name) {
    struct Terminal* emitter = Terminal_new(name, self);
    List_insertFirst(self->terminalList, emitter);
    return emitter;
}

struct Repeater* World_newRepeater(struct World* self, char* name) {
    struct Repeater* repeater = Repeater_new(name, self);
    List_insertFirst(self->repeaterList, repeater);
    return repeater;
}

void World_queueMessage(struct World* self, struct Message* message) {
    List_insertFirst( self->messageList, message );
}

void World_runOneStep(struct World* self) {
    struct Message *message;
    while( (message = List_removeFirst(self->messageList)) != NULL ) {
        Message_println(message);

        struct ListNode* terminalNode = self->terminalList->head;
        while(terminalNode != NULL ) {
            struct Terminal* terminal = terminalNode->data;
            Terminal_receive_message( terminal, message );
            terminalNode = terminalNode->next;
        }
    }
}

void World_println(struct World* self) {
    assert(self != NULL);
    printf("World '%s'\n", self->name);
}