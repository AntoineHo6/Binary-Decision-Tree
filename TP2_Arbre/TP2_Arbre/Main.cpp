#include <iostream>
#include <string>
#include <list>
#include <clocale>
#include "Traitement.h"
#include "AB.h"
#include "Affichage.h"
#include "UtilitairesES.h"

using namespace std;

/**
	Parcour l'arbre et demande s'il la réponse est valide. Sinon, on ajoute une réponse et une question.

	@param arbre L'arbre a parcourir.
	@return nothing.
*/
void logicJeux(AB& arbre);


int main() {
	setlocale(LC_ALL, "");
	const string nomFichier = "sauvegarde.txt";
	list<vector<string>> infoArbre;

	lectureFichSauvegarde(infoArbre, nomFichier);

	AB arbre;
	arbre.initialiseArbre(infoArbre);

	afficheIntro();
	cout << endl;

	while (true) {
		afficheMenu();
		int choix = lireEntier("Entrez votre choix(entre 1 et 2)", 1, 2);

		switch (choix) {
			case 1:
				logicJeux(arbre);
				break;
			case 2:
				arbre.sauvegardePrefixe(nomFichier);
				exit(0);
		}
	}
	return 0;
}


// Parcour l'arbre et demande s'il la réponse est valide. Sinon, on ajoute une réponse et une question.
void logicJeux(AB& arbre) {
	string nouvelleQ;
	string nouvelleR;

	arbre.deplacerCurseurDebut();

	if (arbre.elementCurseurValide()) {
		// boolean si le joueur est tombé sur une réponse ou dans un vide.
		bool reponseInexistant = parcourArbreSelonJoueur(arbre);

		// une reponse a été trouvée.
		if (!reponseInexistant) {
			cout << "C'est un(e) " << arbre.obtenirCurseurNoeud()->getElement() << endl;
			string reponseR = demandeOouN("Ais-je raison? (O/N)");
			// Mauvaise réponse.
			if (reponseR == "N") {
				string *QR = lireQuestionReponse("J'ai perdu");
				arbre.ajoutDeMauvaiseReponseQR(QR[0], QR[1]);
			}
			else {
				cout << "WAHOO" << "\n\n";
			}
		}
		// reponse n'existait pas.
		else {
			string *QR = lireQuestionReponse("Je ne sais pas");
			arbre.ajoutDeNulleReponseQR(QR[0], QR[1]);
		}
	}
	// La racine n'était pas valide.
	else {
		string *QR = lireQuestionReponse("Je ne sais pas");
		arbre.ajoutDeRacineQR(QR[0], QR[1]);
	}
}
