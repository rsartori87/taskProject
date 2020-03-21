#ifndef TASKLIB_GLOBAL_H
#define TASKLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TASKLIB_LIBRARY)
#  define TASKLIB_EXPORT Q_DECL_EXPORT
#else
#  define TASKLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // TASKLIB_GLOBAL_H
