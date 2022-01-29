#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

#include <QMap>

class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);

    int wordStatistics( QString word );

signals:

private:
    QStringList m_wordleList;
};

#endif // MAINCONTROLLER_H
