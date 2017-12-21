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
	int ilosc_warstw = 1;
	int bufor_neuronow = 1;
	while (!mapa.eof())
	{
		getline(mapa, bufor);
		if (bufor != "")
		{
			bufor_neuronow++;
			stream << bufor << " \n";
		}
		else if (bufor == "")
		{
			double** tablica_wag_warstwy = new double* [bufor_neuronow];
			Zapisz_warstwe(stream, tablica_wag_warstwy);
			getline(mapa, bufor);
			ilosc_warstw++;
			stream << " x ";
		}
	}
	cout << ilosc_warstw << endl;
	cout << bufor_neuronow << endl;
}

void Zapisz_warstwe(std::stringstream &stream, double** tablica_wag_warstwy)
{

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