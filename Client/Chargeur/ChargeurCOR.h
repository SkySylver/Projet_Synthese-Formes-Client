#pragma once
/**
 * Classe Chargeur
 */

#include "Chargeur.h"

class ChargeurCOR : public Chargeur {
protected:
	virtual Forme * chargerForme(const string& contenu) const = 0;

public:
	ChargeurCOR* suivant;
	ChargeurCOR(ChargeurCOR* next) : Chargeur(), suivant(next) {};
	~ChargeurCOR() {}

	Forme* Charger(const string& nomFichier) const {
		Forme* forme = chargerForme(nomFichier);
		if (forme != NULL) return forme;
		else if (suivant == NULL) return NULL;
		else return suivant->Charger(nomFichier);
	}

};