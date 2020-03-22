#include "filetask.h"
#include <QDebug>
#include <QDateTime>
#include <QFile>

FileTask::FileTask(QString&& filename, Period *period, QObject *parent) : Task(period, parent), filename(filename)
{}

void FileTask::executeTask() {
    if (!QFile::exists(filename))
        qDebug() << QDateTime::currentDateTime() << " file not found " << filename;
}
