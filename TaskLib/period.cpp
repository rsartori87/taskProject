#include "period.h"
#include <QTimer>

constexpr int SECOND_DURATION = 1000;

Period::Period(QObject* parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        if (match(QDateTime::currentDateTime())) {
            emit triggered();
        }
    });
    timer->start(SECOND_DURATION);
}

bool Period::match(const QDateTime &dateTime)
{
    bool result = true;
    for (const auto& c : _conditions) {
        result = result && c.match(dateTime);
    }
    return result;
}

void Period::addTrigger(Trigger on)
{
    _conditions.push_back(on);
}
