#ifndef FILETASK_H
#define FILETASK_H

#include "task.h"


class FileTask : public Task
{
    Q_OBJECT
public:
    FileTask(const QString& filename, Period const * period, QObject* parent = nullptr);
protected:
    void executeTask() override;
private:
    const QString filename;
};

#endif // FILETASK_H
