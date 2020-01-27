#pragma once
#include "ChargeurCOR.h"
#include "../Cercle.h"
class ChargeurCercle : public ChargeurCOR
{
private:
	ChargeurCOR* suivant;
protected:
	Cercle * chargerForme(const string& contenu) const;
public:

	~ChargeurCercle(){}
	ChargeurCercle(ChargeurCOR* next) : ChargeurCOR(next) {}


};

