#pragma once
#include "Forme.h"
#include <vector>
using namespace std;

class FormeComposee:public Forme
{
private:
	vector<Forme*> _groupe;
public:
	FormeComposee() {}
	FormeComposee(Forme * f);
	~FormeComposee() {};

	void ajouterForme(Forme * f);
	void supprimerForme(Forme * f);
	double getAire() const;
};