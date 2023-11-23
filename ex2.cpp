#include <iostream>
#include "Objet2D.h"
#include "Carre.h"
#include "Rectangle.h"
#include "Stockage.h"

using namespace std;

int get_obj_type() {
	int type = 0;
	while (type < 1 || type > 2) {
		cout << endl << "Entrez le type de l'objet " << endl << "\t|\t1 : Carre" << endl << "\t|\t2 : Rectangle" << endl << "> ";
		cin >> type;
	}
	return type;
}

int get_carre() {
	int cote = 0;
	while (cote <= 0) {
		cout << "Entrez la cote du carre : " << endl << "> ";
		cin >> cote;
	}
	return cote;
}

void get_rectangle(int* longueur, int* largeur) {
	while (*longueur <= 0) {
		cout << "Entrez la longueur du rectangle : " << endl << "> ";
		cin >> *longueur;
	}
	while (*largeur <= 0) {
		cout << "Entrez la largeur du rectangle : " << endl << "> ";
		cin >> *largeur;
	}
}


int put(Stockage* ListeObjet2D) {
	int error = 0;

	int index;
	cout << endl << "Entrez l'index de l'objet a ajouter : " << endl << "> ";
	cin >> index;

	int type = get_obj_type();
	if (type == 1) {
		int cote = get_carre();
		Carre* carre = new Carre(cote);
		error = ListeObjet2D->put(carre, index);
	}
	else if (type == 2) {
		int longueur = 0;
		int largeur = 0;
		get_rectangle(&longueur, &largeur);
		Rectangle* rectangle = new Rectangle(longueur, largeur);
		error = ListeObjet2D->put(rectangle, index);
	}

	return error;
}	

int putAtHead(Stockage* ListeObjet2D) {
	int type = get_obj_type();
	if (type == 1) {
		int cote = get_carre();
		Carre* carre = new Carre(cote);
		ListeObjet2D->putAtHead(carre);
	}
	else if (type == 2) {
		int longueur = 0;
		int largeur = 0;
		get_rectangle(&longueur, &largeur);
		Rectangle* rectangle = new Rectangle(longueur, largeur);
		ListeObjet2D->putAtHead(rectangle);
	}

	return 0;
}

int append(Stockage* ListeObjet2D) {
	int type = get_obj_type();
	if (type == 1) {
		int cote = get_carre();
		Carre* carre = new Carre(cote);
		ListeObjet2D->append(carre);
	}
	else if (type == 2) {
		int longueur = 0;
		int largeur = 0;
		get_rectangle(&longueur, &largeur);
		Rectangle* rectangle = new Rectangle(longueur, largeur);
		ListeObjet2D->append(rectangle);
	}

	return 0;
}

int create_list(Stockage* ListeObjet2D) {
	int size = 0;
	while (size <= 0) {
		cout << "Entrez la longueure de la liste (non definitif) : " << endl << "> ";
		cin >> size;
	}

	for (int i = 0; i < size; i++) {
		append(ListeObjet2D);
		cout << endl << "Objet " << i << " ajoute !" << endl;
	}

	cout << endl << "Liste des objets : " << endl;
	ListeObjet2D->afficheInfo();

	return 0;
}


void help() {
	cout << "Commandes disponibles : " << endl;
	cout << "\t-    help     :	 afficher ce message" << endl;
	cout << "\t- createliste :	 creer une liste d'objets" << endl;
	cout << "\t-   append    :	 ajouter un objet a la liste" << endl;
	cout << "\t-     put     :	 ajouter un objet a la liste a la suite d'un index donne" << endl;
	cout << "\t-  putathead  :	 ajouter un objet a la liste au debut de la liste" << endl;
	cout << "\t-  listeinfo  :	 affiche les informations de tous les objets de la liste" << endl;
	cout << "\t-   remove    :	 supprimer un objet de la liste a un index donne" << endl;
	cout << "\t-  removeall  :	 supprimer tous les objets de la liste" << endl;
	cout << "\t-    exit     :	 quitter le programme" << endl;
}


int main() {
	Stockage ListeObjet2D = Stockage();
	help();

	string command;
	while (command != "exit") {
		cout << endl << "Entrez votre commande : " << endl << "> ";
		cin >> command;
		cout << endl;

		if (command == "help") help(); 
		else if (command == "createliste") create_list(&ListeObjet2D);
		else if (command == "append") append(&ListeObjet2D);
		else if (command == "putathead") putAtHead(&ListeObjet2D);

		else if (command == "put") {
			ListeObjet2D.afficheInfo();
			if (put(&ListeObjet2D) > 0) cout << endl << " X | Erreur : index invalide" << endl;
			else cout << endl << " O | Objet ajoute !" << endl;
		}

		else if (command == "listeinfo") {
			ListeObjet2D.afficheListestats();
			ListeObjet2D.afficheInfo();
		}

		else if (command == "remove") {
			ListeObjet2D.afficheInfo();
			int index = -1;
			while (index < 0) {
				cout << endl << "Entrez l'index de l'objet a supprimer : " << endl << "> ";
				cin >> index;
			}
			if (ListeObjet2D.remove(index) > 0) cout << endl << "X | Erreur : index invalide" << endl;
			else cout << endl << "O | Objet supprime !" << endl;

			ListeObjet2D.afficheInfo();
		}

		else if (command == "removeall") {
			ListeObjet2D.removeAll();
			ListeObjet2D.afficheInfo();
		}

		else if (command == "exit") cout << "Fin du programme" << endl;

		else cout << "Commande inconnue, utilisez 'help'" << endl;
	}
	return 0;
}