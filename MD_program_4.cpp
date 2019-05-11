#include "pch.h"
#include <iostream>
#include "układ_kongurencji.h"
#include <sstream>
#include <conio.h>

//#define moja_spec // kontrola sposbu wyswietlania wyniku

using namespace std;
układ_kongurencji uklad_A;

int main()
{
	setlocale(LC_CTYPE, ".1250");
	int liczba_1, liczba_2;
	cout << "Program do wyliczania rozwiązania dla układu kongruencji. \n      *** Autor: Grzegorz Szwarc *** \nPodanie 0 skutkuje wyjsciem z trybu wprowadzania i rozwiazanie układu." << endl;
	cout << "Podaj kolejno wspolczynniki a i m dla i-tego równania, gdzie ->   x = a (mod m) " << endl;
	while(true)
	{
		while (true)
		{
			if (cin >> liczba_1) { break; }
			cin.clear();
			cin.ignore(512, '\n');
			cout << "Podaj tylko cyfry!!";
		}
		if (liczba_1 == 0) { break; }
		while (true)
		{
			if (cin >> liczba_2) { break; }
			cin.clear();
			cin.ignore(512, '\n');
			cout << "Podaj tylko cyfry!!";
		}
		uklad_A.dodaj_do_ukladu_rownanie(liczba_1, liczba_2);
	}
	cout << endl;
	
	uklad_A.wyswietl_uklad();

	if (uklad_A.rozwiaz_uklad(true))
	{
		cout << " Rozwiązanie dla powyższego układu to:  x = " << uklad_A.get_suma() << " (mod " << uklad_A.get_ilo_n() << ")" << endl;
	}
#ifdef moja_spec
	cout << " Rozwiązanie dla powyższego układu to: " << uklad_A.rozwiaz_uklad(true) << " + " << uklad_A.get_ilo_n() << "k" << endl;
#endif // moja_spec
	
}
