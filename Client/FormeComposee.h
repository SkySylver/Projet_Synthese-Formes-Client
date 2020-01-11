#pragma once
#include "Forme.h"
#include "FormeSimple.h"
#include <vector>
class FormeComposee:public Forme
{
private:
	vector<FormeSimple> formes;
};