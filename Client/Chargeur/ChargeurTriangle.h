#pragma once
#include "ChargeurCOR.h"
#include "../Triangle.h"
class ChargeurTriangle : public ChargeurCOR
{
private:
	ChargeurCOR* suivant;
protected:
	Triangle * chargerForme(const string& contenu) const;
public:

	~ChargeurTriangle(){}
	ChargeurTriangle(ChargeurCOR* next) : ChargeurCOR(next) {}


};

