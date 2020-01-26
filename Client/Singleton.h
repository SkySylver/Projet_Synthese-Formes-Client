#pragma once
/**
 * Classe Singleton
 */

#include <winsock.h>
#include "Erreur.h"
class Singleton
{
private:
	/**
	* instance du singleton
	*/
	static Singleton instance;
public:
	
	/*
	 * Constructeur par défaut
	 * Initialise la librairie Winsock
	 */
	Singleton();

	/**
	 * Destructeur par défaut
	 */
	~Singleton();
	/**
	*	retourne l'instance du singleton
	*/
	static Singleton& getInstance();
};

