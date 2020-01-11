#pragma once
#include "Forme.h"
#include "FormeSimple.h"
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
	double getAire() const;
};