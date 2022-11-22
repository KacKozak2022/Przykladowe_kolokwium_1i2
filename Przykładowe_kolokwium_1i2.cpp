#include <iostream>

#define Blok1

#ifdef Blok1

#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	int n;
	double temp;

	do
	{
		cout << "Podaj poprawne n: ";
		cin >> temp;
		cout << endl;
		n = (int)temp;

	} while (n % 2 == 1 || temp / n != 1 || n <= 0);
	
	temp = 0;

	int liczba, licznik_parzysty = 0;
	double g = 0, s = 0;

	for (int i = 1; i <= n && licznik_parzysty < 3; i++) //i=1 dla klarowności zapisu
	{
		do
		{
			cout << "Podaj poprawną liczbę naturalną: "; 
			cin >> temp;
			liczba = (int)temp;

		} while (temp / liczba != 1 || liczba <= 0);

		if (liczba % 2 == 0)
			licznik_parzysty++;
		else
			licznik_parzysty = 0;

		if (liczba % 5 != 0)
		{
			if (i > 1)
			{
				g = pow((pow(g, (i - 1)) * liczba), 1.0 / i);

				s = ((s * (i - 1)) + liczba) / i;
			}
			else
			{
				g = liczba;
				s = liczba;
			}
		}
	}

	cout << endl << "s = " << s << endl;
	cout << "g = " << g << endl << endl;

	constexpr double e = 2.72;
	
	if ((g - 1) / (g + 1) > 0)
	{
		double y = log10((g - 1) / (g + 1)) * pow(s, e);
		cout << "Funkcja y = " << scientific << showpos << setprecision(8) << fixed << y << endl;
	}
	else
		cout << "Nie mogę policzyć funkcji y" << endl;

}

#endif

#ifdef Blok2

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	srand(time(NULL));

	constexpr int ROZMIAR = 5;
	int tablica[ROZMIAR][ROZMIAR], i, j;

	for (i = 0; i < ROZMIAR; i++)
	{
		for (j = 0; j < ROZMIAR; j++)
		{
			tablica[i][j] = (rand() % 12) - 2;
		}
	}

	cout << "Nieposortowana tablica: " << endl << endl;

	for (i = 0; i < ROZMIAR; i++)
	{
		for (j = 0; j < ROZMIAR; j++)
		{
			cout << setw(4) << tablica[i][j];

			if (j < ROZMIAR - 1)
				cout << " |";
		}

		cout << endl;
	}
	cout << endl;

	int kolumna;

	do
	{
		cout << "Podaj poprawną kolumnę do posortowania: "; cin >> kolumna;

	} while (kolumna < 0 || kolumna > ROZMIAR - 1);

	int* wsk1 = &tablica[0][0] + kolumna, temp = 0,
		* wsk2 = wsk1 + ROZMIAR + kolumna;


	for (i = 0; i < ROZMIAR; i++) 
	{
		for (j = i + 1; j < ROZMIAR; j++) 
		{
			if (*(wsk1 + (j * ROZMIAR)) < *(wsk1 + (i * ROZMIAR))) 
			{

				temp = *(wsk1 + i * ROZMIAR);
				*(wsk1 + i * ROZMIAR) = *(wsk1 + j * ROZMIAR);
				*(wsk1 + j * ROZMIAR) = temp;
			}
		}
	}

	cout << endl << "Tablica z posortowaną kolumną nr " << kolumna << ":" << endl << endl;

	for (i = 0; i < ROZMIAR; i++)
	{
		for (j = 0; j < ROZMIAR; j++)
		{
			cout << setw(4) << tablica[i][j];

			if (j < ROZMIAR - 1)
				cout << " |";
		}

		cout << endl;
	}

}

#endif