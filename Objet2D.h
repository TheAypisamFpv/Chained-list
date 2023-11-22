#pragma once
#include <iostream>

using namespace std;

class Objet2D {
private:
	Objet2D* obj2Dsuivant = nullptr;

protected:
	int dim1, dim2;

public:
	Objet2D();
	Objet2D(int tdim1, int tdim2);

	virtual int getPerimetre();
	virtual int getAire();
	virtual string afficheInfo();

	void setNext(Objet2D* suivant) { obj2Dsuivant = suivant; };
	Objet2D* getNext() const { return obj2Dsuivant; };
};