#pragma once
#include "stdio.h"
#include <string>
#include <stdexcept>
#include "Vecteur2D.h"
#include <sstream>
#include <iostream>

class VisiteurDessin;

class Forme {
protected:
	string _couleur;
	string _couleurs[6] = { "black",  "blue", "red", "green", "yellow", "cyan" };
	const double PI = 3.14159265;

public:
	/**
	 * Destructeur par défaut
	 */
	~Forme() {};

	/**
	 * Constructeur avec couleur
	 */
	Forme(string couleur = "dark");

	/**
	 * @param couleur : Nouvelle couleur
	 */
	void setCouleur(const string &couleur) { _couleur = couleur; };

	/**
	 * @return couleur de la forme
	 */
	string getCouleur() const { return _couleur; };

	/**
	 * Dessine en fonctione du visiteur
	 * @param visiteur
	 */
	virtual void dessiner(const VisiteurDessin & visiteur) const= 0;
	//Forme * clone(const Forme & f) const;

	/**
	 * @return le cercle sous forme de string
	 */
	virtual operator string() const = 0;

	/**
	 * @return l'aire du cercle
	 */
	virtual double getAire() const = 0;

	/**
	 * Retourne la translation du cercle par le vecteur v
	 * @param v : le vecteur2D de translation
	 * @return la translation du cercle par le vecteur v
	 */
	virtual Forme * Translation(const Vecteur2D & v) const = 0;

	/**
	 * Effectue l'homothetie du cercle avec le vecteur v et un rapport d'homothetie
	 * @param v : Vecteur utilisé pour l'homothetie
	 * @param rapport : Rapport d'homothetie
	 * @return L'homothetie du cercle
	 */
	virtual Forme * Homothetie(const Vecteur2D & v, const double rapport) const = 0;
	
	/**
	 * Effectue la rotation du cercle avec un vecteur et un angle de rotation
	 * @param v : Centre de la rotation
	 * @param rapport : angle de rotation
	 * @return La rotation du cercle
	 */
	virtual Forme * Rotation(const Vecteur2D & v, const double angle) const = 0;

};