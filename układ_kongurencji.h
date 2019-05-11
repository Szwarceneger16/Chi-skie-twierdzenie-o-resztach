#pragma once
#include <vector>

//struct Rozwiazanie
//{
//int x0;
//int y0;
//};

class uk³ad_kongurencji
{
	bool blockate = false;
	int ilo_n;
	int suma;
	std::vector<int> vec_a;
	std::vector<int> vec_n;
	int invmod(int, int);
	int Rozsz_Eukli(int, int, int *, int *);
	bool const nwd(int a, int b);
	bool czyParamiWzgledniePierwsze(void);
	void wyswietl_blad(short);
public:
	uk³ad_kongurencji() { ilo_n = 1; };
	void dodaj_do_ukladu_rownanie(int w2, int w3);
	void wyswietl_uklad(void);
	bool rozwiaz_uklad(bool =false);
	int const get_ilo_n(void) { return ilo_n; };//uzyskuje iloczn wspolczynnikow n
	int const get_suma(void) { return suma; };//uzyskuje rozwwiazanie
	~uk³ad_kongurencji();
};

