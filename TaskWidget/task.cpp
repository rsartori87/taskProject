#include "task.h"

Task::Task(Period* period, QObject *parent) : QObject(parent), period(period)
{
    connect(period, &Period::triggered, [=]() {
        executeTask();
    });
}
