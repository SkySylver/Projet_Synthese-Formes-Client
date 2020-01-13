#include "FormeComposee.h"

FormeComposee::FormeComposee(Forme * f) {
	vector<Forme*>::iterator it = find(_groupe.begin(), _groupe.end(), f);
	if (it != end(_groupe)) {
		_groupe.push_back(f);
	}
	else {
		throw invalid_argument("Un groupe contient déjà cette forme");
	}
}

void FormeComposee::ajouterForme(Forme* f) {
	if(f == NULL)
		throw invalid_argument("Paramètre NULL dans FormeComposee::ajouterForme");
	_groupe.push_back(f);
}

void FormeComposee::supprimerForme(Forme* f) {
	vector<Forme*>::iterator it = find(_groupe.begin(), _groupe.end(), f);
	if (it != _groupe.end()) {
		_groupe.erase(it);
	}
}

double FormeComposee::getAire() const {
	double res = 0;
	for (unsigned int i = 0; i < _groupe.size();i++) {
		res += _groupe[i]->getAire();
	}
	return res;
}

void FormeComposee::dessiner(const VisiteurDessin & visiteur) const {

	for (unsigned int i = 0; i < _groupe.size(); i++) {
		_groupe[i]->dessiner(visiteur);
	}
}

FormeComposee::operator string() const {
	string str;
	for (unsigned int i = 0; i < _groupe.size(); i++) {
//		str << (string)_groupe[i];
	}
	return str;
}

Forme * FormeComposee::Translation(const Vecteur2D & v)const {
	FormeComposee *vt = new FormeComposee();
	for (unsigned int i = 0; i < _groupe.size(); i++) {
		vt->ajouterForme(_groupe[i]->Translation(v));
	}
	return vt;
}

Forme * FormeComposee::Homothetie(const Vecteur2D & v, const double rapport)const {
	FormeComposee *vt = new FormeComposee();
	for (unsigned int i = 0; i < _groupe.size(); i++) {
		vt->ajouterForme(_groupe[i]->Homothetie(v, rapport));
	}
	return vt;
}

Forme * FormeComposee::Rotation(const Vecteur2D & v, const double angle)const {
	FormeComposee *vt = new FormeComposee();
	for (unsigned int i = 0; i < _groupe.size(); i++) {
		vt->ajouterForme(_groupe[i]->Rotation(v, angle));
	}
	return vt;
}