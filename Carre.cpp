#include "Carre.h"
#include <iostream>
#include <string>

using namespace std;

Carre::Carre() : Rectangle() {};
Carre::Carre(int cote) : Rectangle(cote, cote) {};

int Carre::getPerimetre() { return 4 * this->getLongueur();};
int Carre::getAire() { return this->getLongueur() * this->getLongueur();};
int Carre::getCote() { return this->getLongueur();};
string Carre::afficheInfo() { return "Type : carre || cote = " + to_string(this->getLongueur()) + ", Perimetre = " + to_string(this->getPerimetre()) + ", Aire = " + to_string(this->getAire()); };