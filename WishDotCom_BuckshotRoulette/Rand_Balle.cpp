#include "Rand_Balle.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>    
#include "Colors.h"
#include <algorithm>

using namespace std;


// Faire les balles au hasard
void balleAleatoire() {

	// Créer la variable "balle"
	int balle(0);

	// 0 = blank, 1 = normal
	while (balles.size() < choixBalle) {
		balle = 0 + (rand() % (1 - 0 + 1));

		// Mettre dans le vecteur
		balles.push_back(balle);
	}
}

// Vérifier si le tir réussi
bool tirerReussi() {

	// Vérifier si la balle est une live
	if (balles[turn] == 1) {

		// Enlever la balle
		balles.erase(balles.begin() + turn);

		// Renvoyer vrai
		return true;
	}
	else {
		// Enlever la balle
		balles.erase(balles.begin() + turn);


		// Renvoyer false
		return false;
	}
}


// Lire le vecteur
void showBullet() {
	// Créer variable
	int k;

	// Pour afficher les balles aléatoirement
	vector<int> ballesMelangees = balles;

	// Faire le shuffle
	random_shuffle(ballesMelangees.begin(), ballesMelangees.end());

	// Afficher le tout
	cout << "Balles :";
	for (int i = 0; i < balles.size(); i++) {

		k = ballesMelangees[i];

		if (k == 1) {
			cout << RED "   ---" RESET;
		}

		else {
			cout << PASTEL_GREEN "   ---" RESET;
		}
		
		

	}

}

// Trouver la probabilité d'une balle live
void live_Chance() {

	// Créer variable pour le nombre de live/total
	double nombre_TOTAL(0);
	double nombre_LIVE(0);

	// Créer variable pour vérifier si c'est le premier tour, et vérifier

	// Trouver le nombre de live/total
	nombre_LIVE = count(balles.begin(), balles.end(), 1);
	nombre_TOTAL = balles.size();



	// Calculer la probabilité ACTUELLE
	probabilite = nombre_LIVE / nombre_TOTAL;
}