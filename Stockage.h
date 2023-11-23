#pragma once
#include <iostream>
#include "Objet2D.h"

class Stockage {
private:
	struct Node {
		Objet2D* objet;
		Node* suivant;
	};

	Node* Head;
	Node* Tail;

public:
	Stockage();
	~Stockage();

	int len();
	void append(Objet2D* objet);
	int put(Objet2D* objet, int index);
	void putAtHead(Objet2D* objet);
	void afficheInfo();
	void afficheListestats();
	int remove(int index);
	void removeAll();
};