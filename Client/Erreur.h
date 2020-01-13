#pragma once
/**
classe Erreur
*/

using namespace std;

#include <string>
#include <iostream>

class Erreur
{
public:
	const static int LONGUEURMESSAGE = 500; ///Longueur maximale du message d'Erreur
	char message[1 + LONGUEURMESSAGE]; ///Message d'Erreur
	
	/**
	 * Constructeur par défaut
	 */
	Erreur();

	/**
	 * Constructeur avec message
	 * @param messageErreur : Le message d'erreur
	 */
	Erreur(const char * messageErreur);

	/**
	 * Destructeur par défaut
	 */
	~Erreur() {};

	/**
	 * Opérateur de conversion en string
	 * @return L'Erreur au format string
	 */
	operator string() const;
};

ostream & operator << (ostream & os, const Erreur & erreur);
