#include "ChargeurTriangle.h"
Triangle * ChargeurTriangle::chargerForme(const string& nomFichier) const {
	string contenu;
	ifstream fichier;
	string arr[8];
	fichier.open(nomFichier.c_str(), fstream::in);

	if (!fichier.is_open()) {
		fichier.close();
		return NULL;
	}

	fichier >> contenu;

	if (contenu.substr(0, 8) == "Triangle") {
		stringstream ss(contenu);
		string token;
		int i = 0;
		while (getline(ss, token, ',')) {
			arr[i] = token;
			i++;
		}
		Vecteur2D a(stod(arr[2]), stod(arr[3]));
		Vecteur2D b(stod(arr[4]), stod(arr[5]));
		Vecteur2D c(stod(arr[6]), stod(arr[7]));

		fichier.close();
		return new Triangle(a, b, c, arr[1]);
	}


	fichier.close();
	return NULL;
}
