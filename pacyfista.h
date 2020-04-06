#ifndef PACYFISTA_H
#define PACYFISTA_H

#include <iostream>
#include "magik.h"

using namespace std;

//duzo hp, malo damage

class Pacyfista: public Magik
{
private:
    int licznik = 0;

public:
    Pacyfista():Magik("Mag Pacyfista",150,6){};
    void zaklecieNaPrzeciwnika(Magik *broniacy);
    void zaklecieNaSiebie(Magik *broniacy);
    void atakSpecjalny(Magik *broniacy);
};
#endif
