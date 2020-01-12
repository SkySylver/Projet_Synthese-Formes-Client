#include "Polygone.h"

double Polygone::getAire() const {
	int j = 0;
	double aire = 0, xsum = 0, ysum = 0;
	//On a besoin du centre du polygone pour faire la somme des triangles qui la composent
	for (unsigned int i = 0; i < _vecteurs.size(); i++) {
		xsum += _vecteurs[i].x;
		ysum += _vecteurs[i].y;
	}
	Vecteur2D centre(xsum / _vecteurs.size(), ysum / _vecteurs.size());
	for (unsigned int i = 0; i < _vecteurs.size() - 1; i++) {
		j = i + 1;
		Triangle t(_vecteurs[i], _vecteurs[j], centre, "black");
		aire += t.getAire();
	}
	Triangle t(_vecteurs[0], _vecteurs[_vecteurs.size()], centre, "black");

	aire += t.getAire();

	return aire;
}


vector<Vecteur2D> Polygone::getVecteurs() {
	return _vecteurs;
}

void Polygone::setVecteur(const vector<Vecteur2D> & v) {

	_vecteurs = v;
}

void Polygone::ajouterVecteur(Vecteur2D v) {
	_vecteurs.push_back(v);
}

void Polygone::retirerVecteur(Vecteur2D v) {
	//vector<Vecteur2D>::iterator it = find(_vecteurs.begin(), _vecteurs.end(), v);
//		_vecteurs.erase(it);
}


Polygone::operator string() const {
	ostringstream os;
	os << "(Polygone :";
	for (vector<Vecteur2D>::const_iterator it = _vecteurs.begin(); it != _vecteurs.end(); ++it) {
		os << *it << ",";
	}
	return os.str();
}


Polygone & Polygone::operator + (const Vecteur2D & v) {
	ajouterVecteur(v);
	return *this;
}

Polygone & Polygone::operator - (const Vecteur2D & v) {
	retirerVecteur(v);
	return *this;
}


Forme * Polygone::Translation(const Vecteur2D & v)const {
	vector<Vecteur2D> vec;
	for (vector<Vecteur2D>::const_iterator it = _vecteurs.begin(); it != _vecteurs.end(); it++)
		vec.push_back(it->Translation(v));

	return new Polygone(vec, _couleur);
}

Forme * Polygone::Homothetie(const Vecteur2D & v, const double rapport)const {
	vector<Vecteur2D> vec;
	for (vector<Vecteur2D>::const_iterator it = _vecteurs.begin(); it != _vecteurs.end(); it++)
		vec.push_back(it->Homothetie(v, rapport));

	return new Polygone(vec, _couleur);
}

Forme * Polygone::Rotation(const Vecteur2D & v, const double angle) const {
	vector<Vecteur2D> vec;
	for (vector<Vecteur2D>::const_iterator it = _vecteurs.begin(); it != _vecteurs.end(); it++)
		vec.push_back(it->Rotation(v, angle));

	return new Polygone(vec, _couleur);
}
