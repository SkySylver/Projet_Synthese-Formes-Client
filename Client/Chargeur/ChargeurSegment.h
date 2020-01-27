#pragma once
#include "ChargeurCOR.h"
#include "../Segment.h"
class ChargeurSegment : public ChargeurCOR
{
private:
	ChargeurCOR* suivant;
protected:
	Segment * chargerForme(const string& contenu) const;
public:

	~ChargeurSegment(){}
	ChargeurSegment(ChargeurCOR* next) : ChargeurCOR(next) {}
};

