#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>


struct Parametry
{
	std::string sciezka_dane, sciezka_wyj, sciezka_mapa;
};

bool OdczytajParametry(int argc, char **argv, Parametry& par);
void Siec_neuronowa(const Parametry& par);
void OdczytajNeuron(std::string &bufor, std::stringstream &stream, std::ifstream &mapa, int i);