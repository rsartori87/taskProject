#ifndef TASK_H
#define TASK_H

#include <QObject>
#include "period.h"

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(Period* period, QObject *parent = nullptr);
private:
    virtual void executeTask() = 0;

signals:

private:
    Period* period;
};

#endif // TASK_H
