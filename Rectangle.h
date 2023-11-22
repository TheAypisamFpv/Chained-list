#pragma once
#include <iostream>
#include "Objet2D.h"

using namespace std;

class Rectangle : public Objet2D {
public:
	Rectangle();
	Rectangle(int tdim1, int tdim2);

	int getLongueur();
	int getLargeur();

	virtual int getPerimetre();
	virtual int getAire();
	virtual string afficheInfo();
};