#include "ChargeurCercle.h"
Cercle * ChargeurCercle::chargerForme(const string& nomFichier) const {
	string contenu;
	ifstream fichier;
	int i = 0;
	string arr[5];
	Cercle * temp;

	fichier.open(nomFichier.c_str(), fstream::in);

	if (!fichier.is_open()) {
		fichier.close();
		return NULL;
	}

	fichier >> contenu;

	if (contenu.substr(0, 6) == "Cercle"){
		stringstream ss(contenu);
		string token;
		int i = 0;
		while (getline(ss, token, ',')) {
			arr[i] = token;
			i++;
		}
		Vecteur2D centre(stod(arr[2]), stod(arr[3]));
		fichier.close();
		return new Cercle(centre, stod(arr[4]), arr[1]);
	}

	fichier.close();
	return NULL;
}
