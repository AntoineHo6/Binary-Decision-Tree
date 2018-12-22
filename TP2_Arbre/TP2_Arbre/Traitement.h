#ifndef TRAITEMENT
#define TRAITEMENT

#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "AB.h"

using namespace std;


/**
	Lit le fichier sauvegarde.txt et stock les informations dans infoArbre.

	@param infoArbre La liste des informations des noeuds qui est rempli selon l'information dans le fichier.
	@param fichier Le fichier a retirer de l'information.
	@return nothing.
*/
void lectureFichSauvegarde(list<vector<string>>& infoArbre, const string& fichier);


/**
	Retourne la position du prochain charactère dans une chaine.

	@param chaine La chaine dont on cherche la position de son premier charactère.
	@return nothing.
*/
const int findPosNextChar(string& chaine);


/**
	Lit une chaine.

	@param message Un message qui apparait avant la demande de la chaine.
	@return La chaine entrée par l'utilisateur.
*/
string lireChaine(const string& message);


/**
	Le joueur parcour l'arbre jusqu'à temps qu'il atteigne une feuille ou rien.

	@param arbre L'arbre dans lequel le il va parcourir.
	@return bool Vrai si le parcour est tombé sur aucune réponse. Faux si une réponse a été trouvé.
*/
bool parcourArbreSelonJoueur(AB& arbre);


/**
	Demande une nouvelle question et reponse a ajouter.

	@param message Affiche qu'il a perdu ou qu'il ne sait pas.
	@return nothing.
*/
string* lireQuestionReponse(const string& message);


/**
	Demande une question repondu par "O" ou "N".

	@param message Affiche la question.
	@return nothing.
*/
string demandeOouN(const string& message);

#endif;
