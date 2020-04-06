#ifndef AGRESOR_H
#define AGRESOR_H

#include <iostream>
#include "magik.h"

using namespace std;

//duzo damage, malo hp

class Agresor: public Magik
{

public:
    Agresor():Magik("Mag Agresor",60,15){};
    void zaklecieNaPrzeciwnika(Magik *broniacy);
    void zaklecieNaSiebie(Magik *broniacy);
    void atakSpecjalny(Magik *broniacy);
};
#endif
