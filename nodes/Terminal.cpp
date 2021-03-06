#include "Terminal.h"
#include "../world/World.h"
#include "../messages/TextMessage.h"
#include "../world/Location.h"
#include "../Logger.h"

#include <cstring>
#include <iostream>
#include <cassert>
#include <memory>

Terminal::Terminal(const char *name, float x, float y, const SchedulerConfiguration& sc, int talkTimeSlot) :
        CommunicationNode(name, x, y, sc, talkTimeSlot)
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

void Terminal::runOneStep(std::list<std::shared_ptr<TextMessage>>& emittedMessageList) {
    const NodeState& state = _scheduler.getState(_nodeClock.currentTime());

    logger << "'" << _name << "' " << _nodeClock << " " << state << " " << _messageToEmitList.size() << std::endl;

    if( SLEEPING == state )
        return;

    if( ! _messageReceivedList.empty() ) {
        logger.stepIn();
        // Process received messages
        while (!_messageReceivedList.empty()) {
            auto message = _messageReceivedList.front();
            _messageReceivedList.pop_front();

            if (strcmp(message->recipientName(), _name) == 0) {
                if (_receivedMessageIds.count(message->messageUniqueId()) == 0) {
                    logger << "received: " << message << std::endl;
                    _receivedMessageIds.insert(message->messageUniqueId());
                }
            }
        }
        logger.stepOut();
    }

    if( TALKING == state ) {
        logger.stepIn();
        for (const auto &m: _messageToEmitList) {
            logger << "emitting: " << m << std::endl;
            emittedMessageList.push_front(m);
        }
        logger.stepOut();
        _messageToEmitList.clear();
    }
}