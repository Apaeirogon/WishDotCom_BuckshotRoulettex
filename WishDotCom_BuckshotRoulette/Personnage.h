#pragma once
#include "Degats_Possible.h"
class Personnage : public Degats_Possible {
protected:
	
	// Point de vie
	int pV;

	// Point de vie Max
	int pVMAX;


public:
	// Constructeur
	Personnage(int pvMax) : pV(pvMax), pVMAX(pvMax) {}


	// Déconstructeur 
	virtual ~Personnage() = default;

	// Action de tirer l'adversaire
	virtual void tirer_Adversaire(Degats_Possible& cible);


	// Action de se tirer
	virtual void tirer_SoiMeme();

	// Vérifier si vivant
	bool estVivant();

	// Prendre des degats
	void prendDegats(int degats);


};

// Créer variable succès pour savoir si le personnage se tire, que c'est blank
extern bool succes;



