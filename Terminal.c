#include <string.h>
#include "NEW.h"

#include "Terminal.h"
#include "World.h"
#include "Message.h"

struct Terminal* Terminal_new(char *name, struct World* owner, float x, float y) {
    struct Terminal* self = NEW(Terminal);

    self->location = Location_new(x, y);
    self->name = name;
    self->owner = owner;
    return self;
}

void Terminal_println(struct Terminal* self) {
    assert(self != NULL);
    printf("Terminal '%s'\n", self->name);
}

void Terminal_send_message(struct Terminal* self, const char* text, const char* recipient) {
    assert(self != NULL);
    assert(text != NULL);
    assert(recipient != NULL);

    struct Message* message = Message_new(self->location, self->name, text, recipient);

    World_queueMessage(self->owner, message);
}

void Terminal_receive_message(struct Terminal* self, struct Message* message) {
    assert(self != NULL);
    assert(message != NULL);

    printf( "Terminal %s received: ", self->name );
    Message_println(message);

    if(strcmp(message->recipientName, self->name) == 0 ) {
        printf("\tprocess, self is for me\n");
    }
}

