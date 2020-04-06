#include "hazardzista.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Hazardzista::atakSpecjalny(Magik *broniacy)  //50% szans na zabicie przeciwnika
{
        srand(time(NULL));
        los = rand()%2;
        if(los == 0)
        {
            broniacy->hp = 0;
        }
}

void Hazardzista::zaklecieNaPrzeciwnika(Magik *broniacy) //zabiera przeciwnikowi zycie w zakresie 10-40%
{
    srand(time(NULL));
    los = rand()%30+10;
    broniacy->hp = broniacy->hp*(100-los)*0.01;
}

void Hazardzista::zaklecieNaSiebie(Magik *broniacy) //dodaje zycie w zakresie 10-40%
{
    srand(time(NULL));
    los = rand()%30+10;
    this->hp = this->hp*(100-los)*0.01;
}
