#ifndef STRINGTASK_H
#define STRINGTASK_H

#include "task.h"


class StringTask : public Task
{
    Q_OBJECT
public:
    StringTask(const QString& message, Period const * period, QObject* parent = nullptr);
protected:
    void executeTask() override;
private:
    const QString message;
};

#endif // STRINGTASK_H
