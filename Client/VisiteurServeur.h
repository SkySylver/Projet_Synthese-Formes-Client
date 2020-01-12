#pragma once
#include "VisiteurDessin.h"
#include "Connexion.h"


class VisiteurServeur :	public VisiteurDessin
{
private:
	Connexion _connexion;
public:
	VisiteurServeur(Connexion c) : VisiteurDessin(), _connexion(c) {};
	//VisiteurServeur(char adresse[L], short port);

	~VisiteurServeur() {};

	void setConnexion(Connexion c) { _connexion = c; };
	Connexion & getConnexion() { return _connexion; };

	virtual void visite(const Segment * s) const;
	virtual void visite(const Cercle * c) const;
	virtual void visite(const Polygone * p) const;
	virtual void visite(const Triangle * t) const;
	virtual void visite(const FormeComposee * f) const;
};