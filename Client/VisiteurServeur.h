#pragma once
/**
 * Classe VisiteurDessin
 */

#include "VisiteurDessin.h"
#include "Connexion.h"


class VisiteurServeur :	public VisiteurDessin
{
private:
	Connexion _connexion; ///Connexion à travers laquelle se feront les requetes
public:

	/**
	 * Constructeur avec Connexion déja effectuée
	 * @param c : Connexion à un serveur
	 */
	VisiteurServeur(Connexion c) : VisiteurDessin(), _connexion(c) {};

	/**
	 * Constructeur à zéro
	 * @param adresse : Adresse du serveur auquel il faut se connecter
	 * @param port : Port de connexion au serveur
	 */
	VisiteurServeur(char adresse[L], short port);

	/**
	 * Destructeur par défaut
	 */
	~VisiteurServeur() {
		_connexion.arreter();
	};

	/**
	 * Redéfinie la connexion du VisiteurServeur
	 * @param c : Nouvelle connexion
	 */
	void setConnexion(Connexion c) { _connexion = c; };

	/**
	 * @return la connexion de VisiteurServeur
	 */
	Connexion & getConnexion() { return _connexion; };

	/**
	 * Visiteur pour le dessin d'un segment
	 * @param s : Segment à visiter
	 */
	virtual void visite(const Segment * s)const;

	/**
	 * Visiteur pour le dessin d'un Cercle
	 * @param c : Cercle à visiter
	 */
	virtual void visite(const Cercle * c)const;

	/**
	 * Visiteur pour le dessin d'un Polygone
	 * @param p : Polygone à visiter
	 */
	virtual void visite(const Polygone * p)const;

	/**
	 * Visiteur pour le dessin d'un Triangle
	 * @param t : Triangle à visiter
	 */
	virtual void visite(const Triangle * t)const;
	
	/**
	 * Visiteur pour le dessin d'une FormeComposee
	 * @param f : FormeComposee à visiter
	 */
	virtual void visite(const FormeComposee * f)const;
};