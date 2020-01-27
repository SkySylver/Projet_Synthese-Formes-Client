#include "ChargeurPolygone.h"
Polygone * ChargeurPolygone::chargerForme(const string& nomFichier) const {
	string contenu;
	ifstream fichier;

	fichier.open(nomFichier.c_str(), fstream::in);

	if (fichier.is_open()) {
		fichier.close();
		return NULL;
	}

	fichier >> contenu;

	if (contenu.substr(0, 8) == "Polygone"){
		cout << "chargeur Polygone" << endl;

		//Charger Segment

	}
	fichier.close();
	return NULL;
}
