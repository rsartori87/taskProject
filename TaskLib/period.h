#ifndef PERIOD_H
#define PERIOD_H

#include <QDateTime>
#include "periodon.h"
#include <vector>

#include "TaskLib_global.h"


class TASKLIB_EXPORT Period
{
    enum {
        YEAR
    };

public:
    Period();
    bool match(const QDateTime& dateTime);
    void addTrigger(PeriodOn addTrigger);
private:
    std::vector<PeriodOn> _conditions;
};

#endif // PERIOD_H
