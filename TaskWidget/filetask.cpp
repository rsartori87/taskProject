#include "filetask.h"
#include <QDebug>
#include <QDateTime>
#include <QFile>

FileTask::FileTask(const QString& filename, Period const *period, QObject *parent) : Task(period, parent), filename(filename)
{}

void FileTask::executeTask() {
    if (!QFile::exists(filename))
        qDebug() << QDateTime::currentDateTime() << " file not found " << filename;
}
