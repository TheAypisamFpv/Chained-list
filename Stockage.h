#pragma once
#include <iostream>
#include "Objet2D.h"

class Stockage {
private:
	struct Node
	{
		Objet2D* objet;
		Node* suivant;
	};

	Node* Head;
	Node* Tail;

public:
	Stockage();
	~Stockage();

	void append(Objet2D* objet);
	void put(Objet2D* objet, int index);
	void afficheInfo();
	void afficheListestats();
	void remove(int index);
	void removeAll();
};