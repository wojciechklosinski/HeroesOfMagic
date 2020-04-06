#ifndef SKILLER_H
#define SKILLER_H

#include <iostream>
#include "magik.h"

using namespace std;

//wyposrodkowany poziom hp i damage

class Skiller: public Magik
{
private:
    double temp;
    double temp1;
public:
    Skiller():Magik("Mag Skiller",100,9){};
    void zaklecieNaPrzeciwnika( Magik *broniacy);
    void zaklecieNaSiebie(Magik *broniacy);
    void atakSpecjalny(Magik *broniacy);
};
#endif
