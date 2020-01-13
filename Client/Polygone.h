#pragma once
#include "Forme.h"
#include "Triangle.h"
#include <vector>

class Polygone: public Forme
{
private :
	vector<Vecteur2D> _vecteurs; /// Vecteur de points, représentant le polygone
public :
	
	/**
	 * Constructeur
	 * @param v : Liste des vecteurs correspondant à la forme
	 * @param couleuur : couleur de la forme
	 */
	Polygone(const vector<Vecteur2D> & v, string couleur): Forme(couleur), _vecteurs(v){}
	
	/**
	 * Destructeur
	 */
	~Polygone() {};

	virtual void dessiner(const VisiteurDessin & visiteur) const;


	/**
	 *@return La liste des points
	 */
	vector<Vecteur2D> getVecteurs() const;
	
	/**
	 * @param v : Nouvelle liste de vecteurs
	 */
	void setVecteur(const vector<Vecteur2D> & v);


	/**
	 * @param v : Vecteur à ajouter à la liste des _vecteurs
	 */
	void ajouterVecteur(Vecteur2D v);

	/**
	 * @param v : Vecteur à supprimer de la liste des _vecteurs
	 */
	void retirerVecteur(Vecteur2D v);

	double getAire() const;

	operator string() const;

	Forme * Translation(const Vecteur2D & v)const;
	Forme * Homothetie(const Vecteur2D & v, const double rapport)const;
	Forme * Rotation(const Vecteur2D & v, const double angle) const;

	Polygone & operator + (const Vecteur2D & v);
	Polygone & operator - (const Vecteur2D & v);

};

