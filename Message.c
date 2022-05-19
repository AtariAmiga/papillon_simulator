#include "NEW.h"
#include "Message.h"
#include "Emitter.h"

struct Message* Message_new(struct Emitter* emitter, const char* text, struct Emitter* recipient) {
    struct Message* this = NEW(Message);

    this->emitter = emitter;
    this->text = text;
    this->recipient = recipient;

    return this;
}

void Message_println(struct Message* this) {
    assert(this != NULL );
    printf( "Message: %s '%s' > %s\n", this->emitter->name, this->text, this->recipient->name );
}

