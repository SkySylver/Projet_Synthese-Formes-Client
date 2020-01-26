#pragma once
/**
 * Classe Chargeur
 */

#include "Chargeur.h"

class ChargeurCOR : public Chargeur {
protected:

	ChargeurCOR(ChargeurCOR* next) : suivant(next) {}

	virtual Forme * chargerForme(const string& contenu, bool charge) const = 0;

public:
	ChargeurCOR* suivant;
	~ChargeurCOR(){}
	Forme* Charger(const string& contenu) const {
		Forme* forme = chargerForme(contenu);
		if (forme != NULL) return forme;
		else {
			if (suivant == NULL) return NULL;
			else return suivant->Charger(contenu);
		}
	}
};