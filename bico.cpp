#include "bico.h"
#include "engarrafadora.h"

Bico::Bico(QObject *parent) : QObject(parent)
{

}

Bico::~Bico()
{

}

void Bico::open(){
    Engarrafadora *machine = qobject_cast<Engarrafadora*>(QObject::sender());
    disconnect(machine, &Engarrafadora::activateBeak, this, &Bico::open);
    qDebug() << Q_FUNC_INFO << "BLOWING";
}

void Bico::close(){
    Engarrafadora *machine = qobject_cast<Engarrafadora*>(QObject::sender());
    disconnect(machine, &Engarrafadora::deactivateBeak, this, &Bico::close);
    qDebug() << Q_FUNC_INFO << "BLOWING CEASED";
}
