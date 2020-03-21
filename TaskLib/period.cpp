#include "period.h"

Period::Period()
{}

bool Period::match(const QDateTime &dateTime)
{
    bool result = true;
    for (const auto& c : _conditions) {
        result = result && c.match(dateTime);
    }
    return result;
}

void Period::addTrigger(PeriodOn on)
{
    _conditions.push_back(on);
}
