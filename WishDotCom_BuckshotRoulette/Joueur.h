#pragma once
#include <string>
#include "Degats_Possible.h"
#include "Personnage.h"
// Classe pour le joueur
class Joueur: public Personnage {
private:

	// L'username
	std::string username;

public:

	// Constructeur
	Joueur(std::string m_Username, int m_PVJoueur);

	// Destructeur
	~Joueur();


	// Les getters
	std::string getUSERNAME() const;

	// Lets setters
	void setUSERNAME(std::string& m_USERNAME); 


	// Stats
	void afficher_Stats() const;
};