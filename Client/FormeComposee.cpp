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