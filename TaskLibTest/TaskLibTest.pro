QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_tasklibtest.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../TaskLib/release/ -lTaskLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../TaskLib/debug/ -lTaskLib
else:unix: LIBS += -L$$OUT_PWD/../TaskLib/ -lTaskLib

INCLUDEPATH += $$PWD/../TaskLib
DEPENDPATH += $$PWD/../TaskLib
