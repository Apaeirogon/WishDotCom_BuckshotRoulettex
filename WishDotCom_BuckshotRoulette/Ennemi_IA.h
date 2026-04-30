#pragma once

#include "Personnage.h"
#include <vector>
class Ennemi_IA {
private:
	// Le nombre déterminant sa difficulté
	double difficulty;

public:

	// Constructeur
	Ennemi_IA(int diff = 1);

	// Destructeur
	~Ennemi_IA();


	// Les actions de l'IA
	void agir(Personnage* soi_meme, Personnage* joueur);
};
