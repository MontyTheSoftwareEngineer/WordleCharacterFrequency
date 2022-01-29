#include <QCoreApplication>

#include <QDebug>
#include "maincontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainController mController;

    return a.exec();
}
