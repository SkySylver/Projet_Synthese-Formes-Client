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
	virtual void visite(const Segment* f)const = 0;
	virtual void visite(const Cercle* f)const = 0;
	virtual void visite(const Triangle* f)const = 0;
	virtual void visite(const Polygone* f)const = 0;
	virtual void visite(const FormeComposee* f)const = 0;

};

