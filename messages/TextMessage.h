#ifndef TEXT_MESSAGE_H
#define TEXT_MESSAGE_H

#include "Message.h"

#include <iostream>
#include <memory>

class TextMessage : public Message {
private:
    const char* _emitterName;
    const char* _text;
    const char* _recipientName;

public:
    TextMessage(const Location& location, const char *emitterName, const char *text, const char *recipientName,
                std::string messageUniqueId);
    std::shared_ptr<TextMessage> cloneAndIncrement(const Location& emitterLocation) const;

    const char* recipientName() const { return _recipientName; };

    friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TextMessage>& message);
};

std::ostream& operator<<(std::ostream& os,  const std::shared_ptr<TextMessage>& m);

#endif // TEXT_MESSAGE_H