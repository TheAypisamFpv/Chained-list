#include "Stockage.h"

Stockage::Stockage() : Head(nullptr), Tail(nullptr) {};

Stockage::~Stockage() { removeAll(); };

int Stockage::len() {
	Node* temp = Head;
	int i = 1;

	while (temp != nullptr) {
		temp = temp->suivant;
		i++;
	}

	return i;
};

void Stockage::append(Objet2D* objet) {
	Node* newNode = new Node;
	newNode->objet = objet;
	newNode->suivant = nullptr;

	if (Head == nullptr) {
		Head = newNode;
		Tail = newNode;
	}
	else {
		Tail->suivant = newNode;
		Tail = newNode;
	}
};

int Stockage::put(Objet2D* objet, int index) {
	Node* temp = Head;
	Node* newNode = new Node;
	newNode->objet = objet;	
	newNode->suivant = nullptr;
	int i=0;
	int lenght = len();

	index = index < 0 ? lenght + index : index;

	if (index < 0) {
		putAtHead(objet);
		return 0;
	}
	else if (index >= lenght) {
		append(objet);
		return 0;
	}

	while (i++ < index-1) {
		if (temp == nullptr) return 1;
		temp = temp->suivant;
	}

	newNode->suivant = temp->suivant;
	temp->suivant = newNode;
	return 0;
};

void Stockage::putAtHead(Objet2D* objet) {
	Node* newNode = new Node;
	newNode->objet = objet;
	newNode->suivant = Head;
	Head = newNode;
};

void Stockage::afficheInfo() {
	Node* temp = Head;
	int index = 0;

	cout << endl << "Liste des objets : " << endl;
	while (temp != nullptr) {
		cout << "\t- Objet " << index << " : " << temp->objet->afficheInfo() << endl;
		temp = temp->suivant;
		index++;
	}
	
};

void Stockage::afficheListestats() {
	//representation of how the list is stored (node 0 {adresse} -> node N {adresse})
	Node* temp = Head;
	int index = 0;

	cout << endl << "Adresses memoire utilise par la liste : " << endl << "\t";

	while (temp != nullptr) {
		cout << "Node " << index << " {" << temp->objet << "}";
		if (temp->suivant != nullptr) cout << " -> ";
		else cout << " -> NULL";
		temp = temp->suivant;
		index++;
	}
	cout << endl;
}

int Stockage::remove(int index) {
	Node* temp = Head;
	Node* temp2 = Head;
	int i = 0;

	if (index == 0) {
		Head = Head->suivant;
		delete temp;
	}
	else {
		while (i < index) {
			if (temp == nullptr) return 1;
			temp2 = temp;
			temp = temp->suivant;
			i++;
		}

		temp2->suivant = temp->suivant;
		delete temp;
	}
	return 0;
};

void Stockage::removeAll() {
	Node* temp = Head;

	while (temp != nullptr) {
		Head = Head->suivant;
		delete temp;
		temp = Head;
	}
};