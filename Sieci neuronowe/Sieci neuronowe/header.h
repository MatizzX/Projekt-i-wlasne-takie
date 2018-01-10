#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>

struct Lista_warstw
{
	Lista_warstwy warstwa;
	Lista_warstw* next;
};

struct Lista_warstwy
{
	double waga;
	Lista_warstwy* next;
};

struct Parametry
{
	std::string sciezka_dane, sciezka_wyj, sciezka_mapa;
};

bool OdczytajParametry(int argc, char **argv, Parametry& par);
void Siec_neuronowa(const Parametry& par);
//void OdczytajNeuron(std::string &bufor, std::stringstream &stream, std::ifstream &mapa, int i);
void Zapisz_warstwe(std::stringstream &stream, double** tablica_wag_warstwy);