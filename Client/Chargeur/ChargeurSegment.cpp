#include "ChargeurSegment.h"
Segment * ChargeurSegment::chargerForme(const string& nomFichier) const {
	string contenu;
	ifstream fichier;

	fichier.open(nomFichier.c_str(), fstream::in);

	if (fichier.is_open()) {
		fichier.close();
		return NULL;
	}

	fichier >> contenu;

	if (contenu.substr(0, 7) == "Segment"){

		//Charger Segment
		cout << "chargeur Segment" << endl;
	}

	fichier.close();
	return NULL;
}
