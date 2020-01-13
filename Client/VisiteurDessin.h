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
	 * @param s : Segment à visiter
	 */
	virtual void visite(const Segment * s) const = 0;

	/**
	 * Visiteur pour le dessin d'un Cercle
	 * @param c : Cercle à visiter
	 */
	virtual void visite(const Cercle * c) const = 0;

	/**
	 * Visiteur pour le dessin d'un Polygone
	 * @param p : Polygone à visiter
	 */
	virtual void visite(const Polygone * p) const = 0;

	/**
	 * Visiteur pour le dessin d'un Triangle
	 * @param t : Triangle à visiter
	 */
	virtual void visite(const Triangle * t) const = 0;

	/**
	 * Visiteur pour le dessin d'une FormeComposee
	 * @param f : FormeComposee à visiter
	 */
	virtual void visite(const FormeComposee * f) const = 0;
};