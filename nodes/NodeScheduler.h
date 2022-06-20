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

    NodeState updateTime(int dtInMs);

private:
    int _activeTimeInMs;
    int _sleepTimeInMs;
    int _talkTimeSlot;
    int _totalTalkSlots;

    time_t _timestampInMs;
};

#endif // NODESCHEDULER_H
