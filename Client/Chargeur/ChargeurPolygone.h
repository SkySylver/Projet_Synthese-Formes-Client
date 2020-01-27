#pragma once
#include "ChargeurCOR.h"
#include "../Polygone.h"
class ChargeurPolygone : public ChargeurCOR
{
private:
	ChargeurCOR* suivant;
protected:
	Polygone * chargerForme(const string& contenu) const;
public:

	~ChargeurPolygone(){}
	ChargeurPolygone(ChargeurCOR* next) : ChargeurCOR(next) {}


};

