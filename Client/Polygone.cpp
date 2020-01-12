#include "Polygone.h"




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
