#pragma once
#include "VisiteurDessin.h"
#include "Connexion.h"

class VisiteurServeur :	public VisiteurDessin
{
private:
	Connexion _connexion;
public:

	VisiteurServeur(Connexion c) : VisiteurDessin(), _connexion(c) {};
	VisiteurServeur(char adresse[L], short port);

	~VisiteurServeur() {};

	void setConnexion(Connexion c) { _connexion = c; };
	Connexion & getConnexion() { return _connexion; };

	void visite(const Segment * v) const;
	void visite(const Cercle * c) const;
	void visite(const Polygone * c) const;
	void visite(const FormeComposee * f) const;

};