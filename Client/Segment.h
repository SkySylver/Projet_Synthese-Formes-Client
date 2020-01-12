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


	virtual double getAire() const { return 0.00; }

	virtual void dessiner(const VisiteurDessin & visiteur) const;

	virtual operator string() const;

	virtual Forme * Translation(const Vecteur2D & v)const;
	virtual Forme * Homothetie(const Vecteur2D & v, const double rapport)const;
	virtual Forme * Rotation(const Vecteur2D & v, const double angle)const;

};

