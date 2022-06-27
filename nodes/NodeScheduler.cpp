#include <ctime>
#include "NodeScheduler.h"

NodeScheduler::NodeScheduler(int activeTimeInMs, int sleepTimeInMs, int talkTimeSlot, int totalTalkSlots) {
    //   activeTimeInMs                   sleepTimeInMs
    // ++++++++++++++----------------------------------------------
    // \/\/\/\/\/\/\/ totalTalkSlots, here: 7
    //   ^^ talkTimeSlot, here #1 (first is #0)

    _activeTimeInMs = activeTimeInMs;
    _sleepTimeInMs = sleepTimeInMs;
    _talkTimeSlot = talkTimeSlot;
    _totalTalkSlots = totalTalkSlots;
}

const NodeState & NodeScheduler::getState(time_t timestampInMs) const {
    const auto fullCycleTimeInMs = _activeTimeInMs + _sleepTimeInMs;
    const auto locationInCycle = (int) (timestampInMs % fullCycleTimeInMs);

    if( locationInCycle < _activeTimeInMs ) {
        auto slotSize = _activeTimeInMs / _totalTalkSlots;
        if( locationInCycle / slotSize == _talkTimeSlot)
            return TALKING;

        return LISTENING;
    }
    return SLEEPING;
}

void NodeScheduler::changeToNextTalkSlot(int i) {
    _talkTimeSlot += i;
    if( _talkTimeSlot == _totalTalkSlots )
        _talkTimeSlot = 0;
}
