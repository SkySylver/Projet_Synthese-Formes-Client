#pragma once
#include "Forme.h"

class Triangle: public Forme
{
private:
	Vecteur2D _a, _b, _c;


public:
	Triangle(const Vecteur2D &a, const Vecteur2D & b, const Vecteur2D & c, const string & couleur = "black");

	~Triangle() {};

	void setA(Vecteur2D a);
	void setB(Vecteur2D b);
	void setC(Vecteur2D c);

	Vecteur2D getA() { return _a; };
	Vecteur2D getB() { return _b; };
	Vecteur2D getC() { return _c; };


	//virtual bool dessiner(VisiteurDessin visiteur) const;

	virtual double getAire() const;


	Forme * Translation(const Vecteur2D & v)const;
	Forme * Homothetie(const Vecteur2D & v, const double rapport)const;
	Forme * Rotation(const Vecteur2D & v, const double angle)const;



};

