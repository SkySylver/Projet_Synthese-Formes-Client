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
	virtual void visite(Segment* f)const = 0;
	virtual void visite(Cercle* f)const = 0;
	virtual void visite(Triangle* f)const = 0;
	virtual void visite(Polygone* f)const = 0;
	virtual void visite(FormeComposee* f)const = 0;

};

