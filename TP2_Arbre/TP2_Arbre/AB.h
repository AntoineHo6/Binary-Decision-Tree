#ifndef AB_H
#define AB_H

#include <list>
#include <vector>
#include <fstream>
#include "Noeud.h"

class AB {

public:
	AB();
	~AB();
	
	// Manipulation curseur
	void deplacerCurseurDebut() const;
	void deplacerCurseurGauche() const;
	void deplacerCurseurDroite() const;
	const bool elementCurseurValide() const;
	Noeud* obtenirCurseurNoeud() const;
	
	// Ajout de Noeud
	void setRacine(Noeud& nouveau);
	void insererGaucheCurseur(Noeud& nouveau);
	void insererDroiteCurseur(Noeud& nouveau);
	void ajoutDeRacineQR(const string& nouvelleQ, const string& nouvelleR);
	void ajoutDeNulleReponseQR(const string& nouvelleQ, const string& nouvelleR);
	void ajoutDeMauvaiseReponseQR(const string& nouvelleQ, const string& nouvelleR);
	
	const bool curseurEstFeuille() const;

	// création de sauvegarde de l'arbre
	void initialiseArbre(list<vector<string>>& infoArbre);
	void sauvegardePrefixe(const string& nomFichier);


private:
	Noeud* racine;
	mutable Noeud* curseur;

	void detruireRecursif(Noeud* n);
	void iniArbreRecursif(Noeud*& n, int niveau, string direction, list<vector<string>>& infoArbre);
	void sauvegardeRecursif(const Noeud* n, const string position, const int niveau, ofstream& fichier);
};

#endif
