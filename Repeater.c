#include <string.h>
#include "NEW.h"

#include "Repeater.h"
#include "World.h"
#include "Message.h"

struct Repeater* Repeater_new(char *name, struct World* owner, float x, float y) {
    struct Repeater* self = NEW(Repeater);
    self->location = Location_new(x, y);
    self->name = name;
    self->worldOwner = owner;
    self->messageList = List_new();
    return self;
}

void Repeater_println(struct Repeater* self) {
    assert(self != NULL);
    printf("Repeater '%s'\n", self->name);
}

void Repeater_receiveMessage(struct Repeater* self, struct Message* message) {
    assert(self != NULL);
    assert(message != NULL);

    printf( "'%s' received: ", self->name );
    Message_println(message);

    List_insertFirst(self->messageList, message);
}

void Repeater_runOneStep(struct Repeater* self) {
    for(;;) {
        struct Message* message = List_removeFirst(self->messageList);
        if( NULL == message)
            break;

        struct Message* clone = Message_cloneAndIncrement(message, self->location);
        World_queueMessage(self->worldOwner, clone);
    }
}

