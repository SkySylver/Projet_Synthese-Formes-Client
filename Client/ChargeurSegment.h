#pragma once
#include "Chargeur/ChargeurCOR.h"
class ChargeurSegment : public ChargeurCOR
{
protected:

	ChargeurSegment(ChargeurCOR* next) : ChargeurCOR(next) {}

	virtual Forme * chargerForme(const string& contenu, bool charge) const = 0;

public:
	ChargeurCOR* suivant;
	~ChargeurSegment(){}

};

