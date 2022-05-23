#include "NEW.h"

#include "World.h"
#include "Message.h"
#include "Terminal.h"
#include "Repeater.h"

const float SIGNAL_RANGE_IN_M = 1000.0f;

struct World* World_new(char* name) {
    struct World* self = NEW(World);

    self->name = name;
    self->messageList = List_new();
    self->terminalList = List_new();
    self->repeaterList = List_new();

    return self;
}

struct Terminal* World_newTerminal(struct World* self, char* name, float x, float y) {
    struct Terminal* emitter = Terminal_new(name, self, x, y);
    List_insertFirst(self->terminalList, emitter);
    return emitter;
}

struct Repeater* World_newRepeater(struct World* self, char* name, float x, float y) {
    struct Repeater* repeater = Repeater_new(name, self, x, y);
    List_insertFirst(self->repeaterList, repeater);
    return repeater;
}

void World_queueMessage(struct World* self, struct Message* message) {
    List_insertFirst( self->messageList, message );
}

void World_runOneStep(struct World* self) {
    struct Message *message;
    while( (message = List_removeFirst(self->messageList)) != NULL ) {
        printf("World: ");
        Message_println(message);

        // todo: do better? 0.0f < d means that emitter should not receive its own emitted messages (unless comes back later after being repeated)
        // Terminals
        struct ListNode* terminalNode = self->terminalList->head;
        while(terminalNode != NULL ) {
            struct Terminal* terminal = terminalNode->data;
            float d = distance(message->emittedLocation, terminal->location);
            if(0.0f < d && d < SIGNAL_RANGE_IN_M)
                Terminal_receive_message( terminal, message );

            terminalNode = terminalNode->next;
        }

        // Repeaters todo: same code for Repeater and Terminal!
        struct ListNode* repeaterNode = self->repeaterList->head;
        while(repeaterNode != NULL ) {
            struct Repeater* repeater = repeaterNode->data;
            float d = distance(message->emittedLocation, repeater->location);
            if(0.0f < d && d < SIGNAL_RANGE_IN_M)
                Repeater_receive_message( repeater, message );

            repeaterNode = repeaterNode->next;
        }
    }
}

void World_println(struct World* self) {
    assert(self != NULL);
    printf("World '%s'\n", self->name);
}