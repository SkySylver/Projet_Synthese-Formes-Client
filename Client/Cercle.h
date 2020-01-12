#pragma once
#include "Forme.h"

class Cercle: public Forme
{

private:
	Vecteur2D _centre; /// Centre du cercle
	double _rayon; ///Rayon du cercle

public:

	/**
	 * Constructeur d'un cercle
	 * @param centre : Centre du cercle
	 * @param rayon : Rayon du cercle
	 * @param couleur : Couleur du cercle
	 */
	Cercle(const Vecteur2D & centre, const double & rayon, const string & couleur);

	/**
	 * Destructeur par défaut
	 */
	~Cercle() {};


	Vecteur2D getCentre() { return _centre; };/// @return Le centre du cercle
	double getRayon() { return _rayon; }; ///@return Le rayon du cercle


	void setCentre(Vecteur2D centre) { _centre = centre; }; ///Redéfini le centre du cercle
	void setRayon(double rayon) { _rayon = rayon; }; /// Redéfini le rayon du cercle


	double getAire() const { return _rayon * _rayon * PI; }; /// @return l'aire du cercle
	operator string() const; ///@ return le cercle sous forme de string

	virtual void dessiner(const VisiteurDessin & visiteur) const;

	/**
	 * Retourne la translation du cercle par le vecteur v
	 * @param v : le vecteur2D de translation
	 * @return la translation du cercle par le vecteur v
	 */
	Forme * Translation(const Vecteur2D & v) const;

	/**
	 * Effectue l'homothetie du cercle avec le vecteur v et un rapport d'homothetie
	 * @param v : Vecteur utilisé pour l'homothetie
	 * @param rapport : Rapport d'homothetie
	 * @return L'homothetie du cercle
	 */
	Forme * Homothetie(const Vecteur2D & v, const double rapport)const;

	/**
	 * Effectue la rotation du cercle avec un vecteur et un angle de rotation
	 * @param v : Centre de la rotation
	 * @param rapport : angle de rotation
	 * @return La rotation du cercle
	 */
	Forme * Rotation(const Vecteur2D & v, const double angle)const;
};

