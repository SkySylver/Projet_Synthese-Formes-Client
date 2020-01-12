#include "VisiteurServeur.h"

/*
VisiteurServeur::VisiteurServeur(char adresse[L], short port): VisiteurDessin(){

	bool continuer;

	_connexion = co;
}
*/

void visite(const Segment & segm) {

	string str;
	str.append("Segment;");
	str.append("dd");

	const char * c = segm.getCouleur();
}

void VisiteurServeur::visite(const Triangle * t)const {

}

void VisiteurServeur::visite(const Cercle * c) const{

}

void VisiteurServeur::visite(const Polygone * p) const{

}

void VisiteurServeur::visite(const FormeComposee * f) const{

}
