#pragma once

/**
 * Classe FormeComposee
 */

#include "Forme.h"
#include <vector>
using namespace std;

class FormeComposee:public Forme
{
private:
	vector<Forme*> _groupe;
public:

	/**
	 * Destructeur par d�faut
	 */
	FormeComposee() {};
	
	/**
	 * Constructeur avec formes
	 */
	FormeComposee(Forme * f);

	/**
	 * Destructeur par d�faut
	 */
	~FormeComposee() {};

	/**
	 * Ajouter une forme � la forme compos�e
	 * @param f : Forme � ajouter
	 */
	void ajouterForme(Forme * f);

	/**
	 * Supprimer une Forme de la forme compos�e
	 * @param f : Forme � supprimer
	 */
	void supprimerForme(Forme * f);

	/**
	 * @return L'aire de la forme compos�e
	 */
	double getAire() const;
	
	/**
	 * @return vector<Forme*> correspondant � la liste des Forme composantes de la FormeComposee
	 */
	vector<Forme*> getGroupe() const { return _groupe; };

	/**
	 * Dessine en fonction du visiteurDessin (Serveur, Librairie graphique, etc...)
	 * @param visiteur : Visiteur
	 */
	virtual void dessiner(const VisiteurDessin & visiteur) const;

	 /**
	  * Op�rateur de conversion en string
	  * @return la FormeComposee au format string
	  */
	operator string() const;

	/**
	 * Retourne la translation de la FormeComposee par le vecteur v
	 * @param v : le vecteur2D de translation
	 * @return la translation de la FormeComposee par le vecteur v
	 */
	Forme * Translation(const Vecteur2D & v)const;

	/**
	 * Effectue l'homothetie de la FormeComposee avec le vecteur v et un rapport d'homothetie
	 * @param v : Vecteur utilis� pour l'homothetie
	 * @param rapport : Rapport d'homothetie
	 * @return L'homothetie de la FormeComposee
	 */
	Forme * Homothetie(const Vecteur2D & v, const double rapport)const;

	/**
	 * Effectue la rotation de la FormeComposee avec un vecteur et un angle de rotation
	 * @param v : Centre de la rotation
	 * @param rapport : angle de rotation
	 * @return La rotation de la FormeComposee
	 */
	Forme * Rotation(const Vecteur2D & v, const double angle)const;

};