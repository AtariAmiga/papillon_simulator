#include "NEW.h"
#include "Message.h"

struct Message* Message_new(struct Emitter* emitter, const char* text, struct Emitter* recipient) {
    struct Message* this = NEW(Message);

    this->emitter = emitter;
    this->text = text;
    this->recipient = recipient;

    return this;
}
