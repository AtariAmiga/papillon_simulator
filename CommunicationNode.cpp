#include "CommunicationNode.h"
#include "Message.h"


void CommunicationNode::receiveMessage(Message *message) {
    messageList.push_front(message);
}
