#include "Traitement.h"

void lectureFichSauvegarde(list<vector<string>>& infoArbre, const string& fichier) {
	ifstream fichSauvegarde(fichier);
	string chaine;

	if (fichSauvegarde.is_open()) {
		while (!fichSauvegarde.eof()) {
			// Chaine devrait est du genre: (3	  G   chien)
			getline(fichSauvegarde, chaine);
			
			if (chaine == "") {
				break;
			}

			vector<string> info;
			// Stock premiere info
			info.push_back(string(1, chaine[0]));
			chaine.erase(0, 1);				// Enleve le niveau de la chaine

			// Stock la deuxieme info
			int pos = findPosNextChar(chaine);
			info.push_back(string(1, chaine[pos]));
			chaine.erase(pos, pos + 1);		// Enleve la direction de la chaine

			// Stock troisieme info
			int pos2 = findPosNextChar(chaine);
			info.push_back(chaine.substr(pos2));

			infoArbre.push_back(info);
		}
		fichSauvegarde.close();
	}
}


const int findPosNextChar(string& chaine) {
	int pos = 0;
	for (char& c : chaine) {
		if (isalpha(c)) {
			break;
		}
		pos++;
	}
	return pos;
}


// Lit une chaine.
string lireChaine(const string& message) {
	string chaine = "";

	while (chaine == "") {
		cout << message << ": ";
		getline(cin, chaine);
	}
	return chaine;
}


bool parcourArbreSelonJoueur(AB& arbre) {
	bool reponseInexistant = false;

	while (!arbre.curseurEstFeuille()) {
		string reponseQ;
		// Demande la question du noeud
		do {
			reponseQ = lireChaine(arbre.obtenirCurseurNoeud()->getElement() + "(O/N)");
			std::transform(reponseQ.begin(), reponseQ.end(), reponseQ.begin(), ::toupper);
		} while (reponseQ != "O" && reponseQ != "N");

		
		// Une réponse Oui nous déplace vers la droite de l'arbre
		if (reponseQ == "O") {
			if (arbre.obtenirCurseurNoeud()->getGauche() != nullptr) {
				arbre.deplacerCurseurGauche();
			}
			else {
				reponseInexistant = true;
				break;
			}
		}
		// Une réponse Non nous déplace vers la gauche de l'arbre
		else {
			if (arbre.obtenirCurseurNoeud()->getDroite() != nullptr) {
				arbre.deplacerCurseurDroite();
			}
			else {
				reponseInexistant = true;
				break;
			}
		}
	}
	return reponseInexistant;
}


string* lireQuestionReponse(const string& message) {
	cout << message << endl;
	string nouvelleR = lireChaine("Quel est la réponse");
	string nouvelleQ = lireChaine("Quelle question permet de le distinguer?");

	static string QR[2];
	QR[0] = nouvelleQ;
	QR[1] = nouvelleR;
	return QR;
}


string demandeOouN(const string& message) {
	string reponse;
	reponse = lireChaine(message);
	std::transform(reponse.begin(), reponse.end(), reponse.begin(), ::toupper);
	while (reponse != "O" && reponse != "N") {
		reponse = lireChaine("Entrez 'O' ou 'N'");
		std::transform(reponse.begin(), reponse.end(), reponse.begin(), ::toupper);
	}

	return reponse;
}
