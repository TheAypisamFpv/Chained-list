#include "Objet2D.h"

Objet2D::Objet2D() : dim1(0), dim2(0), obj2Dsuivant(nullptr) {};
Objet2D::Objet2D(int tdim1, int tdim2) : dim1(tdim1), dim2(tdim2) {};

int Objet2D::getPerimetre() { return 0; };
int Objet2D::getAire() { return 0; };
string Objet2D::afficheInfo() { return "Objet2D function"; };