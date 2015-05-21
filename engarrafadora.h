#ifndef ENGARRAFADORA_H
#define ENGARRAFADORA_H

#include "torneira.h"
#include "bico.h"
#include "molde.h"
#include <QTimer>
#include <QObject>

class Engarrafadora : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool a READ getA WRITE setA NOTIFY aChanged);
    Q_PROPERTY(bool b READ getB WRITE setB NOTIFY bChanged);
    Q_PROPERTY(bool c READ getC WRITE setC NOTIFY cChanged);

public:
    Engarrafadora(QObject *parent = 0);
    ~Engarrafadora();

    void plasticReady(bool ready);

    bool getA() const;
    void setA(bool value);

    bool getB() const;
    void setB(bool value);

    bool getC() const;
    void setC(bool value);

signals:
    void openTap();
    void closeTap();
    void activateBeak();
    void deactivateBeak();
    void openMold();
    void closeMold();

    void aChanged(bool);
    void bChanged(bool);
    void cChanged(bool);
public slots:
    void releaseFluid();
    void ceaseFluid();
    void blow();
    void stopBlowing();
    void bottleReady();
    void bottleToBe();

private:
    Torneira *tap;
    Bico *beak;
    Molde *mold;
    bool a;
    bool b;
    bool c;

};

#endif // ENGARRAFADORA_H
