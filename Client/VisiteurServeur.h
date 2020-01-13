#pragma once
/**
 * Classe VisiteurDessin
 */

#include "VisiteurDessin.h"
#include "Connexion.h"


class VisiteurServeur :	public VisiteurDessin
{
private:
	Connexion _connexion; ///Connexion � travers laquelle se feront les requetes
public:

	/**
	 * Constructeur avec Connexion d�ja effectu�e
	 * @param c : Connexion � un serveur
	 */
	VisiteurServeur(Connexion c) : VisiteurDessin(), _connexion(c) {};

	/**
	 * Constructeur � z�ro
	 * @param adresse : Adresse du serveur auquel il faut se connecter
	 * @param port : Port de connexion au serveur
	 */
	VisiteurServeur(char adresse[L], short port);

	/**
	 * Destructeur par d�faut
	 */
	~VisiteurServeur() {
		_connexion.arreter();
	};

	/**
	 * Red�finie la connexion du VisiteurServeur
	 * @param c : Nouvelle connexion
	 */
	void setConnexion(Connexion c) { _connexion = c; };

	/**
	 * @return la connexion de VisiteurServeur
	 */
	Connexion & getConnexion() { return _connexion; };

	/**
	 * Visiteur pour le dessin d'un segment
	 * @param s : Segment � visiter
	 */
	virtual void visite(const Segment * s)const;

	/**
	 * Visiteur pour le dessin d'un Cercle
	 * @param c : Cercle � visiter
	 */
	virtual void visite(const Cercle * c)const;

	/**
	 * Visiteur pour le dessin d'un Polygone
	 * @param p : Polygone � visiter
	 */
	virtual void visite(const Polygone * p)const;

	/**
	 * Visiteur pour le dessin d'un Triangle
	 * @param t : Triangle � visiter
	 */
	virtual void visite(const Triangle * t)const;
	
	/**
	 * Visiteur pour le dessin d'une FormeComposee
	 * @param f : FormeComposee � visiter
	 */
	virtual void visite(const FormeComposee * f)const;
};