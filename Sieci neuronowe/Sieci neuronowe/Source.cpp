#include"header.h"

int main(int argc, char**argv)
{
	using namespace std;
	Parametry parametry;
	if (OdczytajParametry(argc, argv, parametry))
	{
		Siec_neuronowa(parametry);
	}
	else
	{
		cout << "Bledne parametry.\n";
	}
}