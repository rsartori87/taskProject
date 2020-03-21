#ifndef PERIOD_H
#define PERIOD_H

#include <QObject>
#include <QDateTime>
#include "periodon.h"
#include <vector>

#include "TaskLib_global.h"

class QTimer;

class TASKLIB_EXPORT Period : public QObject
{
    Q_OBJECT
public:
    Period(QObject* parent = nullptr);
    bool match(const QDateTime& dateTime);
    void addTrigger(PeriodOn addTrigger);
signals:
    void triggered();
private:
    std::vector<PeriodOn> _conditions;
    QTimer* timer;
};

#endif // PERIOD_H
