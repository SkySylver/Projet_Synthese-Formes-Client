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
	 * Constructeur par d�faut
	 * Initialise la librairie Winsock
	 */
	Singleton();

	/**
	 * Destructeur par d�faut
	 */
	~Singleton();
};

