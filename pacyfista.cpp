#include <iostream>
#include "pacyfista.h"

using namespace std;


void Pacyfista::atakSpecjalny(Magik *broniacy) //zwieksz ilosc pkt hp o 100
{
    this->hp+=100;
}

void Pacyfista::zaklecieNaPrzeciwnika(Magik *broniacy) //dodanie przeciwnikowi 2pkt damage i zabranie 25pkt hp
{
    broniacy->damage+=2;
    broniacy->hp-=25;
}

void Pacyfista::zaklecieNaSiebie(Magik *broniacy) //zbiera punkty do ataku ostatecznego, ktory powoduje smierc przeciwnika + zwieksza prawdopodobienstwo obrony o 20%
{
    this->prawdopodobienstwoSkutecznejObrony = this->prawdopodobienstwoSkutecznejObrony*1.2;
    licznik++;
    if(licznik == 4)
    {
        broniacy->hp = 0;
    }
}
