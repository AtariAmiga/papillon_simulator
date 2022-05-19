#include "NEW.h"
#include "Message.h"
#include "Terminal.h"

struct Message* Message_new(const char* emitterName, const char* text, const char* recipientName) {
    struct Message* this = NEW(Message);

    this->emitterName = emitterName;
    this->text = text;
    this->recipientName = recipientName;

    return this;
}

void Message_println(struct Message* this) {
    assert(this != NULL );
    printf("Message: %s '%s' > %s\n", this->emitterName, this->text, this->recipientName );
}

