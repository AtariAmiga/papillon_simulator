#include "NEW.h"
#include "Message.h"
#include "Terminal.h"

struct Message* Message_new(const char* emitterName, const char* text, const char* recipientName) {
    struct Message* this = NEW(Message);

    this->emitterName = emitterName;
    this->text = text;
    this->recipientName = recipientName;
    this->hopsCount = 0;

    return this;
}

struct Message* Message_clone_and_increment(struct Message* this) {
    struct Message* clone = NEW(Message);

    // todo: fully clone?
    clone->emitterName = this->emitterName;
    clone->text = this->text;
    clone->recipientName = this->recipientName;
    clone->hopsCount = this->hopsCount + 1;

    return clone;
}

void Message_println(struct Message* this) {
    assert(this != NULL );
    printf("Message: %s '%s' > %s\n", this->emitterName, this->text, this->recipientName );
}

