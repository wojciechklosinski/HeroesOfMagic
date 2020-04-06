#include <iostream>
#include "skiller.h"

using namespace std;


void Skiller::atakSpecjalny(Magik *broniacy) // zabiera przeciwnikowi hp z przedzialu <20,100>
{
    temp = broniacy->prawdopodobienstwoSkutecznejObrony;
    temp1 = this->damage;
    broniacy->prawdopodobienstwoSkutecznejObrony = 1;
    this->damage = 20;
    this->atak(broniacy);
    broniacy->prawdopodobienstwoSkutecznejObrony = temp;
    this->damage = temp1;
}

void Skiller::zaklecieNaPrzeciwnika(Magik *broniacy) //pozwala wykonac 2 zwykle ataki
{
    this->atak(broniacy);
    this->atak(broniacy);
}

void Skiller::zaklecieNaSiebie(Magik *broniacy) //zwieksza swoj poziom zycia o 50%
{
    this->hp = this->hp*1.5;
}
