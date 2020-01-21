#include "Segment.h"
#include "VisiteurDessin.h"
#include "VisiteurSauvegarde.h"

Segment::Segment(const Vecteur2D & a, const Vecteur2D & b, const string & couleur): Forme(couleur), _a(a), _b(b){}

Segment::operator string() const {
	ostringstream os;

	os << "[" << _a << "," << _b <<"]";

	return os.str();
}

void Segment::sauvegarder(VisiteurSauvegarde * v) {
	v->visite(this);
}

void Segment::dessiner(const VisiteurDessin & visiteur) const {
	visiteur.visite(this);
};

Forme * Segment::Translation(const Vecteur2D & v)const {
	Segment * s = new Segment(_a.Translation(v), _b.Translation(v), _couleur);
	return s;
}

Forme * Segment::Homothetie(const Vecteur2D & v, const double rapport)const {
	Segment * s = new Segment(_a.Homothetie(v,rapport), _b.Homothetie(v, rapport), _couleur);
	return s;
}

Forme * Segment::Rotation(const Vecteur2D & v, const double angle)const {
	Segment * s = new Segment(_a.Homothetie(v, angle), _b.Homothetie(v, angle), _couleur);
	return s;
}