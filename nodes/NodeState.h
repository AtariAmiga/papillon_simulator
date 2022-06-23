#ifndef NODESTATE_H
#define NODESTATE_H

#include <iostream>

class NodeState {
public:
    explicit NodeState(const char* name): _name(name) {}

    friend std::ostream& operator<<(std::ostream& os,  const NodeState& n);

private:
    explicit NodeState(const NodeState&) {}

    const char *_name;
};

inline bool operator!=(const NodeState& lhs, const NodeState& rhs) { return &lhs != &rhs; }
inline bool operator==(const NodeState& lhs, const NodeState& rhs) { return &lhs == &rhs; }
inline std::ostream& operator<<(std::ostream& os,  const NodeState& n) { os << n._name; return os; };

extern NodeState LISTENING;
extern NodeState TALKING;
extern NodeState SLEEPING;

#endif // NODESTATE_H
