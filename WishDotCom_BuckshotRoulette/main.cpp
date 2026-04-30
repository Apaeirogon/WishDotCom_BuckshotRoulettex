#include <iostream>
#include "Colors.h"
#include "Rand_Balle.h"
#include "Personnage.h"
#include "Joueur.h"
#include "Ennemi.h"
#include <cstdlib> 
#include <ctime> 
#include <string>
#include <cctype>
using namespace std;

// Initialiser certaines donnees globales

	// L'ennemi
Ennemi* ennemi = nullptr;

	// Le joueur
Joueur* joueur = nullptr;

	// Le personnage ennemi
Personnage* pEnnemi = ennemi;

	// Le personnage Joueur
Personnage* pJoueur = joueur;

	// Le choix du nombre de balles
int choixBalle(0);

	// Les tours (0 = premier)
int turn(0);

	// l'action de l'utilisateur
int action(0);

	// Probabilité que la balle soit live
double probabilite(0);

	// Créer vecteur avec les balles
vector<int> balles;

	// Initialiser l'IA
Ennemi_IA IA;


// Fonction de l'affichage
void affichage() {
	cout << BOLD_WHITE "ROULETTE RUSSE" RESET " ;\n";
	cout << "Bienvenu au jeu de la " SOFT_AMBER "Roulette Russe MODIFIE\n" RESET "Un revolver contenant " CYAN UNDERLINE "UN NOMBRE DETERMINE DE BALLES LIVE" RESET " est utilise.\n";
	cout << "Savoir cette information est crucial pour decider de vos actions; " CYAN UNDERLINE "RETENEZ-LA" RESET ".\nLes participants prennent chacun leur tour pour tirer.\n";
	cout << "----------------\n";
	cout << BOLD_WHITE "REGLES" RESET " ;\n";
	cout << "* Les participants peuvent choisir de: " CYAN UNDERLINE "tirer soi-meme" RESET ", ou de " CYAN UNDERLINE "tirer l'ennemi" RESET ".\n";
	cout << "* Si un participant decide de se tirer, et que la balle est blank : " CYAN UNDERLINE "CELUI-CI RECOMMENCE SON TOUR" RESET ".\n";
	cout << "* Le jeu continu jusqu'a ce qu'il reste seulement 1 participant.\n\n";
	cout << BOLD_WHITE "Que la chance soi avec vous...\n" RESET BOLD_RED;
	std::system("pause");
	std::system("cls");
	cout << RESET;
}

// Choisir le nombre de pV, et initialiser le joueur/ennemi
void nombreVie(Ennemi*& xennemi, Joueur*& xjoueur, Personnage*& xpEnnemi, Personnage*& xpJoueur) {

	// Créer les variable
	int pvMax(0);


	// Création de loop de vérification
	while (true) {

		// Imprimer la question 
		cout << "Choisir le nombre de " GREEN "pV" RESET SOFT_CYAN " [1 - 10] " RESET "des personnages : " PASTEL_GREEN;
		// Prendre la valeur
		cin >> pvMax;
		cout << RESET;

		// Si cin.fail
		if (cin.fail()) {

			// Vider le buffer
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			// Imprimer l'erreur
			cout << RESET BOLD_RED "\nErreur: Saisie Invalide. Veuillez Reessayez." RESET << endl;

		}

		else if (pvMax <= 0 || pvMax >= 11) {
			// Imprimer l'erreur
			cout << RESET BOLD_RED "\nErreur: Saisie Hors Intervalle Accepte. Veuillez Reessayez." RESET << endl;

		}

		// Sinon, quitter la loop
		else {
			cout << RESET "\n";
			break;
		}
	}

	// Créer l'ennemi (initilaliser)
	xennemi = new Ennemi(pvMax);

	// L'ennemi est aussi une classe personnage, important pour plus tard
	xpEnnemi = xennemi;

	// Créer le joueur, placeholder.
	xjoueur = new Joueur("placeholder", pvMax);

	// Le joueur est aussi une classe personnage, important pour plus tard
	xpJoueur = xjoueur;

}

char rejouer() {

	// Création de variable
	char choix;

	// Création de loop de vérification
	while (true) {

		// Imprimer la question 
		cout << CYAN "Voulez-vous rejouer?\n" RESET "(" GREEN "Y" RESET "," RED "N" RESET ") : " PASTEL_GREEN;

		// Prendre la valeur
		cin >> choix;
		cout << RESET;

		// Si cin.fail
		if (cin.fail()) {

			// Vider le buffer
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			// Imprimer l'erreur
			cout << RESET BOLD_RED "\nErreur: Saisie Invalide. Veuillez Reessayez." RESET << endl;

		}

		else if (choix != 'Y' and choix != 'N' and choix != 'y' and choix != 'n') {
			// Imprimer l'erreur
			cout << RESET BOLD_RED "\nErreur: Caractere Non Reconnu. Veuillez Ressayez." RESET << endl;

		}

		// Sinon, quitter la loop
		else {
			cout << RESET "\n";
			// Mettre en majuscule
			choix = toupper(choix);

			return choix;

		}
	}
}



int ChoixDiffuclte() {

	// Création de variable
	int p_Diff;

	// Création de loop de vérification
	while (true) {

		// Imprimer la question 
		cout << "Choisir la " MAGENTA "Difficulte" RESET SOFT_CYAN " [1 - 5] " RESET "de la partie : " PASTEL_GREEN;
		// Prendre la valeur
		cin >> p_Diff;
		cout << RESET;

		// Si cin.fail
		if (cin.fail()) {

			// Vider le buffer
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			// Imprimer l'erreur
			cout << RESET BOLD_RED "\nErreur: Saisie Invalide. Veuillez Reessayez." RESET << endl;

		}

		else if (p_Diff <= 0 || p_Diff >= 6) {
			// Imprimer l'erreur
			cout << RESET BOLD_RED "\nErreur: Saisie Hors Intervalle Accepte. Veuillez Reessayez." RESET << endl;

		}

		// Sinon, quitter la loop
		else {
			cout << RESET "\n";
			break;
		}
	}

	return p_Diff;
}

void ChoixNBBalle() {

	// Création de variable
	int p_Balle;

	// Création de loop de vérification
	while (true) {

		// Imprimer la question 
		cout << "Choisir le nombre de " SOFT_AMBER << "BALLES" RESET SOFT_CYAN " [4-15] " RESET ": " << PASTEL_GREEN;

		// Prendre la valeur
		cin >> p_Balle;

		// Si cin.fail
		if (cin.fail()) {

			// Vider le buffer
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			// Imprimer l'erreur
			cout << RESET BOLD_RED "\nErreur: Saisie Invalide. Veuillez Reessayez." RESET << endl;

		}

		else if (p_Balle <= 3 || p_Balle >= 16) {
			// Imprimer l'erreur
			cout << RESET BOLD_RED "\nErreur: Saisie Hors Intervalle Accepte. Veuillez Reessayez." RESET << endl;

		}

		// Sinon, quitter la loop
		else {
			cout << RESET "\n";
			break;
		}
	}

	choixBalle = p_Balle;
}


int actionJoueur() {

	// Imprimer la question
	cout << "Actions disponnible: " CYAN "\n1- " << RESET << "Tirer " RED "l'ennemi" << RESET << endl << CYAN "2- " RESET << "Tirer " GREEN "soi-meme\n" RESET << endl;

	// Création de loop de vérification x
	while (true) {
		// Imprimer la question 
		cout <<  "Votre choix: " PASTEL_GREEN;

		// Prendre la valeur
		cin >> action;

		// Si cin.fail
		if (cin.fail()) {

			// Vider le buffer
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			// Imprimer l'erreur
			cout << RESET BOLD_RED "\nErreur: Saisie Invalide. Veuillez Reessayez." RESET << endl;
		}

		// Sinon, vérifier que c'est positif
		else if (action <= 0 or (action != 1 and action != 2)) {

			// Imprimer l'erreur
			cout << RESET BOLD_RED "\nErreur: Saisie Hors Intervalle Accepte. Veuillez Reessayez." RESET << endl;
		}

		else {

			// Retourner l'action, et reset les couleurs
			cout << RESET "\n";
			return action;
		}
	}
}

void choisirUsername() {

	// Créer les variables
	string username("");

	// Imprimer la question
	cout << "Entrez votre " CYAN "username" RESET " : " PASTEL_GREEN;

	// Création de loop de vérification x
	while (true) {

		
		// Prendre la valeur et clear le buffer avant
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, username);

		// Reset les couleurs
		cout << RESET;

		// Si le nom du joueur est vide
		if (username.empty() || username.find_first_not_of(' ') == string::npos) {

			// Vider le buffer
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			// Imprimer l'erreur
			cout << RESET BOLD_RED "\nErreur: Saisie Invalide. Veuillez Reessayez." RESET << endl;
		}

		else {

			// Set l'username
			joueur->setUSERNAME(username);
			return;
		}
	}
}


void boucleJeu() {
	// Créer la boucle infini du jeu
	while (true) {
		// Créer le chargeur
		balleAleatoire();

		// Montrer les balles
		showBullet();
		cout << "\n";

		// Mettre en pause
		std::system("pause");
		cout << "\n";

		// Clear la console
		std::system("cls");

		// Tant que le chargeur n'est pas 0
		while (balles.size() != 0) {

			// Prendre l'action du joueur
			do {
				action = actionJoueur();

				// Clear la console
				std::system("cls");

				// Si action = 1
				if (action == 1) {

					// Le joueur tire l'ennemi
					pJoueur->tirer_Adversaire(*pEnnemi);

					// Vérifier si le joueur/ennemi est vivant
					if (!pJoueur->estVivant() or !pEnnemi->estVivant()) {
						std::system("pause");
						std::system("cls");
						return;
					}
				}

				else {
					// Sinon, donc choix = 2, le joueur se tire
					pJoueur->tirer_SoiMeme();

					// Vérifier si le joueur/ennemi est vivant
					if (!pJoueur->estVivant() or !pEnnemi->estVivant()) {
						std::system("pause");
						std::system("cls");
						return;
					}
				}

				// Si la balle est une blank, on peut rejouer!
				if (succes) {

					// Afficher cela
					cout << PASTEL_GREEN "Vous pouvez rejouer!\n" RESET;
				}
				else {



					// Sinon (donc la balle est live), afficher les stats du joueur/ennemi, et mettre en pause + clear
					std::system("pause");
					std::system("cls");

					// Rendre l'affichage plus claire
					cout << GREEN "Stats Joueur\n------------------------\n" RESET;
					joueur->afficher_Stats();

					// Séprarer l'affichage
					cout << RED "\n\nStats Ennemi\n------------------------\n";
					ennemi->afficher_Stats();
					cout << "\n";
				}

				// Mettre en pause et clear la console
				std::system("pause");
				std::system("cls");

			} while (succes and balles.size() != 0); // Tant que succes est vrai et que le chargeur n'est pas 0

			// Si le chargeur n'est pas vide
			if (balles.size() != 0) {
				do {
					if (balles.size() != 0) {

						// Tour de l'IA; elle analyse les probabilités selon sa difficulté
						IA.agir(pEnnemi, pJoueur);

						// Vérifier si le joueur/ennemi est vivant
						if (!pJoueur->estVivant() or !pEnnemi->estVivant()) {
							std::system("pause");
							std::system("cls");
							return;
						}


						// Si elle se tire, et que c'est une blank
						if (succes) {

							// Afficher que l'ennemi peut rejouer
							cout << BOLD_RED "L'ennemi peut rejouer!" RESET << endl;
						}

						// Mettre en pause et clear la console
						std::system("pause");
						std::system("cls");


						// Vérifier que le joueur est vivant
						if (!pJoueur->estVivant() or !pEnnemi->estVivant()) {
							std::system("pause");
							std::system("cls");
							return;
						}

						// Afficher les stats du joueur/ennemi, et clear/mettre en pause la console
						cout << GREEN "Stats Joueur\n------------------------\n" RESET;
						joueur->afficher_Stats();

						// Séprarer l'affichage
						cout << RED "\n\nStats Ennemi\n------------------------\n" RESET;
						ennemi->afficher_Stats();
						cout << "\n";
						
						std::system("pause");
						std::system("cls");
					}

				} while (succes and balles.size() != 0); // tant que 

			}
		}
		// Dire qu'on recharge le chargeur
		cout << SOFT_AMBER "Le chargeur est vide...\n" RESET BOLD_RED UNDERLINE "NOUVEAU CHARGEUR!\n" RESET;

		// Mettre en pause, et clear la console"
		std::system("pause");
		std::system("cls");
	}
}

int main() {
	// Afficher le but
	affichage();

	// Créer une nouvelle seed
	srand(std::time(nullptr));

	while (true) {
		// Choisir le nombre de balles dans le chargeur
		ChoixNBBalle();

		// Choisir la difficulté de l'IA
		ChoixDiffuclte();

		// Choisir le nombre de pV, et initialiser les personnages
		nombreVie(ennemi, joueur, pEnnemi, pJoueur);

		// Set l'username du joueur
		choisirUsername();

		// Clear la console
		std::system("cls");

		// Création de la boucle jeu
		boucleJeu();

		// Dire qui est mort
		if (pJoueur->estVivant()) {
			cout << BOLD_YELLOW << R"(
		+---------------------+
		|       YOU WIN!      |
		+---------------------+
                \(^_^)/
		)";
		}
		else {
			cout << BOLD_RED << R"(
		+---------------------+
		|      YOU LOSE!      |
		+---------------------+
                 (x_x)
		)";
		}

		// Mettre en pause et clear + reset les couleurs
		cout << "\n" RESET;
		std::system("pause");
		std::system("cls");


		// Demander si l'utilisateur veut rejouer

		// Si oui
		if (rejouer() == 'Y') {
			std::system("cls");
		}

		// Si non
		else {
			// Delete les news
			delete joueur;
			delete ennemi;
			return EXIT_SUCCESS;
		}
	}
}


