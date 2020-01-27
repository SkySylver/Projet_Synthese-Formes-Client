#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "../Forme.h"
using namespace std;

class Chargeur {

	virtual Forme* Charger(const string& nomFichier)const = 0;
};