#include "NEW.h"
#include "Message.h"
#include "Terminal.h"

struct Message* Message_new(struct Terminal* emitter, const char* text, const char* recipientName) {
    struct Message* this = NEW(Message);

    this->emitter = emitter;
    this->text = text;
    this->recipientName = recipientName;

    return this;
}

void Message_println(struct Message* this) {
    assert(this != NULL );
    printf( "Message: %s '%s' > %s\n", this->emitter->name, this->text, this->recipientName );
}

