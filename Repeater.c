#include <string.h>
#include "NEW.h"

#include "Repeater.h"
#include "World.h"
#include "Message.h"

struct Repeater* Repeater_new(char *name, struct World* owner) {
    struct Repeater* i = NEW(Repeater);
    i->name = name;
    i->owner = owner;
    return i;
}

void Repeater_println(struct Repeater* this) {
    assert(this != NULL);
    printf("Repeater '%s'\n", this->name);
}

void Repeater_receive_message(struct Repeater* this, struct Message* message) {
    assert(this != NULL);
    assert(message != NULL);

    printf( "Repeater %s received: ", this->name );
    Message_println(message);

    struct Message* message2 = Message_clone_and_increment(message);

    World_queueMessage(this->owner, message2);
}

