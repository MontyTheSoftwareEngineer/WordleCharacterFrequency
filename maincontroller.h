#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

#include <QMap>
#include <QThread>
#include "task.h"

class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);

    int wordStatistics( QString word );

signals:

private:
    QStringList m_wordleList;
    QMap< QThread *, Task *> m_multiThreadMap;
};

#endif // MAINCONTROLLER_H
