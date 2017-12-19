#include <iostream>
#include <sstream>
#include <string>
int main()
{

	std::stringstream strumien;

	strumien << "Napis\n" << 123 << " :)";
	std::string sTekst = strumien.str();

	std::cout << sTekst;
	return 0;
}