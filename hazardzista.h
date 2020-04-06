#ifndef HAZARDZISTA_H
#define HAZARDZISTA_H

#include <iostream>
#include "magik.h"

using namespace std;

class Hazardzista: public Magik
{
private:
    int los;
public:
    Hazardzista():Magik("Mag   Hazardzista",100,9){};
    void zaklecieNaPrzeciwnika(Magik *broniacy);
    void zaklecieNaSiebie(Magik *broniacy);
    void atakSpecjalny(Magik *broniacy);
};

#endif // HAZARDZISTA_H
