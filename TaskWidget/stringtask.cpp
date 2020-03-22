#include "stringtask.h"

#include <QDebug>
#include <QDateTime>

StringTask::StringTask(QString&& message, Period *period, QObject *parent) : Task(period, parent), message(message)
{}

void StringTask::executeTask()
{
    qDebug() << QDateTime::currentDateTime() << " " << message;
}

