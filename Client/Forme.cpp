#include "Forme.h"

Forme::Forme(string couleur) {
	string* foo = find(begin(_couleurs), end(_couleurs), couleur);
	// When the element is not found, find returns the end of the range
	if (foo != end(_couleurs)) {
		_couleur = couleur;
	}
	else {
		throw invalid_argument("Couleur invalide");
	}
}
