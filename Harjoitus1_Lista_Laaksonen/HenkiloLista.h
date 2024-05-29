#pragma once
/********************************************************************/
//HenkiloLista.h//
/********************************************************************/


//Tämä luokka tarjoaa metodit henkilöiden hallintaan.
#ifndef HENKILOLISTA_H
#define HENKILOLISTA_H

#include "henkilo.h"
#include <string>

class HenkiloLista
{
public:
	Henkilo* head; //Täs listan pää, thats y head
	
	HenkiloLista() : head(nullptr) {} //Konstruktori

	//Tässä metodeja millä hallita
	void lisaaHenkilo(const std::string& nimi, const std::string& osoite, const std::string& puh);
	void tulostaKaikki() const; //tulostellaa kaik?
	void poistaHenkilo(const std::string& nimi); //poista stringi nimi-tiedon mukaan
	void haeHenkilo(const std::string& nimi) const; //hae henkilo listasta nimen perusteella ja tulosta

	~HenkiloLista(); //Hajotin
};

#endif	//HENKILOLISTA_H

