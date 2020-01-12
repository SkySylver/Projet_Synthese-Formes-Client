#pragma once
#include "Forme.h"
class Cercle: public Forme
{

private:
	Vecteur2D _centre;
	double _rayon;

public:
	
	Cercle(const Vecteur2D & centre, const double & rayon, const string & couleur);
	~Cercle() {};

	Vecteur2D getCentre() { return _centre; };
	double getRayon() { return _rayon; };
	void setCentre(Vecteur2D centre) { _centre = centre; };
	void setRayon(double rayon) { _rayon = rayon; };


	double getAire() const { return _rayon * _rayon * PI; }
	operator string() const;

	//bool dessiner(VisiteurDessin visiteur) const;


	Forme * Translation(const Vecteur2D & v) const;
	Forme * Homothetie(const Vecteur2D & v, const double rapport)const;
	Forme * Rotation(const Vecteur2D & v, const double angle)const;
};

