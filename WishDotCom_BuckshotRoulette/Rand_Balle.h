#pragma once
#include <vector>


// Vecteur qui contient les donnees des balles
extern std::vector<int> balles;

// Créer turn
extern int turn;


// Fonction pour prendre 6 valeurs au hasard
void balleAleatoire();



// Si le tir réussi
bool tirerReussi();


// Lire le vecteur
void showBullet();

// Calculer les probabilities
void live_Chance();


// Définir la variable de probabilité actuelle
extern double probabilite;

// Nombre de balle
extern int choixBalle;