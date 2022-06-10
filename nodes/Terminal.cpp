#include "Terminal.h"
#include "../world/World.h"
#include "../messages/TextMessage.h"
#include "../world/Location.h"

#include <cstring>
#include <iostream>
#include <cassert>
#include <memory>

Terminal::Terminal(const char *name, float x, float y) :
        CommunicationNode(name, x, y)
{
}

void Terminal::newMessage(const char *text, const char *recipient) {
    assert(text != nullptr);
    assert(recipient != nullptr);

    std::string messageUniqueId = nextMessageUniqueId();

    auto message = std::make_shared<TextMessage>(_location, _name, text, recipient, messageUniqueId);
    _messageToEmitList.push_front(message);
}

std::string Terminal::nextMessageUniqueId() {
    return std::to_string(_nodeUniqueID) + "." + std::to_string(_nextMessageNum++);
}

void Terminal::runOneStep(std::list<std::shared_ptr<TextMessage>> &emittedMessageList) {
    std::cout << "'" << name() << "' " << _nodeClock << " processing:" << std::endl;

    // Process received messages
    while (!_messageReceivedList.empty()) {
        auto message = _messageReceivedList.front();
        _messageReceivedList.pop_front();

        if (strcmp(message->recipientName(), _name) == 0) {
            if (_receivedMessageIds.count(message->messageUniqueId()) == 0) {
                std::cout << "\treceived: " << message << std::endl;
                _receivedMessageIds.insert(message->messageUniqueId());
            }
        }
    }

    for (const auto &m: _messageToEmitList) {
        std::cout << "\temitting: " << m << std::endl;
        emittedMessageList.push_front(m);
    }
    _messageToEmitList.clear();
}