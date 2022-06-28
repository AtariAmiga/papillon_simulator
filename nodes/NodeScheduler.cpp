#include <ctime>
#include "NodeScheduler.h"

NodeScheduler::NodeScheduler(const SchedulerConfiguration& sc, int talkTimeSlot) {
    //   activeTimeInMs                   sleepTimeInMs
    // ++++++++++++++----------------------------------------------
    // \/\/\/\/\/\/\/ totalTalkSlots, here: 7
    //   ^^ talkTimeSlot, here #1 (first is #0)

    _activeTimeInMs = sc.activeTimeInMs;
    _sleepTimeInMs = sc.sleepTimeInMs;
    _totalTalkSlots = sc.totalTalkSlots;

    _talkTimeSlot = talkTimeSlot;
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

int NodeScheduler::changeToNextTalkSlot(int i) {
    _talkTimeSlot += i;
    if( _talkTimeSlot == _totalTalkSlots )
        _talkTimeSlot = 0;

    return _talkTimeSlot;
}
