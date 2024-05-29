#pragma once
/********************************************************************/
//HenkiloLista.h//
/********************************************************************/


//T�m� luokka tarjoaa metodit henkil�iden hallintaan.
#ifndef HENKILOLISTA_H
#define HENKILOLISTA_H

#include "henkilo.h"
#include <string>

class HenkiloLista
{
public:
	Henkilo* head; //T�s listan p��, thats y head
	
	HenkiloLista() : head(nullptr) {} //Konstruktori

	//T�ss� metodeja mill� hallita
	void lisaaHenkilo(const std::string& nimi, const std::string& osoite, const std::string& puh);
	void tulostaKaikki() const; //tulostellaa kaik?
	void poistaHenkilo(const std::string& nimi); //poista stringi nimi-tiedon mukaan
	void haeHenkilo(const std::string& nimi) const; //hae henkilo listasta nimen perusteella ja tulosta

	~HenkiloLista(); //Hajotin
};

#endif	//HENKILOLISTA_H

