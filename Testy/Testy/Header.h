#pragma once
#include <iostream>
#include <string>
#include <random>
#include <math.h>
#include <time.h>

void generuj();
int modInverse(int a, int m); //odwrotnosc modulo liczby
int gcdExtended(int a, int b, int *x, int *y); //rozszerzony algorytm Euklidesa
int convertToASCII(std::string letter, int* tablica); //funkcja zamieniajaca litery na cyfry wedle tablicy ASCII

template <typename Number> //funkcja znajdujaca najwiekszy wspolny dzielnik
Number GCD(Number u, Number v) {
	while (v != 0) {
		Number r = u % v;
		u = v;
		v = r;
	}
	return u;
}

template <typename T> //algorytm wykonujacy pow(a, b) % n w madry sposob, bo trudno podniesc cos do trzycyfrowej+ potegi w cpp bez bibliotek
T modpow(T base, T exp, T modulus) {
	base %= modulus;
	T result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}