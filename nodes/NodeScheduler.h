#ifndef NODESCHEDULER_H
#define NODESCHEDULER_H

#include "NodeState.h"
#include <iostream>

class NodeScheduler {
public:
    NodeScheduler(int activeTimeInMs, int sleepTimeInMs, int talkTimeSlot, int totalTalkSlots);

    const NodeState & getState(time_t timestampInMs) const;
    inline int talkTimeSlot() const { return _talkTimeSlot; }
    void changeToNextTalkSlot(int i);

private:
    int _activeTimeInMs;
    int _sleepTimeInMs;
    int _talkTimeSlot;
    int _totalTalkSlots;
};

#endif // NODESCHEDULER_H
