#include "FormeComposee.h"

FormeComposee::FormeComposee(const Forme& f) {
	vector<Forme>::iterator it = find(_groupe.begin(), _groupe.end(), f);
	if (it != end(_groupe)) {
		_groupe.push_back(f);
	}
	else {
		throw invalid_argument("Un groupe contient déjà cette forme");
	}
}

double FormeComposee::getAire() const {
	double res;
	for (int i = 0; i < _groupe.size(); i++) {
		res += _groupe[i].getAire();
	}
	return res;
}