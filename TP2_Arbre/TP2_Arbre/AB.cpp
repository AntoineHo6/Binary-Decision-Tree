#include "AB.h"

AB::AB() {
	racine = nullptr;
}


AB::~AB() {
	detruireRecursif(racine);
}


void AB::deplacerCurseurDebut() const {
	curseur = racine;
}


void AB::deplacerCurseurGauche() const {
	curseur = curseur->getGauche();
}


void AB::deplacerCurseurDroite() const {
	curseur = curseur->getDroite();
}


const bool AB::elementCurseurValide() const {
	if (curseur == nullptr) {
		return false;
	}
	return true;
}


Noeud* AB::obtenirCurseurNoeud() const {
	return curseur;
}


void AB::setRacine(Noeud& nouveau) {
	racine = &nouveau;
}


void AB::insererGaucheCurseur(Noeud& nouveau) {
	curseur->setGauche(&nouveau);
}


void AB::insererDroiteCurseur(Noeud& nouveau) {
	curseur->setDroite(&nouveau);
}


void AB::ajoutDeRacineQR(const string& nouvelleQ, const string& nouvelleR) {
	Noeud *nouveauR = new Noeud(nouvelleR);
	Noeud *nouvelleRacine = new Noeud(nouvelleQ);
	racine = nouvelleRacine;
	deplacerCurseurDebut();
	insererGaucheCurseur(*nouveauR);
}


void AB::ajoutDeNulleReponseQR(const string& nouvelleQ, const string& nouvelleR) {
	Noeud *nouveauR = new Noeud(nouvelleR);
	Noeud *nouveauQ = new Noeud(nouvelleQ);
	insererDroiteCurseur(*nouveauQ);
	deplacerCurseurDroite();
	insererGaucheCurseur(*nouveauR);
}


void AB::ajoutDeMauvaiseReponseQR(const string& nouvelleQ, const string& nouvelleR) {
	Noeud *nouveauR = new Noeud(nouvelleR);
	Noeud *vielleR = new Noeud(obtenirCurseurNoeud()->getElement());
	obtenirCurseurNoeud()->setElement(nouvelleQ);
	insererDroiteCurseur(*vielleR);
	insererGaucheCurseur(*nouveauR);
}


const bool AB::curseurEstFeuille() const {
	if (curseur->gauche == nullptr && curseur->droite == nullptr) {
		return true;
	}
	return false;
}


void AB::initialiseArbre(list<vector<string>>& infoArbre) {
	iniArbreRecursif(racine, 0, "R", infoArbre);
}


void AB::iniArbreRecursif(Noeud*& n, int niveau, string direction, list<vector<string>>& infoArbre) {
	// infoNoeud: {<niveau>, <direction>, <contenu>}
	vector<string> infoNoeud;
	if (infoArbre.size() > 0) {
		infoNoeud = infoArbre.front();
	} else {
		return;
	}
	
	if (niveau == stoi(infoNoeud[0]) && direction == infoNoeud[1]) {
		n = new Noeud(infoNoeud[2]);
		infoArbre.pop_front();

		iniArbreRecursif(n->gauche, niveau + 1, "G", infoArbre);
		iniArbreRecursif(n->droite, niveau + 1, "D", infoArbre);
	}
}


void AB::detruireRecursif(Noeud* n) {
	if (n != nullptr) {
		detruireRecursif(n->getGauche());
		detruireRecursif(n->getDroite());
		delete n;
	}
}


void AB::sauvegardePrefixe(const string& nomFichier) {
	ofstream fichier(nomFichier);
	if (fichier.is_open()) {
		sauvegardeRecursif(racine, "R", 0, fichier);
	}
	fichier.close();
}


void AB::sauvegardeRecursif(const Noeud* n, const string position, const int niveau, ofstream& fichier) {
	if (n != nullptr) {
		fichier << niveau << "\t" << position << "\t" << n->element << endl;
		sauvegardeRecursif(n->gauche, "G", niveau + 1, fichier);
		sauvegardeRecursif(n->droite, "D", niveau + 1, fichier);
	}
}
