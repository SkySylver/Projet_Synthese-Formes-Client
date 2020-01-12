#pragma once
#include "Forme.h"
#include "Triangle.h"
#include <vector>

class Polygone: public Forme
{
private :
	vector<Vecteur2D> _vecteurs; /// Vecteur de points, représentant le polygone
public :
	Polygone(const vector<Vecteur2D> & v, string couleur): Forme(couleur), _vecteurs(v){}
	~Polygone() {}; ///Destructeur par défaut
	//virtual bool dessiner(VisiteurDessin visiteur) const = 0;

	vector<Vecteur2D> getVecteurs(); ///@return La liste des points
	void setVecteur(const vector<Vecteur2D> & v);

	void ajouterVecteur(Vecteur2D v);
	void retirerVecteur(Vecteur2D v);

	double getAire() const;

	operator string() const;

	Forme * Translation(const Vecteur2D & v)const;
	Forme * Homothetie(const Vecteur2D & v, const double rapport)const;
	Forme * Rotation(const Vecteur2D & v, const double angle) const;

	Polygone & operator + (const Vecteur2D & v);
	Polygone & operator - (const Vecteur2D & v);

};

