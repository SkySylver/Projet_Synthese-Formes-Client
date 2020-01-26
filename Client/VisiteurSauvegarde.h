#pragma once
/**
 * Classe VisiteurSauvegarde
 */

#include "Forme.h"
#include "Cercle.h"
#include "Segment.h"
#include "Triangle.h"
#include "Polygone.h"
#include "FormeComposee.h"

class VisiteurSauvegarde
{
public:

	/**
	 * Constructeur par défaut
	 */
	VisiteurSauvegarde(){}

	/**
	 * Visiteur pour la sauvegarde d'un Segment
	 * @param f : Segment à sauvegarder
	 */
	virtual void visite(const Segment* f) = 0;

	/**
	 * Visiteur pour la sauvegarde d'un Cercle
	 * @param f : Cercle à sauvegarder
	 */
	virtual void visite(const Cercle* f) = 0;

	/**
	 * Visiteur pour la sauvegarde d'un Triangle
	 * @param f : Triangle à sauvegarder
	 */
	virtual void visite(const Triangle* f) = 0;

	/**
	 * Visiteur pour la sauvegarde d'un Polygone
	 * @param f : Polygone à sauvegarder
	 */
	virtual void visite(const Polygone* f) = 0;

	/**
	 * Visiteur pour la sauvegarde d'une FormeComposee
	 * @param f : FormeComposée à sauvegarder
	 */
	virtual void visite(const FormeComposee* f) = 0;

};

