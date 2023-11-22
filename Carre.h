#pragma once
#include "Rectangle.h"

class Carre : public Rectangle {
public:
	Carre();
	Carre(int cote);

	int getCote();

	virtual int getPerimetre();
	virtual int getAire();
	virtual string afficheInfo();
};