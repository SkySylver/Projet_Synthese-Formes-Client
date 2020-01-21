#pragma once
#include "Forme.h"
#include "Cercle.h"
#include "Segment.h"
#include "Triangle.h"
#include "Polygone.h"
#include "FormeComposee.h"

class VisiteurSauvegarde
{
public:

	VisiteurSauvegarde(){}
	virtual void visite(const Segment* f) = 0;
	virtual void visite(const Cercle* f) = 0;
	virtual void visite(const Triangle* f) = 0;
	virtual void visite(const Polygone* f) = 0;
	virtual void visite(const FormeComposee* f) = 0;

};

