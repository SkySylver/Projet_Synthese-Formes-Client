#include "FormeComposee.h"

FormeComposee::FormeComposee(const Forme& f) {
	vector<Forme>::iterator it = find(_groupes.begin(), _groupes.end(), f);
	if (it != end(_groupes)) {
		_groupes.push_back(f);
	}
	else {
		throw invalid_argument("Un groupe contient déjà cette forme");
	}
}

double FormeComposee::getAire() const {
	double res;
	for (int i = 0; i < _groupes.size(); i++) {
		res += _groupes[i].getAire();
	}
	return res;
}