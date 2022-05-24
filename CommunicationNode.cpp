#include "CommunicationNode.h"
#include "Message.h"


void CommunicationNode::receiveMessage(Message *message) {
    _messageList.push_front(message);
}
