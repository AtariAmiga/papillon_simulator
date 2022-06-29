#ifndef SCHEDULERCONFIGURATION_H
#define SCHEDULERCONFIGURATION_H


class SchedulerConfiguration {
public:
    explicit SchedulerConfiguration(int activeTimeInMs = 100, int sleepTimeInMs = 50, int totalTalkSlots = 10)
        :_activeTimeInMs(activeTimeInMs),
        _sleepTimeInMs(sleepTimeInMs),
        _totalTalkSlots(totalTalkSlots)
    {}

    int _activeTimeInMs;
    int _sleepTimeInMs;
    int _totalTalkSlots;
};

#endif // SCHEDULERCONFIGURATION_H
