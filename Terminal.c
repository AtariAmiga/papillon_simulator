#include <string.h>
#include "NEW.h"

#include "Terminal.h"
#include "World.h"
#include "Message.h"

struct Terminal* Terminal_new(char *name, struct World* owner) {
    struct Terminal* i = NEW(Terminal);
    i->name = name;
    i->owner = owner;
    return i;
}

void Terminal_println(struct Terminal* this) {
    assert(this != NULL);
    printf("Terminal '%s'\n", this->name);
}

void Terminal_send_message(struct Terminal* this, const char* text, const char* recipient) {
    assert(this != NULL);
    assert(text != NULL);
    assert(recipient != NULL);

    struct Message* message = Message_new(this->name, text, recipient);

    World_queueMessage(this->owner, message);
}

void Terminal_receive_message(struct Terminal* this, struct Message* message) {
    assert(this != NULL);
    assert(message != NULL);

    printf( "Terminal %s received: ", this->name );
    Message_println(message);
    if(strcmp(message->recipientName, this->name) == 0 ) {
        printf( "\tprocess, this is for me\n" );
    } else {
        printf( "\tsend, this is NOT for me\n" );
    }
}

