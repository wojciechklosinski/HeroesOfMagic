#include <iostream>
#include "agresor.h"

using namespace std;


void Agresor::atakSpecjalny(Magik *broniacy)  //powododuje zwiekszenie damage o 30, zaatakowanie przeciwnika i powrot do dawnego poziomu damage
{
        this->damage += 30;
        this->atak(broniacy);
        this->damage -= 30;
}

void Agresor::zaklecieNaPrzeciwnika(Magik *broniacy) //zmniejsza poziom hp przeciwnika o 25%
{
        broniacy->hp = broniacy->hp*0.75;
}

void Agresor::zaklecieNaSiebie(Magik *broniacy) //powoduje zwiekszenie ilosci many o 50%
{
        this->skillPoints = this->skillPoints*1.5;
        this->skillPoints+=10;
}
