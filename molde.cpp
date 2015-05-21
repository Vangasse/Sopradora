#include "molde.h"
#include "engarrafadora.h"

Molde::Molde(QObject *parent) : QObject(parent)
{

}

Molde::~Molde()
{

}

void Molde::open(){
    Engarrafadora *machine = qobject_cast<Engarrafadora*>(QObject::sender());
    disconnect(machine, &Engarrafadora::openMold, this, &Molde::open);
    qDebug() << Q_FUNC_INFO << "OPEN";
}

void Molde::close(){
    Engarrafadora *machine = qobject_cast<Engarrafadora*>(QObject::sender());
    disconnect(machine, &Engarrafadora::closeMold, this, &Molde::close);
    qDebug() << Q_FUNC_INFO << "CLOSED";
}
