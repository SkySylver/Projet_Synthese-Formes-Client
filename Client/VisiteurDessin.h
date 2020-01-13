#pragma once
/**
 * Classe VisiteurDessin
 */

#include "Segment.h"
#include "Cercle.h"
#include "Polygone.h"
#include "FormeComposee.h"

class VisiteurDessin
{
public:
	
	/**
	 * Visiteur pour le dessin d'un segment
	 * @param s : Segment � visiter
	 */
	virtual void visite(const Segment * s) const = 0;

	/**
	 * Visiteur pour le dessin d'un Cercle
	 * @param c : Cercle � visiter
	 */
	virtual void visite(const Cercle * c) const = 0;

	/**
	 * Visiteur pour le dessin d'un Polygone
	 * @param p : Polygone � visiter
	 */
	virtual void visite(const Polygone * p) const = 0;

	/**
	 * Visiteur pour le dessin d'un Triangle
	 * @param t : Triangle � visiter
	 */
	virtual void visite(const Triangle * t) const = 0;

	/**
	 * Visiteur pour le dessin d'une FormeComposee
	 * @param f : FormeComposee � visiter
	 */
	virtual void visite(const FormeComposee * f) const = 0;
};