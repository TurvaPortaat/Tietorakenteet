// Harjoitus1_Lista_Laaksonen.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma execution_character_set("utf-8")
#include <iostream>
#include <string>
#include "henkilo.h"
#include "HenkiloLista.h"
#include "alustus.h"
#include "lopeta_tallenna.h"

void naytaValikko() 
{
	std::cout << "HENKIL÷IDEN/PUH.NUMEROIDEN KƒSITTELY\n";
	std::cout << "a. Lis‰‰ uusi henkilˆ\n";
	std::cout << "b. N‰yt‰ ensimm‰inen henkilˆ\n";
	std::cout << "c. N‰yt‰ seuraava henkilˆ\n";
	std::cout << "d. Poista kohdalla oleva henkilˆ\n";
	std::cout << "e. Tulosta kaikki tietueet\n";
	std::cout << "0. Lopetus\n";
}

int main()
{
	HenkiloLista henkilot;
	std::string tiedostonimi = "henkilot.csv"; // t‰st‰ n‰in tarkista tiedosto
	
	//Alusta lista tiedostosta
	alustus(henkilot, tiedostonimi.c_str());

	char valinta;
	std::string nimi, osoite, puh;
	Henkilo* current = nullptr;

	do 
	{
		naytaValikko();
		std::cin >> valinta;
		std::cin.ignore(); //pois ylim‰‰r‰ne rivinvaihto

		switch (valinta)
		{
		case 'a':
			std::cout << "Anna nimi: ";
			std::getline(std::cin, nimi);
			std::cout << "Anna osoite: ";
			std::getline(std::cin, osoite);
			std::cout << "Anna puhelinnumero: ";
			std::getline(std::cin, puh);
			henkilot.lisaaHenkilo(nimi, osoite, puh);
			break;

		case 'b':
			current = henkilot.head;
			if (current != nullptr) {
				std::cout << "Nimi: " << current->nimi << std::endl;
				std::cout << "Osoite: " << current->osoite << std::endl;
				std::cout << "Puhelin: " << current->puh << std::endl;
			}
			else {
				std::cout << "Ei henkiloita listassa." << std::endl;
			}
			break;

		case 'c':
			if (current != nullptr &&
				current->next != nullptr) {
				current = current->next;
				std::cout << "Nimi: " << current->nimi << std::endl;
				std::cout << "Osoite: " << current->osoite << std::endl;
				std::cout << "Puhelin: " << current->puh << std::endl;
			}
			else {
				std::cout << "Ei seuraavaa henkiloa." << std::endl;
			}
			break;

		case 'd':
			if (current != nullptr) {
				henkilot.poistaHenkilo(current->nimi);
				current = henkilot.head;
			}
			else {
				std::cout << "Ei poistettavaa henkilˆ‰." << std::endl;
			}
			break;

		case 'e':
			henkilot.tulostaKaikki();
			break;

		case '0':
			shutDown(henkilot.head, tiedostonimi);
			std::cout << "Ohjelma lopetetaan." << std::endl;
			break;

		default:
			std::cout << "Virheellinen valinta. Yrit‰ uudelleen." 
			<< std::endl;

		}
	} while (valinta != '0');

	return 0;

}