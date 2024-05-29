/*******************************************************************/
//HenkiloLista.cpp
/*******************************************************************/
// T‰‰ll‰ on metodit HenkiloLista:aan.

#include "HenkiloLista.h"
#include "henkilo.h"
#include <string>
#include <iostream>

void HenkiloLista::lisaaHenkilo(
	const std::string& nimi, 
	const std::string& osoite, 
	const std::string& puh)

{
	Henkilo* uusi = new Henkilo(
		const_cast<char*>(nimi.c_str()), 
		const_cast<char*>(osoite.c_str()), 
		const_cast<char*>(puh.c_str()));

	uusi->next = head;
	head = uusi;
}

void HenkiloLista::tulostaKaikki() const
{
								//T‰ss‰ tulostan kaiken yksi tieto per rivi, luettavuuden vuoksi.
	Henkilo* current = head;
	while (current != nullptr)
	{
		std::cout << "Nimi: " << current->nimi << std::endl;
		std::cout << ", Osoite: " << current->osoite << std::endl;
		std::cout << ", Puhelin: " << current->puh << std::endl;
		current = current->next;
	}
}

void HenkiloLista::poistaHenkilo(
	const std::string& nimi)
{
	Henkilo* current = head;		// T‰s alotetaan listan alusta
	Henkilo* previous = nullptr;	// Aluks ei oo edellist‰ solmua, duh

	while (current != nullptr &&	
		strcmp(current->nimi, nimi.c_str()) != 0) 
	{
		previous = current;			// Edellinen solmu on nykyinen solmu.
		current = current->next;	// Siirryt‰‰n seuraavaan
	}

	if (current == nullptr)			//Jos p‰‰stiin listan loppuun 
	{
		std::cout << "Henkilˆ‰ nimelt‰ '" << nimi
				  << "' ei lˆytynyt." << std::endl;
		return;
	}

	if (previous == nullptr)		//Jos poistettava solmu on ekana
	{
		head = current->next;		//P‰ivitet‰‰n alku seuraavaan
	}
	else
	{
		previous->next = current->next; //Ohitetaan poistettava solmu
	}

	delete current;					//Muistetaan vapauttaa muisti
	
	std::cout << "Henkilˆ nimelt‰ '"	//'OK'-viesti k‰ytt‰j‰lle.
	<< nimi << "' poistettu." << std::endl;	
}

void HenkiloLista::haeHenkilo(
	const std::string& nimi) const 
{
	Henkilo* current = head;	//Alotetaan alusta

	while (current != nullptr)
	{
		if (strcmp(current->nimi, nimi.c_str()) == 0)
		{
			std::cout << "Nimi: " << current->nimi << std::endl;
			std::cout << "Osoite: " << current->osoite << std::endl;
			std::cout << "Puhelin: " << current->puh << std::endl;
			return;				//Pois funktiosta kun on lˆytyny
		}
		current = current->next;	//Seuraavaan
	}
	// Virhe-ilmoitus k‰ytt‰j‰lle, jos ei lˆydy.
	std::cout << "Henkilˆ‰ nimelt‰ '" << nimi << "' ei lˆytynyt." << std::endl;
}
HenkiloLista::~HenkiloLista() 
{
	Henkilo* current = head;
	while (current != nullptr)
	{
		Henkilo* tuhottava = current;
		current = current->next;
		delete tuhottava;
	}
}
/*******************************************************************/