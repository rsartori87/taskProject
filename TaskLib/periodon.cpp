#include "periodon.h"

PeriodOn::PeriodOn(PeriodField field, int when) : _field(field)
{
    _whens.push_back(when);
}

PeriodOn::PeriodOn(PeriodField field, std::vector<int> whens) : _field(field), _whens(whens)
{}

bool PeriodOn::match(const QDateTime &dateTime) const
{
    bool result = false;
    int value;
    switch (_field) {
    case PeriodField::YEAR:
        value = dateTime.date().year();
        break;
    case PeriodField::MONTH:
        value = dateTime.date().month();
        break;
    case PeriodField::DAY_OF_MONTH:
        value = dateTime.date().day();
        break;
    case PeriodField::DAY_OF_WEEK:
        value = dateTime.date().dayOfWeek();
        break;
    case PeriodField::HOUR:
        value = dateTime.time().hour();
        break;
    case PeriodField::MINUTE:
        value = dateTime.time().minute();
        break;
    case PeriodField::SECOND:
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
