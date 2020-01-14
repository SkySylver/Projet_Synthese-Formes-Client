#pragma once
/**
 * Classe Polygone
 */

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
	Polygone(const vector<Vecteur2D> & v, string couleur="black"): Forme(couleur), _vecteurs(v){}
	
	/**
	 * Destructeur
	 */
	~Polygone() {};

	/**
	 * Dessine en fonction du visiteurDessin (Serveur, Librairie graphique, etc...)
	 * @param visiteur : Visiteur
	 */
	virtual void dessiner(const VisiteurDessin & visiteur) const;


	 /**
	  * @return vector<Vecteur2D> correspondant à la liste liste des points représentants du Polygone
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

	/**
	 * @return l'aire du Polygone
	 */
	double getAire() const;

	/**
	 * Opérateur de conversion en string
	 * @return le Polygone au format string
	 */
	operator string() const;

	/**
	 * Retourne la translation du Polygone par le vecteur v
	 * @param v : le vecteur2D de translation
	 * @return la translation du Polygone par le vecteur v
	 */
	Forme * Translation(const Vecteur2D & v)const;
	
	/**
	 * Effectue l'homothetie du Polygone avec le vecteur v et un rapport d'homothetie
	 * @param v : Vecteur utilisé pour l'homothetie
	 * @param rapport : Rapport d'homothetie
	 * @return L'homothetie du Polygone
	 */
	Forme * Homothetie(const Vecteur2D & v, const double rapport)const;
	
	/**
	 * Effectue la rotation du Polygone avec un vecteur et un angle de rotation
	 * @param v : Centre de la rotation
	 * @param rapport : angle de rotation
	 * @return La rotation du Polygone
	 */
	Forme * Rotation(const Vecteur2D & v, const double angle) const;

	/**
	 * Opérateur permettant l'ajout d'un point au Polygone
	 * @param v : Vecteur2D point à ajouter
	 */
	Polygone & operator + (const Vecteur2D & v);

	/**
	 * Opérateur permettant la suppression d'un point du Polygone
	 * @param v : Vecteur2D point à supprimer
	 */
	Polygone & operator - (const Vecteur2D & v);

};

