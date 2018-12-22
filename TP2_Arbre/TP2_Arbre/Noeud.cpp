#include "Noeud.h"

Noeud::Noeud() {
	gauche = nullptr;
	droite = nullptr;
}

Noeud::Noeud(const string& chaine) {
	element = chaine;
}

Noeud::~Noeud() {
}


const Noeud& Noeud::operator=(const Noeud& n) {
	gauche = n.gauche;
	droite = n.droite;
	element = n.element;
	return *this;
}


const string& Noeud::getElement() const {
	return element;
}


const Noeud* Noeud::getGauche() const {
	return gauche;
}


Noeud* Noeud::getGauche() {
	return gauche;
}


const Noeud* Noeud::getDroite() const {
	return droite;
}


Noeud* Noeud::getDroite() {
	return droite;
}


void Noeud::setElement(string element) {
	this->element = element;
}


void Noeud::setGauche(Noeud* gauche) {
	this->gauche = gauche;
}


void Noeud::setDroite(Noeud* droite) {
	this->droite = droite;
}