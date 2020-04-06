#include <iostream>
#include "magik.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Magik::~Magik()
{

}

Magik::Magik(string n, double h, double d, double s, double pO)
{
        name = n;
        hp = h;
        damage = d;
        skillPoints = s;
        prawdopodobienstwoSkutecznejObrony = pO;
}

void Magik::atakuj(Magik *br)
{
    srand(time(NULL));
    moc_ataku =this->damage/br->prawdopodobienstwoSkutecznejObrony*(rand()%5+1);
    br->hp -= moc_ataku;
}

void Magik::atak(Magik *broniacy)
{
    this->atakuj(broniacy);
}

void Magik::pokaz_statystyki()
{
    cout << endl;
    cout << "Gracz: " << this->name << endl;
    cout << "Poziom zycia: " << this->hp << endl;
    cout << "Poziom many: " << this->skillPoints << endl;
    cout << "Zadawane obrazenia: " << this->damage << endl;
    cout << "Prawdopodobienstwo skutecznej obrony: " << this->prawdopodobienstwoSkutecznejObrony << endl;
    cout << endl;
}

void Magik::zwiekszenieDamage()
{
    this->damage+=3;
}

void Magik::zwiekszenieHP()
{
    this->hp+=10;
}

void Magik::zwiekszenieMany()
{
    this->skillPoints+=5;
}


void Magik::zwiekszeniePrawdopodobienstwaSkutecznejObrony()
{
    this->prawdopodobienstwoSkutecznejObrony+=3;
}

void Magik::zmniejszenieDamage(Magik *broniacy)
{
    broniacy->damage-=3;
}

void Magik::zmniejszenieMany(Magik *broniacy)
{
    broniacy->skillPoints-=5;
}

void Magik::zmniejszenieprawdopodobienstwaSkutecznejObrony(Magik *broniacy)
{
    broniacy->prawdopodobienstwoSkutecznejObrony-=3;
}

void Magik::sprawdzenie()
{
    if(this->damage<1)
    {
        this->damage = 1;
    }

    if(this->prawdopodobienstwoSkutecznejObrony<1)
    {
        this->prawdopodobienstwoSkutecznejObrony = 1;
    }

    if(this->skillPoints<0)
    {
        this->skillPoints = 0;
    }

}
