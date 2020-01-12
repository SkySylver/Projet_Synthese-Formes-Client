#include "Cercle.h"



Cercle::Cercle(const Vecteur2D & centre, const Vecteur2D & rayon, const string & couleur) : Forme(couleur), _centre(centre), _rayon(rayon) {}
/*
bool Cercle::dessiner(VisiteurDessin visiteur) const {
	return true;
}
*/
Forme * Cercle::Translation(const Vecteur2D & v)const {

	Cercle * c = new Cercle(_centre.Translation(v), _rayon, _couleur);
	return c;
}

Cercle::operator string() const {
	ostringstream os;
	os << "(Centre : " << _centre << "," << "Rayon : " << _rayon << ")";
	return os.str();
}

Forme * Cercle::Homothetie(const Vecteur2D & v, const double rapport)const {
	Cercle * c = new Cercle(_centre, _rayon.Homothetie(v, rapport), _couleur);
	return c;
}

Forme * Cercle::Rotation(const Vecteur2D & v, const double angle)const {
	Cercle * c = new Cercle(_centre, _rayon, _couleur);
	return c;
}