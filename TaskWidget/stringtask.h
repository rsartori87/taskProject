#ifndef STRINGTASK_H
#define STRINGTASK_H

#include "task.h"


class StringTask : public Task
{
    Q_OBJECT
public:
    StringTask(QString message, Period* period, QObject* parent = nullptr);
private:
    void executeTask() override;
    QString message;
};

#endif // STRINGTASK_H
