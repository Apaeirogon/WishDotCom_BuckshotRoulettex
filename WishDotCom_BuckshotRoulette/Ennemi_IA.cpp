#include "Ennemi_IA.h"
#include "Rand_Balle.h"
#include "Ennemi.h"
#include "Personnage.h"
#include <iostream>
#include "Colors.h"
#include <cstdlib>

using namespace std;


// Fonction pour agir
void Ennemi_IA::agir(Personnage* soi_meme, Personnage* joueur) {

	// Créer variables
	double pourcentageMax(0);

	// Créer classe


	// Ajuster le pourcentage de tirage
	pourcentageMax = difficulty * 10;

	// Si le pourcentage ajusté est plus que 50%
	if (pourcentageMax >= probabilite) {
		// Afficher ce que l'ennemi fait
		cout << RED "L'ennemi" RESET << " vous tire!" << endl;
		soi_meme->tirer_Adversaire(*joueur);

	}
	else {
		cout << RED "L'ennemi" RESET << " se tire!" << endl;
		soi_meme->tirer_SoiMeme();


	}




}



Ennemi_IA::Ennemi_IA(int diff) {
	difficulty = diff;
}

Ennemi_IA::~Ennemi_IA() {}

