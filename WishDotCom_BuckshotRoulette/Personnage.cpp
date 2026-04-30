#include "Personnage.h"
#include "Rand_Balle.h"
#include "Colors.h"
#include <iostream>

using namespace std;

// Définir succes
bool succes(false);


// Fonction de tirer adversaire
void Personnage::tirer_Adversaire(Degats_Possible& cible) {
    succes = false;

    // Si tirer l'ennemi réussi
    if (tirerReussi()) {

        // La cible prend des dégats
        cible.prendDegats(1);

        // Afficher le résultat
        cout << BOLD_RED "BANG!!\n" RESET;
    }
    else {
        // Afficher que la balle était blank
        cout <<  YELLOW "Rien ne se passe...\n" RESET;
    }
}

// Fonction de s'autotirer
void Personnage::tirer_SoiMeme() {

    // Si se tirer réussi
    if (tirerReussi()) {

        // On prend des dégats
        prendDegats(1);
        succes = false;

        // Afficher le résultats
        cout << BOLD_RED "BANG!!\n" RESET;
    }
    else {

        succes = true;

        // Afficher que la balle était blank
        cout << YELLOW "Rien ne se passe...\n" RESET;
    }
}

// Vérifier si vivant
bool Personnage::estVivant() {

    // Vérifier les pV
    if (pV == 0)
        // Si mort, return false
        return false;
    else
        // Si vivant, return true
        return true;
}

// Prendre les dégats
void Personnage::prendDegats(int degats) {

    // Vérifier si il y a des dégats
    if (degats <= 0) {
        return;
    }

    // Réduire les pV
    pV -= degats;


    // Vérifier si le joueur est mort
    if (pV < 0)
        pV = 0;
}

