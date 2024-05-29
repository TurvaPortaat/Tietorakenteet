/********************************************************************
/ Kuvaus: Aliohjelma tallentaa listan CSV-muotoisena tiedostoon.
		  T‰m‰n lis‰ksi tehd‰‰n dynaamiset muistinvapautukset.
/ Nimi  : lopeta_tallenna.cpp
/ Pva   : 9.1.2017
/ Teki  : I. Trast
/ Muutos: Kirsi Laaksonen 5/2024
********************************************************************/
#include "lopeta_tallenna.h"
#include <iostream>
#include <fstream>
#include <string>
#include "henkilo.h"


using namespace std;

void shutDown(Henkilo* list, std::string tied) {
	ofstream fos;
	Henkilo* index;
	Henkilo* tuhottava;
	bool pois = false; //Alustetaan pois t‰ss‰

	index = list;

	//tallennetaan ensi lista tiedostoon
	fos.open(tied.c_str());	// .c_str() jotta const char*

	if (!fos.fail()) {
		while (index != NULL) {
			fos << index->nimi << "," << index->osoite << "," << index->puh << endl;
			index = index->next;
		}
	}
	fos.close();

	//t‰m‰n j‰lkeen tehd‰‰n muistivapautukset. Huom! kaikki, mika on 
	//new:lla varattu on delete:ll‰ tuhottava!
	index = list;
	while (index != NULL) {
		tuhottava = index;
		index = index->next; //Siirryt‰‰n seuraavaan solmuun enne nykyisen tuhoamista
		delete tuhottava;
	}
}
/*******************************************************************/