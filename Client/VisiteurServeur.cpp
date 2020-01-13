#include "VisiteurServeur.h"


VisiteurServeur::VisiteurServeur(char adresse[L], short port): VisiteurDessin(){
	Connexion _connexion(adresse, port);
}


void VisiteurServeur::visite(const Segment * s)const {

	ostringstream os;

	os << "Segment;" << s->getCouleur() <<"," <<s->getA().x << "," << s->getA().y <<"," << s->getB().x << "," << s->getB().y;
	_connexion.requete(os.str().c_str());
}

void VisiteurServeur::visite(const Triangle * t)const {
	ostringstream os;
	os << "Triangle;" << t->getCouleur() << "," << t->getA().x << "," << t->getA().y << t->getB().x << "," << t->getB().y << t->getC().x << "," << t->getC().y;
	_connexion.requete(os.str().c_str());
}

void VisiteurServeur::visite(const Cercle * c) const{
	ostringstream os;
	os << "Cercle;" << c->getCouleur() << "," << c->getCentre().x << "," << c->getCentre().y << "," << c->getRayon() * 2<< "," << c->getRayon() * 2;
	_connexion.requete(os.str().c_str());

}

void VisiteurServeur::visite(const Polygone * p) const{
	ostringstream os;
	os << "Polygone;" << p->getCouleur();
	vector<Vecteur2D> v = p->getVecteurs();
	for (unsigned int i = 0; i <= v.size(); i++) os << "," << v.at(i).x << "," << v.at(i).y;

	_connexion.requete(os.str().c_str());
}

void VisiteurServeur::visite(const FormeComposee * f) const{
	ostringstream os;
	vector<Forme*> v = f->getGroupe();
	for (unsigned int i = 0; i <= v.size(); i++) {
		v.at(i)->dessiner(*this);
	}
}
