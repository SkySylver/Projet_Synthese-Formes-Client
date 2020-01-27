#include "ChargeurPolygone.h"
Polygone * ChargeurPolygone::chargerForme(const string& nomFichier) const {
	string contenu;
	ifstream fichier;
	vector<Vecteur2D> arr;
	fichier.open(nomFichier.c_str(), fstream::in);
	string col, nom;

	if (!fichier.is_open()) {
		fichier.close();
		return NULL;
	}

	fichier >> contenu;
	stringstream ss(contenu);
	getline(ss, nom, ',');
	getline(ss, col, ',');
	
	if (contenu.substr(0, 8) == "Polygone"){
		string token1, token2;
		while (getline(ss, token1, ',')) {
			getline(ss, token2, ',');
			arr.push_back(Vecteur2D(stod(token1),stod(token2)));
		}

		fichier.close();
		return new Polygone(arr, col);
	}
	fichier.close();
	return NULL;
}
