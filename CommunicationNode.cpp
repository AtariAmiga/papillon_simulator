#include "CommunicationNode.h"
#include "Message.h"
#include "Location.h"

int CommunicationNode::_nextNodeUniqueID = 1;

CommunicationNode::CommunicationNode(const char* name, World* worldOwner, float x, float y)
    : _nodeUniqueID(_nextNodeUniqueID++),
      _location(new Location(x, y)),
      _name(name),
      _worldOwner(worldOwner)
{
}

void CommunicationNode::receiveMessage(Message *message) {
    _messageList.push_front(message);
}

std::ostream& operator<<(std::ostream& os, const CommunicationNode* n) {
    return os << "'" << n->_name << "' " << n->_location << " id:" << n->_nodeUniqueID;
}
