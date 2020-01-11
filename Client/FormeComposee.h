#pragma once
#include "Forme.h"
#include "FormeSimple.h"
#include <vector>
using namespace std;

class FormeComposee:public Forme
{
private:
	vector<Forme> _groupes;
public:
	FormeComposee() {}
	FormeComposee(const Forme& f);
	~FormeComposee() {};

};