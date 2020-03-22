#ifndef PERIODON_H
#define PERIODON_H

#include <QDateTime>
#include <vector>

#include "TaskLib_global.h"

class TASKLIB_EXPORT Trigger
{
public:
    enum TriggerField {
        YEAR,
        MONTH,
        DAY_OF_MONTH,
        DAY_OF_WEEK,
        HOUR,
        MINUTE,
        SECOND
    };
    Trigger(TriggerField field, int when);
    Trigger(TriggerField field, std::vector<int>&& whens);
    bool match(const QDateTime& dateTime) const;
private:
    TriggerField _field;
    std::vector<int> _whens;
};

#endif // PERIODON_H
