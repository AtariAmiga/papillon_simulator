#include "NEW.h"

#include "Emitter.h"
#include "World.h"
#include "Message.h"

struct Emitter* Emitter_new(char *name, struct World* owner) {
    struct Emitter* i = NEW(Emitter);
    i->name = name;
    i->owner = owner;
    return i;
}

void Emitter_println(struct Emitter* this) {
    assert(this != NULL);
    printf("Emitter '%s'\n", this->name);
}

void Emitter_send_message(struct Emitter* this, const char* text, struct Emitter* recipient) {
    assert(this != NULL);
    assert(text != NULL);
    assert(recipient != NULL);

    struct Message* message = Message_new(this, text, recipient);

    World_queueMessage(this->owner, message);
}

