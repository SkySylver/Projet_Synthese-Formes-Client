#pragma once
#include "Forme.h"
#include "Triangle.h"
#include <vector>



class Polygone: public Forme
{
private :
	vector<Vecteur2D>_vecteurs;
public :
	Polygone(const vector<Vecteur2D> & v, string couleur): Forme(couleur), _vecteurs(v){}
	~Polygone() {};
	//virtual bool dessiner(VisiteurDessin visiteur) const = 0;

	double getAire() const;

	operator string() const;

	Forme * Translation(const Vecteur2D & v)const;
	Forme * Homothetie(const Vecteur2D & v, const double rapport)const;
	Forme * Rotation(const Vecteur2D & v, const double angle) const;
};

