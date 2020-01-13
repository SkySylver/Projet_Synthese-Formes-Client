#pragma once

/**
 * Classe Forme
 */

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
	 * @return couleur de la Forme
	 */
	string getCouleur() const { return _couleur; };

	/**
	 * Dessine en fonction du visiteurDessin (Serveur, Librairie graphique, etc...)
	 * @param visiteur : Visiteur
	 */
	virtual void dessiner(const VisiteurDessin & visiteur) const= 0;

	//Forme * clone(const Forme & f) const;

	 /**
	  * Opérateur de conversion en string
	  * @return la Forme au format string
	  */
	virtual operator string() const = 0;

	/**
	 * @return l'aire de la Forme
	 */
	virtual double getAire() const = 0;

	/**
	 * Retourne la translation de la Forme par le vecteur v
	 * @param v : le vecteur2D de translation
	 * @return la translation de la Forme par le vecteur v
	 */
	virtual Forme * Translation(const Vecteur2D & v) const = 0;

	/**
	 * Effectue l'homothetie de la Forme avec le vecteur v et un rapport d'homothetie
	 * @param v : Vecteur utilisé pour l'homothetie
	 * @param rapport : Rapport d'homothetie
	 * @return L'homothetie de la Forme
	 */
	virtual Forme * Homothetie(const Vecteur2D & v, const double rapport) const = 0;
	
	/**
	 * Effectue la rotation de la Forme avec un vecteur et un angle de rotation
	 * @param v : Centre de la rotation
	 * @param rapport : angle de rotation
	 * @return La rotation de la Forme
	 */
	virtual Forme * Rotation(const Vecteur2D & v, const double angle) const = 0;

};