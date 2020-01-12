#pragma once
#include "Forme.h"
#include "Segment.h"
#include "Cercle.h"
#include "Polygone.h"
#include "FormeComposee.h"

class VisiteurDessin
{
public:

	VisiteurDessin() {};
	virtual ~VisiteurDessin() {};
	
	virtual void visite(const Segment * v) const = 0;
	virtual void visite(const Cercle * c) const = 0;
	virtual void visite(const Polygone * c) const = 0;
	virtual void visite(const FormeComposee * f) const = 0;

};

