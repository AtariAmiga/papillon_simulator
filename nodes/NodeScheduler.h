#ifndef NODESCHEDULER_H
#define NODESCHEDULER_H

#include "NodeState.h"
#include "SchedulerConfiguration.h"
#include <iostream>

class NodeScheduler {
public:
    NodeScheduler(const SchedulerConfiguration& sc, int talkTimeSlot);

    const NodeState & getState(time_t timestampInMs) const;
    inline int talkTimeSlot() const { return _talkTimeSlot; }
    int changeToNextTalkSlot(int i);

private:
    int _activeTimeInMs;
    int _sleepTimeInMs;
    int _talkTimeSlot;
    int _totalTalkSlots;
};

#endif // NODESCHEDULER_H
