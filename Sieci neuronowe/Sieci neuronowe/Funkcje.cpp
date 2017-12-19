#include"header.h"

bool OdczytajParametry(int argc, char **argv, Parametry& par)
{
	using namespace std;
	string param_i = "-i";
	string param_o = "-o";
	string param_m = "-m";

	for (int i = 1; i < argc - 1; ++i)
	{
		if (argv[i] == param_i)
			par.sciezka_dane = argv[++i];
		else if (argv[i] == param_o)
			par.sciezka_wyj = argv[++i];
		else if (argv[i] == param_m)
			par.sciezka_mapa = argv[++i];
	}
	if (par.sciezka_dane == "" || par.sciezka_mapa == "" || par.sciezka_wyj == "")
		return false;
	return true;
}

void Siec_neuronowa(const Parametry& par)
{
	using namespace std;
	ifstream dane(par.sciezka_dane);
	if (!dane)
	{
		cout << "Nie mozna odczytac pliku: " << par.sciezka_dane << "\n";
		return;
	}

	ifstream mapa(par.sciezka_mapa);
	if (!mapa)
	{
		cout << "Nie mozna odczytac pliku: " << par.sciezka_mapa << "\n";
		return;
	}

	ofstream wyjscie(par.sciezka_wyj);
	if (!wyjscie)
	{
		cout << "Nie mozna zapisac pliku: " << par.sciezka_wyj << "\n";
		return;
	}
	//double ** tab_mapa = new double *[i];
	stringstream stream;
	string bufor;
	int ilosc_warstw = 0;
	while (!mapa.eof())
	{
		getline(mapa, bufor);
		if (bufor != "")
			ilosc_warstw++;
		stream << bufor << " \n";
	}
	cout << ilosc_warstw;
	cout << stream.str();
}

//void OdczytajNeuron(std::string &bufor, std::stringstream &stream, std::ifstream &mapa, int i)
//{
//	using namespace std;
//	while (mapa)
//	{
//		mapa >> bufor;
//		++i;
//		stream << bufor;
//		if (mapa.peek() == '\n')
//			break;
//		stream << " ";
//	}
//}