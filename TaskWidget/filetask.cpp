#include "filetask.h"
#include <QDebug>
#include <QDateTime>

FileTask::FileTask(QString filename, Period *period, QObject *parent) : Task(period, parent), filename(filename)
{}

void FileTask::executeTask() {
    qDebug() << QDateTime::currentDateTime() << " executing on " << filename;
}
