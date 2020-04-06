#ifndef MAGIK_H
#define MAGIK_H

#include <iostream>

using namespace std;

class Magik
{
public:
    string name;
    double hp;
    double damage;
    double skillPoints;
    double prawdopodobienstwoSkutecznejObrony;

    void atak(Magik *broniacy); //funkcja powoduje atak na przeciwnika, brane sa pod uwage prawdopodobienstwo ataku krytycznego, prawdopodobienstwo skutecznej obrony oraz damage
    void pokaz_statystyki(); //funkcja wyswietla statystyki postaci
    void zwiekszenieHP();
    void zwiekszenieDamage();
    void zwiekszenieMany();
    void zwiekszeniePrawdopodobienstwaSkutecznejObrony();
    void zmniejszenieDamage(Magik *broniacy);
    void zmniejszenieMany(Magik *broniacy);
    void zmniejszenieprawdopodobienstwaSkutecznejObrony(Magik *broniacy);


    virtual void zaklecieNaPrzeciwnika(Magik *broniacy)=0; //potrzeba 10many zeby to zrobic
    virtual void zaklecieNaSiebie(Magik *broniacy)=0; //potrzeba 10 many zeby to zrobic
    virtual void atakSpecjalny(Magik *broniacy)=0; //potrzeba 30 many zeby to zrobic

    Magik(string = "Demo", double = 100, double = 10, double = 10, double pO = 10);
    virtual ~Magik();
    void sprawdzenie();
private:
    void atakuj(Magik *br);
    double moc_ataku;
};
#endif


