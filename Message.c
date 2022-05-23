#include "NEW.h"
#include "Message.h"
#include "Terminal.h"

struct Message* Message_new(struct Location* location, const char* emitterName, const char* text, const char* recipientName) {
    struct Message* self = NEW(Message);

    self->emittedLocation = Location_clone(location);
    self->emitterName = emitterName;
    self->text = text;
    self->recipientName = recipientName;
    self->hopsCount = 0;

    return self;
}

struct Message* Message_clone_and_increment(struct Message* self, struct Location* emitterLocation) {
    struct Message* clone = NEW(Message);

    clone->emittedLocation = Location_clone(emitterLocation);
    // ----
    clone->emitterName = self->emitterName;
    clone->text = self->text;
    clone->recipientName = self->recipientName;
    clone->hopsCount = self->hopsCount + 1;

    return clone;
}

void Message_println(struct Message* self) {
    assert(self != NULL );
    printf("Message ");
    Location_print(self->emittedLocation);
    printf(": %s '%s' > %s\n", self->emitterName, self->text, self->recipientName );
}

