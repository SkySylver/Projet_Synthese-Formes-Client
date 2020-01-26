#pragma once
/**
 * Classe Singleton
 */

#include <winsock.h>
#include "Erreur.h"
class Singleton
{
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
};

