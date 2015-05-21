#ifndef MOLDE_H
#define MOLDE_H

#include <QObject>
//#include "engarrafadora.h"
#include <QDebug>

class Molde : public QObject
{
    Q_OBJECT
public:
    Molde(QObject *parent = 0);
    ~Molde();
public slots:
    void open();
    void close();
};

#endif // MOLDE_H
