#pragma once
#include <string>
#include <stdexcept>
#include "Vecteur2D.h"
#include "VisiteurDessin.h"
#include <stdbool.h>

using namespace std;
class Forme
{
protected:
	string _couleur;
	string _couleurs[6] = { "black",  "blue", "red", "green", "yellow", "cyan" };
	
public:

	virtual ~Forme() {};
	Forme(string couleur= "black");

	void setCouleur(const string &couleur) { _couleur = couleur; };
	string getCouleur() { return _couleur; };
	
	//virtual bool dessiner(VisiteurDessin visiteur) const = 0;

	virtual double getAire() const = 0;

	virtual Forme * Translation(const Vecteur2D & v)const = 0;
	virtual Forme * Homothetie(const Vecteur2D & v, const double rapport)const = 0;
	virtual Forme * Rotation(const Vecteur2D & v, const double angle) const = 0;
};