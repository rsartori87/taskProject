#include <QTest>
#include "period.h"
#include "periodon.h"
#include "periodfield.h"
#include <vector>

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
        PeriodOn on(PeriodField::YEAR, 2020);
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnlyOnTheSpecifiedMonth() {
        Period period;
        QDate baseDate(2020, 1, 1);
        QDateTime dt(baseDate);
        PeriodOn on(PeriodField::MONTH, 2);
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnlyOnTheSpecifiedDayOfMonth() {
        Period period;
        QDate baseDate(2020, 1, 1);
        QDateTime dt(baseDate);
        PeriodOn on(PeriodField::DAY_OF_MONTH, 12);
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnlyOnTheSpecifiedDayOfWeek() {
        Period period;
        QDate baseDate(2020, 3, 17); // Tuesday
        QDateTime dt(baseDate);
        PeriodOn on(PeriodField::DAY_OF_WEEK, 1); // Monday
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnlyOnTheSpecifiedHour() {
        Period period;
        QDate baseDate(2020, 3, 17);
        QTime time(13, 0);
        QDateTime dt(baseDate, time);
        PeriodOn on(PeriodField::HOUR, 15);
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnlyOnTheSpecifiedMinute() {
        Period period;
        QDate baseDate(2020, 3, 17);
        QTime time(13, 35);
        QDateTime dt(baseDate, time);
        PeriodOn on(PeriodField::MINUTE, 30);
        period.addTrigger(on);
        QVERIFY(!period.match(dt));
    }

    void periodCanMatchOnlyOnTheSpecifiedSecond() {
        Period period;
        QDate baseDate(2020, 3, 17);
        QTime time(13, 35, 15);
        QDateTime dt(baseDate, time);
        PeriodOn on(PeriodField::SECOND, 10);
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

        PeriodOn onYear(PeriodField::YEAR, 2020);
        period.addTrigger(onYear);
        PeriodOn onMonth(PeriodField::MONTH, 3);
        period.addTrigger(onMonth);
        PeriodOn onDOM(PeriodField::DAY_OF_MONTH, 17);
        period.addTrigger(onDOM);
        PeriodOn onHour(PeriodField::HOUR, 13);
        period.addTrigger(onHour);
        PeriodOn onMinute(PeriodField::MINUTE, 35);
        period.addTrigger(onMinute);
        PeriodOn onSecond(PeriodField::SECOND, 15);
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

        PeriodOn onYear(PeriodField::YEAR, 2020);
        period.addTrigger(onYear);
        std::vector<int> months{ 3, 4 };
        PeriodOn onMonth(PeriodField::MONTH, months);
        period.addTrigger(onMonth);
        std::vector<int> days{ 17, 18 };
        PeriodOn onDOM(PeriodField::DAY_OF_MONTH, days);
        period.addTrigger(onDOM);
        std::vector<int> hours{13, 14 };
        PeriodOn onHour(PeriodField::HOUR, hours);
        period.addTrigger(onHour);
        std::vector<int> minutes{ 35, 36 };
        PeriodOn onMinute(PeriodField::MINUTE, minutes);
        period.addTrigger(onMinute);
        std::vector<int> seconds{ 15, 16 };
        PeriodOn onSecond(PeriodField::SECOND, seconds);
        period.addTrigger(onSecond);

        QVERIFY(period.match(validDateTime));
        QVERIFY(period.match(invalidDateTime));
    }
};

QTEST_MAIN(TaskLibTest)
#include "tst_tasklibtest.moc"
