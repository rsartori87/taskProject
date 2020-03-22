#include "task.h"

Task::Task(Period const * period, QObject *parent) : QObject(parent), period(period)
{
    connection = connect(period, &Period::triggered, [=]() {
        executeTask();
    });
}

Task::~Task()
{
    disconnect(connection);
}
