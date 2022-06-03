#include "CommunicationNode.h"
#include "TextMessage.h"
#include "Location.h"

int CommunicationNode::_nextNodeUniqueID = 1; // todo: to be replaced by the MAC ID for instance

CommunicationNode::CommunicationNode(const char *name, float x, float y)
    : _nodeUniqueID(_nextNodeUniqueID++),
      _location(x, y),
      _name(name)
{
}

void CommunicationNode::receiveMessage(const std::shared_ptr<TextMessage>& message) {
    _messageList.push_front(message);
}

const char *CommunicationNode::name() {
    return _name;
}

void CommunicationNode::simulateTime(int dtInMs) {
    _nodeTime += dtInMs;
}

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<CommunicationNode>& n) {
    return os << "{'" << n->_nodeTime << " " << n->_name << "' " << n->_location << " id:" << n->_nodeUniqueID << "}";
}
