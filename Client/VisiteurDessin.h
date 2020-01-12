#pragma once
#include "Segment.h"
#include "Cercle.h"
#include "Polygone.h"
#include "FormeComposee.h"

class VisiteurDessin
{
public:
	
	virtual void visite(const Segment * s) const = 0;
	virtual void visite(const Cercle * c) const = 0;
	virtual void visite(const Polygone * p) const = 0;
	virtual void visite(const Triangle * t) const = 0;
	virtual void visite(const FormeComposee * f) const = 0;
};