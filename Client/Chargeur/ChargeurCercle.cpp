#include "ChargeurCercle.h"
Cercle * ChargeurCercle::chargerForme(const string& nomFichier) const {
	string contenu;
	ifstream fichier;

	fichier.open(nomFichier.c_str(), fstream::in);

	if (fichier.is_open()) {
		fichier.close();
		return NULL;
	}

	fichier >> contenu;

	if (contenu.substr(0, 6) == "Cercle"){
		cout << "chargeur Cercle" << endl;

		//Charger Segment

	}

	fichier.close();
	return NULL;
}
