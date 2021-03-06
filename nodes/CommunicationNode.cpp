#include "CommunicationNode.h"
#include "../messages/TextMessage.h"
#include "../Logger.h"
#include "../RandomGenerator.h"

int CommunicationNode::_nextNodeUniqueID = 1; // todo: to be replaced by the MAC ID for instance
RandomGenerator rg_0_3(0, 3);

CommunicationNode::CommunicationNode(const char *name, float x, float y, const SchedulerConfiguration& sc, int talkTimeSlot)
    : _nodeUniqueID(_nextNodeUniqueID++),
      _location(x, y),
      _name(name),
      _nodeClock(0, 0),
      _scheduler(sc, talkTimeSlot)
{
    std::cout << "CommunicationNode:" << name << " " << talkTimeSlot << std::endl;
}

void CommunicationNode::receiveMessage(const std::shared_ptr<TextMessage>& message) {
    const NodeState& state = _scheduler.getState(_nodeClock.currentTime());
    if( SLEEPING == state ) {
        logger << "'" << _name << "' is SLEEPING, so dropped " << message << std::endl;
    } else {
        _messageReceivedList.push_front(message);

        if( TALKING == state ) {
            int newTalkSlot = _scheduler.changeToNextTalkSlot((int) rg_0_3.get());
            logger << "'" << _name << "' received a message while in " << state << " state, so switched to talk slot #" << newTalkSlot << std::endl;
        }
    }
}

const char* CommunicationNode::name() {
    return _name;
}

void CommunicationNode::simulateTime(int dtInMs) {
    _nodeClock.updateTime(dtInMs);
}

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<CommunicationNode>& n) {
    return os << "{'" << n->_nodeClock << " " << n->_name << "' " << n->_location << " id:" << n->_nodeUniqueID << "}";
}
