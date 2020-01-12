#include "Polygone.h"


double Polygone::getAire() const {
	int j = 0;
	double aire = 0, xsum = 0, ysum = 0;
	//On a besoin du centre du polygone pour faire la somme des triangles qui la composent
	for (int i = 0; i < _vecteurs.size(); i++) {
		xsum += _vecteurs[i].x;
		ysum += _vecteurs[i].y;
	}
	Vecteur2D centre(xsum/_vecteurs.size(),ysum/_vecteurs.size());
	for (int i = 0; i < _vecteurs.size() - 1; i++) {
		j = i + 1;
		Triangle t(_vecteurs[i], _vecteurs[j], centre, "black");
		aire += t.getAire();
	}
	Triangle t(_vecteurs.begin, _vecteurs.end, centre, "black");
	aire += t.getAire();

	return aire;
}
Polygone::operator string() const {

}

Forme * Polygone::Translation(const Vecteur2D & v)const {

}

Forme * Polygone::Homothetie(const Vecteur2D & v, const double rapport)const {

}

Forme * Polygone::Rotation(const Vecteur2D & v, const double angle) const {

}
