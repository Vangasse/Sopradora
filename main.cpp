#include <QCoreApplication>
#include <QTimer>
#include "engarrafadora.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    Engarrafadora *e = new Engarrafadora;
    e->setParent(&app);

    e->plasticReady(true);

    return app.exec();
}
