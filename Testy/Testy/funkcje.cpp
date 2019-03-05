#include "Header.h"

void generuj()
{
	uint64_t p = 30871;
	uint64_t q = 31333;
	uint64_t n = p * q;
	uint64_t euler = (p - 1)*(q - 1);
	uint64_t e = NULL;
	uint64_t d = NULL;
	std::string tekst;

	while (GCD(euler, e) != 1)
	{
		srand(time(0));
		e = (rand() % euler) + 2;
	}

	d = modInverse(e, euler);

	std::cout << "Klucz publiczny: (" << n << ", " << e << ")" << std::endl;
	std::cout << "Klucz prywatny: (" << n << ", " << d << ")" << std::endl;
	std::cout << "Wpisz wiadomosc do zakodowania:" << std::endl;
	std::getline(std::cin, tekst);
	int wielkosc = tekst.length();
	int *tablica = new int[wielkosc];
	int *zakodowane = new int[wielkosc];
	int *odkodowane = new int[wielkosc];
	*tablica = convertToASCII(tekst, tablica);

	std::cout << "Wiadomosc zakodowana kluczem publicznym: " << std::endl;

	for (int i = 0; i < tekst.length(); i++)
	{
		uint64_t x = tablica[i];
		uint64_t y = modpow(x, e, n);
		zakodowane[i] = y;
		std::cout << zakodowane[i] << " ";
	}

	std::cout << std::endl << "Wiadomosc odkodowana kluczem prywatnym: " << std::endl;

	for (int i = 0; i < tekst.length(); i++)
	{
		uint64_t x = zakodowane[i];
		uint64_t y = modpow(x, d, n);
		odkodowane[i] = y;
		std::cout << odkodowane[i] << " (" << char(odkodowane[i]) << ") ";
	}

	std::cout << std::endl;
	delete[] tablica;
	delete[] zakodowane;
	delete[] odkodowane;
}

int convertToASCII(std::string tekst, int* tablica)
{
	for (int i = 0; i < tekst.length(); i++)
	{
		char x = tekst.at(i);
		tablica[i] = int(x);
	}
	return *tablica;
}

int gcdExtended(int a, int b, int *x, int *y)
{
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}

	int x1, y1; // To store results of recursive call 
	int gcd = gcdExtended(b%a, a, &x1, &y1);

	// Update x and y using results of recursive 
	// call 
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

int modInverse(int a, int m)
{
	int x, y;
	int g = gcdExtended(a, m, &x, &y);
	if (g != 1)
	{
		std::cout << "Odwrotnosc nie istnieje";
		return 0;
	}
	else
	{
		int res = (x%m + m) % m;
		return res;
	}
}