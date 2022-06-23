#ifndef NODESCHEDULER_H
#define NODESCHEDULER_H

#include <iostream>

class NodeState {
public:
    explicit NodeState(const char* name): _name(name) {}

    friend std::ostream& operator<<(std::ostream& os,  const NodeState& n);
private:
    const char *_name;
};

inline bool operator!=(const NodeState& lhs, const NodeState& rhs) { return &lhs != &rhs; }
inline bool operator==(const NodeState& lhs, const NodeState& rhs) { return &lhs == &rhs; }
inline std::ostream& operator<<(std::ostream& os,  const NodeState& n) { os << n._name; return os; };

static NodeState LISTENING("LISTENING");
static NodeState TALKING("TALKING");
static NodeState SLEEPING("SLEEPING");

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
