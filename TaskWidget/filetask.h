#ifndef FILETASK_H
#define FILETASK_H

#include "task.h"


class FileTask : public Task
{
    Q_OBJECT
public:
    FileTask(QString filename, Period* period, QObject* parent = nullptr);
private:
    void executeTask() override;
    QString filename;
};

#endif // FILETASK_H
