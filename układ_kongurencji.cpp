#include "pch.h"
#include "uk�ad_kongurencji.h"
#include <iostream>
#include <vector>

void uk�ad_kongurencji::dodaj_do_ukladu_rownanie(int w2, int w3)// dodaje kolejne r�wnanie o wsp�cnznnikach a, m [gdzie: x = a (mod m) ] do uk�adu kongruencji
{
	if (!blockate)
	{
		vec_a.push_back(w2);
		vec_n.push_back(w3);
		ilo_n *= w3; //obliczanie N
	} 
}

int uk�ad_kongurencji::Rozsz_Eukli(int a, int b, int *x, int *y)
{
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}
	int x1, y1; // Przechowuje wyniki danego wywoa�ania funkcji 
	int gcd = Rozsz_Eukli(b%a, a, &x1, &y1);

	*x = y1 - (b / a) * x1; // uaktualnia wyniki do poprzedniego
	*y = x1;

	return gcd;
}

int uk�ad_kongurencji::invmod(int a,int m)
{
	int x, y;
	int g = Rozsz_Eukli(a, m, &x, &y); // wykonanie inwersji
	if (g == 1) { return x; } // sprawdzenie prawdziwosci warunku
}

bool const uk�ad_kongurencji::nwd(int a, int b)
{
	int x = (a == 0) ? b : nwd(b%a, a);
	return (x == 1);
}

bool uk�ad_kongurencji::czyParamiWzgledniePierwsze(void) {
	for (int i = 0; i + 1 < vec_a.size(); i++)
		for (int j = i + 1; j < vec_a.size(); j++)
			if (!nwd(vec_a[i],vec_a[j])) 
			{ return false; }
	return true;
}

bool uk�ad_kongurencji::rozwiaz_uklad(bool wyswietl_kolejne_kroki)//rozwiazuje uklad, zwraca true w przypadku powodzenia(spelnienia warunkow), w innym przypadku false
{
	//sprawdzanie warunk�w dla algorytmu gaussa
	if (vec_a.size() != vec_n.size()) { wyswietl_blad(1); return false; }
	else if (!czyParamiWzgledniePierwsze()) { wyswietl_blad(2); return false; }

	blockate = true;
	int N_i=0,M_i=0;

	if (wyswietl_kolejne_kroki) {std::cout << "Iloczyn wsyztskich m jest r�wny " << ilo_n << std::endl; }

	for (int i = 0; i < vec_n.size(); i++) // obliczanie sumy z twierdzenia gauusa
	{
		N_i = (ilo_n / vec_n[i]);
		M_i = invmod(N_i, vec_n[i]);
		suma += vec_a[i] * N_i * M_i;
		if (wyswietl_kolejne_kroki) { std::cout << "DLa " << i+1 << " iteracji: " << "SUMA= "<< suma << " | N_" << i+1 << "= "  << N_i << " | M_" << i+1 << "= " << M_i << " " << std::endl; }
	}
	suma %= ilo_n;
	return true;
}

void uk�ad_kongurencji::wyswietl_blad(short error_type)
{
	switch (error_type)
	{
		case 1:
			std::cout << "B��D !!! Ilosc wspolczynnik�w a oraz m jest r�zna!" << std::endl;
			break;
		case 2:
			std::cout << "B��D !!! Nie spe�niono warunk�w zadania! \nPodane wsp�czynniki a nie s� parami wzglednie pierwsze!!" << std::endl;
			break;
		case 3:
			std::cout << "B��D !!! Nie istnieje inwersja modularna dla podanego uk�adu!!" << std::endl;
			break;
	default:
		break;
	}
}

void uk�ad_kongurencji::wyswietl_uklad(void)// wyswietla uklad kongruancji
{
	std::cout << std::endl;
	for (int i = 0; i < vec_n.size(); i++)
	{
		std::cout << "x = " << vec_a[i] << "(mod " << vec_n[i] << " )" << std::endl;
	}
	std::cout << std::endl;
}

uk�ad_kongurencji::~uk�ad_kongurencji()
{
}

