#pragma once
/**
 * Classe Triangle
 */

#include "Forme.h"

class Triangle: public Forme
{
private:
	Vecteur2D _a, _b, _c; ///Points représentants du Triangle

public:

	/**
	 * Constructeur de Segment
	 * @param a : Point a du Segment
	 * @param b : Point b du Segment
	 * @param couleur : Couleur du Segment
	 */
	Triangle(const Vecteur2D &a, const Vecteur2D & b, const Vecteur2D & c, const string & couleur = "black");

	/**
	 * Destructeur par défaut
	 */
	~Triangle() {};

	/**
	 * Setter Point a
	 * @param a : Nouveau Vecteur2D a
	 */
	void setA(Vecteur2D a);

	/**
	 * Setter Point b
	 * @param b : Nouveau Vecteur2D b
	 */
	void setB(Vecteur2D b);
	
	/**
	 * Setter Point c
	 * @param c : Nouveau Vecteur2D c
	 */
	void setC(Vecteur2D c);

	/**
	 * Getter Point a
	 * @return Vecteur2D a
	 */
	Vecteur2D getA()const { return _a; };

	/**
	 * Getter Point b
	 * @return Vecteur2D b
	 */
	Vecteur2D getB()const { return _b; };

	/**
	 * Getter Point c
	 * @return Vecteur2D c
	 */
	Vecteur2D getC()const { return _c; };

	/**
	 * Opérateur de conversion en string
	 * @return le Triangle au format string
	 */
	operator string() const;

	/**
	 * Sauvegarde cette forme
	 * @param v : Correspond au type de sauvegarde qui sera faite
	 */
	void sauvegarder(VisiteurSauvegarde * v);

	/**
	 * Dessine en fonction du visiteurDessin (Serveur, Librairie graphique, etc...)
	 * @param visiteur : Visiteur
	 */
	virtual void dessiner(const VisiteurDessin & visiteur) const;

	/**
	 * @return l'aire du Triangle
	 */
	double getAire() const;

	/**
	 * Retourne la translation du Triangle par le vecteur v
	 * @param v : le vecteur2D de translation
	 * @return la translation du Triangle par le vecteur v
	 */
	Forme * Translation(const Vecteur2D & v)const;
	
	/**
	 * Effectue l'homothetie du Triangle avec le vecteur v et un rapport d'homothetie
	 * @param v : Vecteur utilisé pour l'homothetie
	 * @param rapport : Rapport d'homothetie
	 * @return L'homothetie du Triangle
	 */
	Forme * Homothetie(const Vecteur2D & v, const double rapport)const;
	
	/**
	 * Effectue la rotation du Triangle avec un vecteur et un angle de rotation
	 * @param v : Centre de la rotation
	 * @param rapport : angle de rotation
	 * @return La rotation du Triangle
	 */
	Forme * Rotation(const Vecteur2D & v, const double angle)const;



};

