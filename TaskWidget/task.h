#ifndef TASK_H
#define TASK_H

#include <QObject>
#include "period.h"

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(Period const * period, QObject *parent = nullptr);
    ~Task();
protected:
    virtual void executeTask() = 0;
private:
    const Period* period;
    QMetaObject::Connection connection;
};

#endif // TASK_H
