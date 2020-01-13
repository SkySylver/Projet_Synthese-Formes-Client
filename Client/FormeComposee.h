#pragma once
#include "Forme.h"
#include <vector>
using namespace std;

class FormeComposee:public Forme
{
private:
	vector<Forme*> _groupe;
public:

	/**
	 * Destructeur par défaut
	 */
	FormeComposee() {};
	
	/**
	 * Constructeur par avec formes
	 */
	FormeComposee(Forme * f);

	/**
	 * Destructeur par défaut
	 */
	~FormeComposee() {};

	/**
	 * 
	 *
	 *
	 */
	void ajouterForme(Forme * f);
	void supprimerForme(Forme * f);
	double getAire() const;

	vector<Forme*> getGroupe() const { return _groupe; };

	virtual void dessiner(const VisiteurDessin & visiteur) const;

	operator string() const;

	Forme * Translation(const Vecteur2D & v)const;
	Forme * Homothetie(const Vecteur2D & v, const double rapport)const;
	Forme * Rotation(const Vecteur2D & v, const double angle)const;

};