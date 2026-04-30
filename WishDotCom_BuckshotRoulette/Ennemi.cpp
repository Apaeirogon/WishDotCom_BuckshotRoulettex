#include "Ennemi.h"
#include "Personnage.h"
#include <string>
#include "Colors.h"
#include <iostream>

using namespace std;

// Initialiser
Ennemi::Ennemi(int m_PVEnnemi) : Personnage(m_PVEnnemi) {
}

// Destructeur
Ennemi::~Ennemi() {}


void Ennemi::afficher_Stats() const {
	// Définir les variables et prendre les valeurs

	string Etat;
	string FULL(BOLD_RED);
	string HALF(YELLOW);
	string LOW(PASTEL_GREEN);

	// Décider de la couleur des pV
	if (pV >= 4)
		Etat = FULL;
	else if (pV >= 2)
		Etat = HALF;
	else
		Etat = LOW;

	// Imprimer les informations
	cout << SOFT_GRAY "pV de l'ennemi : " RESET << Etat << pV << RESET << endl;
}