#include "ChargeurTriangle.h"
Triangle * ChargeurTriangle::chargerForme(const string& nomFichier) const {
	string contenu;
	ifstream fichier;

	fichier.open(nomFichier.c_str(), fstream::in);

	if (!fichier.is_open()) {
		fichier.close();
		return NULL;
	}

	fichier >> contenu;

	if (contenu.substr(0, 8) == "Triangle"){
		cout << "triangle charge" << endl;
		//Charger Triangle

	}


	fichier.close();
	return NULL;
}
