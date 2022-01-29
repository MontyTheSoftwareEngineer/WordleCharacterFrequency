#include "maincontroller.h"

#include <QFile>
#include <QDebug>

#include <QPair>

MainController::MainController(QObject *parent) : QObject(parent)
{

    //code to load text file
    QFile textFile("wordleList.txt");
    if ( textFile.open( QIODevice::ReadOnly ) )
    {
        m_wordleList = QString( textFile.readAll() ).split("\r\n");
        textFile.close();
    }

    qDebug() << "Wordle size list: " << m_wordleList.size();

    QString letterList = "abcdefghijklmnopqrstuvwxyz";

    //This code was to track which was the best letter per position
    //but it didnt come up with any good particular word as two letters
    //really dominated.
    QMap< int, QPair< QString, int > > bestTracker;
    bestTracker[ 0 ] = QPair<QString,int>( "", 0);
    bestTracker[ 1 ] = QPair<QString,int>( "", 0);
    bestTracker[ 2 ] = QPair<QString,int>( "", 0);
    bestTracker[ 3 ] = QPair<QString,int>( "", 0);
    bestTracker[ 4 ] = QPair<QString,int>( "", 0);

    //iterate through our alphabet A-Z
    foreach ( const QString letter, letterList )
    {
        qDebug() << "Letter " << letter;

        //create counter for letter x position


        //check that letter in each space for every single word
        for ( int spaceCount = 0; spaceCount < 5; spaceCount++ )
        {
            int occurenceRate = 0;
            //iterating through every word in the list
            foreach ( const QString word, m_wordleList )
            {
                if ( word[spaceCount] == letter )
                    occurenceRate++;
            }

            //keeping track of best letter per position.
            if ( occurenceRate > bestTracker[ spaceCount ].second )
                bestTracker[ spaceCount ] = QPair< QString, int >( letter, occurenceRate );

            //debug out result of letter occurence per position
            qDebug() << spaceCount << "," << occurenceRate;
        }
    }

    qDebug() << bestTracker;

}
