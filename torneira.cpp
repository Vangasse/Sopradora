#include "torneira.h"
#include "engarrafadora.h"

Torneira::Torneira(QObject *parent) : QObject(parent)
{

}

Torneira::~Torneira()
{

}

void Torneira::open(){
    Engarrafadora *machine = qobject_cast<Engarrafadora*>(QObject::sender());
    disconnect(machine, &Engarrafadora::openTap, this, &Torneira::open);
    qDebug() << Q_FUNC_INFO << "FEEDING STARTED";
}

void Torneira::close(){
    Engarrafadora *machine = qobject_cast<Engarrafadora*>(QObject::sender());
    disconnect(machine, &Engarrafadora::closeTap, this, &Torneira::close);
    qDebug() << Q_FUNC_INFO << "FEEDING CEASED";
}
