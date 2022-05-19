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

void Terminal_send_message(struct Terminal* this, const char* text, struct Terminal* recipient) {
    assert(this != NULL);
    assert(text != NULL);
    assert(recipient != NULL);

    struct Message* message = Message_new(this, text, recipient);

    World_queueMessage(this->owner, message);
}

