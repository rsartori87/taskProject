#ifndef TASK_H
#define TASK_H

#include <QObject>
#include "period.h"

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(Period* period, QObject *parent = nullptr);
    ~Task();
private:
    virtual void executeTask() = 0;

signals:

private:
    Period* period;
    QMetaObject::Connection connection;
};

#endif // TASK_H
