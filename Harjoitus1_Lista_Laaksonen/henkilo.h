#pragma once
#ifndef HENKILO_H
#define HENKILO_H
/********************************************************************
/ Kuvaus: Henkilo-luokan prototyyppi. Sis‰lt‰‰ tiedon myˆs merkkijonojen pituudesta
/ Nimi : henkilo.h
/ Pva : 9.1.2017
/ Teki : I. Trast
/ Muutos: Kirsi Laaksonen 5/2024
********************************************************************/

#include <cstring>
#define MPITUUS 100

using namespace std;

class Henkilo
{
public:
    char nimi[MPITUUS];
    char osoite[MPITUUS];
    char puh[MPITUUS];

    Henkilo* next;

    Henkilo() : next(nullptr)  // Oletusmuodostin
    {
        nimi[0] = '\0';
        osoite[0] = '\0';
        puh[0] = '\0';
    }

    Henkilo(char* nimiVal, char* osoiteVal, char* puhVal) : next(nullptr) //Parametrillinen muodostin, eli kopsataan merkkijonot paikoillee
    {                                                       //alustetaan merkkijonot tyhjiksi
        strncpy_s(nimi, nimiVal, MPITUUS);    //strncpy_s, est‰‰ buffer overflow'n
        strncpy_s(osoite, osoiteVal, MPITUUS);
        strncpy_s(puh, puhVal, MPITUUS);
    }

    ~Henkilo() //Oletushajoitin
    {
        // Dynaamista muistia ei ole varattu, ei tarvitse tehd‰ mit‰‰n
    }
};

#endif  //HENKILO_H
