#ifndef TORNEIRA_H
#define TORNEIRA_H

#include <QObject>
//#include "engarrafadora.h"
#include <QDebug>

class Torneira : public QObject
{
    Q_OBJECT
public:
    Torneira(QObject *parent = 0);
    ~Torneira();
public slots:
    void open();
    void close();
};

#endif // TORNEIRA_H
