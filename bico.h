#ifndef BICO_H
#define BICO_H

#include <QObject>
//#include "engarrafadora.h"
#include <QDebug>

class Bico : public QObject
{
    Q_OBJECT
public:
    Bico(QObject *parent = 0);
    ~Bico();
public slots:
    void open();
    void close();
};

#endif // BICO_H
