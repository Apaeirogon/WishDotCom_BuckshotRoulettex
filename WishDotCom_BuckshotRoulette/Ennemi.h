#pragma once
#include "Personnage.h"
#include "Ennemi_IA.h"

class Ennemi : public Personnage {
public:
	// Constructeur
	Ennemi(int m_PVEnnemi);

	// Destructeur
	~Ennemi();

	// Afficher les stats de l'ennemi
	void afficher_Stats() const;
};