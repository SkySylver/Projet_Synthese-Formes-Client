#pragma once
/**
 * Classe Segment
 */

#include "Forme.h"

class Segment: public Forme
{
private:
	Vecteur2D _a, _b; ///Points représentants du Segment

public:

	/**
	 * Constructeur de Segment
	 * @param a : Point a du Segment
	 * @param b : Point b du Segment
	 * @param couleur : Couleur du Segment
	 */
	Segment(const Vecteur2D & a, const Vecteur2D & b, const string & couleur = "black");

	/**
	 * Destructeur par défaut
	 */
	~Segment() {};
	
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
	 * Setter Point a
	 * @param a : Nouveau Vecteur2D a
	 */
	void setA(Vecteur2D a) { _a = a; };

	/**
	 * Setter Point b
	 * @param b : Nouveau Vecteur2D b
	 */
	void setB(Vecteur2D b) { _b = b; };

	/**
	 * @return l'aire du Segment
	 */
	double getAire() const { return 0.00; }


//	void sauvegarder(const VisiteurSauvegarde * vS)const;
	
	/**
	 * Dessine en fonction du visiteurDessin (Serveur, Librairie graphique, etc...)
	 * @param visiteur : Visiteur
	 */
	virtual void dessiner(const VisiteurDessin & visiteur) const;

	/**
	 * Opérateur de conversion en string
	 * @return le Segment au format string
	 */
	operator string() const;

	/**
	 * Retourne la translation du Segment par le vecteur v
	 * @param v : le vecteur2D de translation
	 * @return la translation du Segment par le vecteur v
	 */
	Forme * Translation(const Vecteur2D & v)const;

	/**
	 * Effectue l'homothetie du Segment avec le vecteur v et un rapport d'homothetie
	 * @param v : Vecteur utilisé pour l'homothetie
	 * @param rapport : Rapport d'homothetie
	 * @return L'homothetie du Segment
	 */
	Forme * Homothetie(const Vecteur2D & v, const double rapport)const;

	/**
	 * Effectue la rotation du Segment avec un vecteur et un angle de rotation
	 * @param v : Centre de la rotation
	 * @param rapport : angle de rotation
	 * @return La rotation du Segment
	 */
	Forme * Rotation(const Vecteur2D & v, const double angle)const;
};

