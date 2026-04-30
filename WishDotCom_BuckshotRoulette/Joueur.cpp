#include <iostream>
#include "Colors.h"
#include "Joueur.h"
using namespace std;


// Initialisateurs
Joueur::Joueur(string m_Username, int m_PVMax) : Personnage(m_PVMax), username(m_Username) {
}

// Destructeur
Joueur::~Joueur() {};


// Définir les setters
	// Username
void Joueur::setUSERNAME(string& m_USERNAME) {
	username = m_USERNAME;
}


// Définir les getters
	// Username
string Joueur::getUSERNAME() const {
	return username;
}

void Joueur::afficher_Stats() const {
	// Définir les variables et prendre les valeurs

	string Etat;
	string FULL(PASTEL_GREEN);
	string HALF(YELLOW);
	string LOW(BOLD_RED);

	// Décider de la couleur des pV
	if (pV >= 4)
		Etat = FULL;
	else if (pV >= 2)
		Etat = HALF;
	else
		Etat = LOW;

	// Imprimer les informations
	cout << SOFT_GRAY "Votre username: " RESET CYAN << username << RESET << endl;
	cout << SOFT_GRAY "Vos pV: " RESET << Etat << pV << RESET << endl;
}






