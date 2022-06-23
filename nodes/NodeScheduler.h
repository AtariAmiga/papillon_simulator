#ifndef NODESCHEDULER_H
#define NODESCHEDULER_H


enum NodeState {
    LISTENING,
    TALKING,
    SLEEPING
};

class NodeScheduler {
public:
    NodeScheduler(int activeTimeInMs, int sleepTimeInMs, int talkTimeSlot, int totalTalkSlots);

    NodeState getState(time_t timestampInMs);

private:
    int _activeTimeInMs;
    int _sleepTimeInMs;
    int _talkTimeSlot;
    int _totalTalkSlots;
};

#endif // NODESCHEDULER_H
