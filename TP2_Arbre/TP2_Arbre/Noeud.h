#ifndef NOEUD_H
#define NOEUD_H

#include <string>

using namespace std;

class Noeud {
	
	friend class AB;

public:
	Noeud();
	Noeud(const string& chaine);
	~Noeud();

	const Noeud& operator=(const Noeud& n);

	// Getters
	const string& getElement() const;
	const Noeud* getGauche() const;
	Noeud* getGauche();
	const Noeud* getDroite() const;
	Noeud* getDroite();

	// Setters
	void setElement(string element);
	void setGauche(Noeud* gauche);
	void setDroite(Noeud* droite);

private:
	Noeud* gauche;
	Noeud* droite;
	string element;
};

#endif
