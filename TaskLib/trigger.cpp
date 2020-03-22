#include "trigger.h"

Trigger::Trigger(TriggerField field, int when) : _field(field)
{
    _whens.push_back(when);
}

Trigger::Trigger(TriggerField field, std::vector<int>&& whens) : _field(field), _whens(whens)
{}

bool Trigger::match(const QDateTime &dateTime) const
{
    bool result = false;
    int value;
    switch (_field) {
    case TriggerField::YEAR:
        value = dateTime.date().year();
        break;
    case TriggerField::MONTH:
        value = dateTime.date().month();
        break;
    case TriggerField::DAY_OF_MONTH:
        value = dateTime.date().day();
        break;
    case TriggerField::DAY_OF_WEEK:
        value = dateTime.date().dayOfWeek();
        break;
    case TriggerField::HOUR:
        value = dateTime.time().hour();
        break;
    case TriggerField::MINUTE:
        value = dateTime.time().minute();
        break;
    case TriggerField::SECOND:
        value = dateTime.time().second();
        break;
    default:
        return result;
    }

    for (const auto& when : _whens) {
        result = result || (value == when);
    }

    return result;
}
