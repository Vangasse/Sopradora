//O SINAL EMITIDO PELO SETA DEVE CHAMAR O RELEASEFLUID

#include "engarrafadora.h"


Engarrafadora::Engarrafadora(QObject *parent) : QObject(parent)
{
    tap = new Torneira(this);
    beak = new Bico(this);
    mold = new Molde(this);
    a = false;
    b = false;
    c = true;
    connect(this, &Engarrafadora::openTap, tap, &Torneira::open);
    connect(this, &Engarrafadora::closeTap, tap, &Torneira::close);
    connect(this, &Engarrafadora::activateBeak, beak, &Bico::open);
    connect(this, &Engarrafadora::deactivateBeak, beak, &Bico::close);
    connect(this, &Engarrafadora::openMold, mold, &Molde::open);
    connect(this, &Engarrafadora::closeMold, mold, &Molde::close);
}

Engarrafadora::~Engarrafadora()
{

}
bool Engarrafadora::getA() const
{
    return a;
}

void Engarrafadora::setA(bool value)
{
    a = value;
    emit this->aChanged(value);
    if(a == true)emit this->openTap();
    else emit this->closeTap();
}

bool Engarrafadora::getB() const
{
    return b;
}

void Engarrafadora::setB(bool value)
{
    b = value;
    emit this->bChanged(value);
    if(b == true)emit this->activateBeak();
    else emit this->deactivateBeak();
}

bool Engarrafadora::getC() const
{
    return c;
}

void Engarrafadora::setC(bool value)
{
    c = value;
    emit this->cChanged(value);
    if(c == false)emit this->closeMold();
    else emit this->openMold();
}

void Engarrafadora::plasticReady(bool ready){
    if(ready){
        QTimer *t = new QTimer(this);

        t->setInterval(5000);

        QObject::connect(t, &QTimer::timeout, this, &Engarrafadora::ceaseFluid);

        releaseFluid();
        t->start();
    }
}

void Engarrafadora::releaseFluid(){
    setA(true);
}

void Engarrafadora::ceaseFluid(){
    setA(false);
    QTimer *t = new QTimer(this);

    t->setInterval(500);

    QObject::connect(t, &QTimer::timeout, this, &Engarrafadora::stopBlowing);

    bottleToBe();
    blow();
    t->start();
}

void Engarrafadora::blow(){
    setB(true);
}

void Engarrafadora::stopBlowing(){
    setB(false);
    QTimer *t = new QTimer(this);

    t->setInterval(4000);

    QObject::connect(t, &QTimer::timeout, this, &Engarrafadora::bottleReady);

    t->start();
}

void Engarrafadora::bottleReady(){
    setC(true);
}

void Engarrafadora::bottleToBe(){
    setC(false);
}
