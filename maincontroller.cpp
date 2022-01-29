#include "maincontroller.h"

#include <QFile>
#include <QDebug>
#include <thread>

#include <QPair>

MainController::MainController(QObject *parent) : QObject(parent)
{
    QFile textFile("wordleList.txt");
    if ( textFile.open( QIODevice::ReadOnly ) )
    {
        m_wordleList = QString( textFile.readAll() ).split("\r\n");
        textFile.close();
    }

    qDebug() << "Wordle size list: " << m_wordleList.size();
    QString letterList = "abcdefghijklmnopqrstuvwxyz";

    QMap< int, QPair< QString, int > > bestTracker;
    bestTracker[ 0 ] = QPair<QString,int>( "", 0);
    bestTracker[ 1 ] = QPair<QString,int>( "", 0);
    bestTracker[ 2 ] = QPair<QString,int>( "", 0);
    bestTracker[ 3 ] = QPair<QString,int>( "", 0);
    bestTracker[ 4 ] = QPair<QString,int>( "", 0);

    foreach ( const QString letter, letterList )
    {
        qDebug() << "Letter " << letter;
        int occurenceRate = 0;
        for ( int spaceCount = 0; spaceCount < 5; spaceCount++ )
        {
            foreach ( const QString word, m_wordleList )
            {
                if ( word[spaceCount] == letter )
                    occurenceRate++;
            }
            if ( occurenceRate > bestTracker[ spaceCount ].second )
                bestTracker[ spaceCount ] = QPair< QString, int >( letter, occurenceRate );
            qDebug() << spaceCount << "," << occurenceRate;
        }
    }

    qDebug() << bestTracker;

}
