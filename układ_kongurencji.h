#pragma once
#include <vector>

/*         INSTRUKCJA
	Po utworzeniu obiketu nalezy matod¹ dodaj_do_ukladu_rownanie() dodawac kolejne rownania.
	Po zakonczneiu dodawania nalezy wywo³aæ metode rozwiaz_uklad(). Podanie argumentu true powduje wyswietlanie kolejnych krokow.
	Wynik oraz iloczyn wspolczynnikow modulo wtedy jest dostepny kolejno poprzez metode get_rozwiazanie() i get_ilo_n().
	
	W ka¿dej chwili mo¿na uzyc metody wyswietl_uklad() ktora pokaze nam aktualnie wprowadzony uk³ad kongruencji.
*/


class uk³ad_kongurencji
{
	bool blockate = false; // zabezpieczenie przed dodaniem do ukladu po rozwiazaniu go
	int ilo_n; // iloczyn wsyztskich wspolczynnikow m
	int rozwiazanie; // rozwiazanie
	std::vector<int> vec_a; // wektor przechowujacy wspolczynniki a
	std::vector<int> vec_n; // wektor przechowujacy wspolczynniki m
	int invmod(int, int); // metoda wykonujaca inwersje modularna do algorytmu gaussa
	int Rozsz_Eukli(int, int, int *, int *); // metoda Rozszerzonego algorytmu euklidesa, skladowa metody invmod
	bool const nwd(int a, int b); // metoda Najwiekszego wspolnego dzielnika, skladowa metody czyParamiWzgledniePierwsze
	bool czyParamiWzgledniePierwsze(void); // metoda sprawdzajaca czy wspolczynniki w ukladzie sa parami wzgledne pierwsze
	void wyswietl_blad(short); // metoda sluzaca wyswietlaniu bledow, braku spelniania warunkow itd
public:
	uk³ad_kongurencji() { ilo_n = 1; };
	void dodaj_do_ukladu_rownanie(int w2, int w3); // dodaje do ukladu kolejne rownanie
	void wyswietl_uklad(void); // wyswietla aktualnie wprowadzony uklad kongruencji
	bool rozwiaz_uklad(bool =false); // roziwazuje uklad, przyjmuje argument decydujacy o wsywietlaniu kolejnych krokow - domyslnie false
	int const get_ilo_n(void) { return ilo_n; };//uzyskuje iloczn wspolczynnikow n
	int const get_rozwiazanie(void) { return rozwiazanie; };//uzyskuje rozwiazanie
	~uk³ad_kongurencji();
};

