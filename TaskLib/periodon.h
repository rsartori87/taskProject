#ifndef PERIODON_H
#define PERIODON_H

#include <QDateTime>
#include <vector>

#include "TaskLib_global.h"
#include "periodfield.h"

class TASKLIB_EXPORT PeriodOn
{
public:
    PeriodOn(PeriodField field, int when);
    PeriodOn(PeriodField field, std::vector<int> whens);
    bool match(const QDateTime& dateTime) const;
private:
    PeriodField _field;
    std::vector<int> _whens;
};

#endif // PERIODON_H
