#pragma once
#include "Forme.h"
class Segment: public Forme
{
private:
	Vecteur2D _a, _b;

public:
	Segment(const Vecteur2D & a, const Vecteur2D & b, const string & couleur = "black");
	~Segment() {};
	
    
	Vecteur2D getA() { return _a; };
	Vecteur2D getB() { return _b; };
	void setA(Vecteur2D a) { _a = a; };
	void setB(Vecteur2D b) { _b = b; };


	double getAire() const { return 0.00; }

	void sauvegarder(const VisiteurSauvegarde * vS)const;
	virtual void dessiner(const VisiteurDessin & visiteur) const;

	operator string() const;

	Forme * Translation(const Vecteur2D & v)const;
	Forme * Homothetie(const Vecteur2D & v, const double rapport)const;
	Forme * Rotation(const Vecteur2D & v, const double angle)const;

};

