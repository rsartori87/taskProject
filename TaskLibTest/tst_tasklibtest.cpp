#include <QTest>
#include "period.h"
#include "trigger.h"
#include <vector>
#include <utility>

class TaskLibTest : public QObject {
    Q_OBJECT
private slots:
    void periodMatchAlwaysTrueByDefault() {
        Period period;
        QDateTime now = QDateTime::currentDateTime();
        QVERIFY(period.match(now));
    }

    void periodCanMatchOnlyOnTheSpecifiedYear() {
        Period period;
        QDate baseDate(2019, 1, 1);
        QDateTime dt(baseDate);
        Trigger on(Trigger::YEAR, 2020);
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnlyOnTheSpecifiedMonth() {
        Period period;
        QDate baseDate(2020, 1, 1);
        QDateTime dt(baseDate);
        Trigger on(Trigger::MONTH, 2);
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnlyOnTheSpecifiedDayOfMonth() {
        Period period;
        QDate baseDate(2020, 1, 1);
        QDateTime dt(baseDate);
        Trigger on(Trigger::DAY_OF_MONTH, 12);
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnlyOnTheSpecifiedDayOfWeek() {
        Period period;
        QDate baseDate(2020, 3, 17); // Tuesday
        QDateTime dt(baseDate);
        Trigger on(Trigger::DAY_OF_WEEK, 1); // Monday
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnlyOnTheSpecifiedHour() {
        Period period;
        QDate baseDate(2020, 3, 17);
        QTime time(13, 0);
        QDateTime dt(baseDate, time);
        Trigger on(Trigger::HOUR, 15);
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnlyOnTheSpecifiedMinute() {
        Period period;
        QDate baseDate(2020, 3, 17);
        QTime time(13, 35);
        QDateTime dt(baseDate, time);
        Trigger on(Trigger::MINUTE, 30);
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnlyOnTheSpecifiedSecond() {
        Period period;
        QDate baseDate(2020, 3, 17);
        QTime time(13, 35, 15);
        QDateTime dt(baseDate, time);
        Trigger on(Trigger::SECOND, 10);
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnMultipleTrigger() {
        Period period;
        QDate baseDate(2020, 3, 17);
        QTime time(13, 35, 15);
        QDateTime validDateTime(baseDate, time);
        QDate baseDate1(2020, 4, 18);
        QTime time1(14, 36, 16);
        QDateTime invalidDateTime(baseDate1, time1);

        Trigger onYear(Trigger::YEAR, 2020);
        period.addTrigger(onYear);
        Trigger onMonth(Trigger::MONTH, 3);
        period.addTrigger(onMonth);
        Trigger onDOM(Trigger::DAY_OF_MONTH, 17);
        period.addTrigger(onDOM);
        Trigger onHour(Trigger::HOUR, 13);
        period.addTrigger(onHour);
        Trigger onMinute(Trigger::MINUTE, 35);
        period.addTrigger(onMinute);
        Trigger onSecond(Trigger::SECOND, 15);
        period.addTrigger(onSecond);

        QVERIFY(period.match(validDateTime));
        QVERIFY(!period.match(invalidDateTime));
    }

    void periodCanMatchOnMultipleTriggerOnTheSameField() {
        Period period;
        QDate baseDate(2020, 3, 17);
        QTime time(13, 35, 15);
        QDateTime validDateTime(baseDate, time);
        QDate baseDate1(2020, 4, 18);
        QTime time1(14, 36, 16);
        QDateTime invalidDateTime(baseDate1, time1);

        Trigger onYear(Trigger::YEAR, 2020);
        period.addTrigger(onYear);
        std::vector<int> months{ 3, 4 };
        Trigger onMonth(Trigger::MONTH, std::move(months));
        period.addTrigger(onMonth);
        std::vector<int> days{ 17, 18 };
        Trigger onDOM(Trigger::DAY_OF_MONTH, std::move(days));
        period.addTrigger(onDOM);
        std::vector<int> hours{13, 14 };
        Trigger onHour(Trigger::HOUR, std::move(hours));
        period.addTrigger(onHour);
        std::vector<int> minutes{ 35, 36 };
        Trigger onMinute(Trigger::MINUTE, std::move(minutes));
        period.addTrigger(onMinute);
        std::vector<int> seconds{ 15, 16 };
        Trigger onSecond(Trigger::SECOND, std::move(seconds));
        period.addTrigger(onSecond);

        QVERIFY(period.match(validDateTime));
        QVERIFY(period.match(invalidDateTime));
    }
};

QTEST_MAIN(TaskLibTest)
#include "tst_tasklibtest.moc"
