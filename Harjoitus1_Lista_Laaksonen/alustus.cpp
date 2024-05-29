/********************************************************************
/ Kuvaus: Aliohjelma luo uuden Henkilo-listan alustaen ensimm‰iseen
		  alkioon kenttien nimet. Mik‰li annettu tiedosto lˆytyy,
		  alustetaan lista tiedostosta lˆytyv‰ll‰ datalla.
/ Nimi  : alusta.cpp
/ Pva   : 9.1.2017
/ Teki  : I. Trast
/ Muutos: Kirsi Laaksonen 5/2024
********************************************************************/
//T‰m‰ on, jotta Visual Studio k‰‰nt‰‰ vanhat str-alkuiset funktiot
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#pragma execution_character_set("utf-8")

#include "alustus.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "henkilo.h"
#include "HenkiloLista.h"

void alustus(HenkiloLista& henkilot, const char *tied_nimi) {
	std::ifstream fis;
	char tempNimi[100], tempOsoite[100], tempPuh[100];
	std::string nimi, osoite, puh;
	std::string rivi;

	// Otan sis‰‰ char:na ja tallennan v‰liaikaiseen muuttujaan
	//T‰ss‰ avataan tiedosto
	fis.open(tied_nimi);

	if (!fis.fail())
	{
		//Hukataan otsikkorivi
		getline(fis, rivi);

		//Luetaan lista t‰yteen tietoja tiedostosta
		while (getline(fis, rivi))
		{
			if(sscanf_s(rivi.c_str(), "%99[^,],%99[^,],%99[^,]", tempNimi, (unsigned)_countof(tempNimi), tempOsoite, (unsigned)_countof(tempOsoite), tempPuh, (unsigned)_countof(tempPuh)) == 3 )
			{
				//Varoitukset ‰rsytti, kokeilen t‰ss‰ nollaterminointia
				tempNimi[99] = '\0';
				tempOsoite[99] = '\0';
				tempPuh[99] = '\0';

				//T‰‰ll‰ siirr‰n v‰liaikaisesta muuttujasta vakiomuuttujaan oikeassa muodossa.
				nimi = tempNimi;
				osoite = tempOsoite;
				puh = tempPuh;

				//lis‰t‰‰n tiedot listaan
				henkilot.lisaaHenkilo(nimi, osoite, puh);
			}
			else
			{
				//Virhek‰sittely‰
				std::cout << "Virheelline rivi havaittu: " << rivi << std::endl;
				std::cout << "Valitse haluatko (1) Ohittaa t‰m‰n rivin, (2) Lopettaa k‰sittelyn, vai (3) Korjata rivin manuaalisesti?";
				int valinta;	//luodaan muuttuja mihin tallennetaan valinta
				std::cin >> valinta;	//otetaan k‰ytt‰j‰n valinta talteen
				std::cin.ignore();

				if(valinta == 2)
				{
					break;
				}
				else if(valinta == 3)
				{
					std::cout << "Anna korjattu rivi: ";
					std::getline(std::cin, rivi);

					if(sscanf_s(rivi.c_str(), "%99[^,],%99[^,],%99[^,]", tempNimi, (unsigned)_countof(tempNimi), tempOsoite, (unsigned)_countof(tempOsoite), tempPuh, (unsigned)_countof(tempPuh)) == 3)
					{
						tempNimi[99] = '\0';
						tempOsoite[99] = '\0';
						tempPuh[99] = '\0';

						nimi = tempNimi;
						osoite = tempOsoite;
						puh = tempPuh;

						henkilot.lisaaHenkilo(nimi, osoite, puh);

					}
					else
					{
						std::cout << "Virheellinen rivi. Ohitetaan." << std::endl;
					}
				}
			}
		}

	} //t‰ss‰ suljetaan tiedosto
	fis.close();
}