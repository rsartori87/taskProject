#include "stringtask.h"

#include <QDebug>
#include <QDateTime>

StringTask::StringTask(const QString& message, Period const *period, QObject *parent) : Task(period, parent), message(message)
{}

void StringTask::executeTask()
{
    qDebug() << QDateTime::currentDateTime() << " " << message;
}

