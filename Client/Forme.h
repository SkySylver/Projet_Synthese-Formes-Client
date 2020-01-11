#pragma once
#include <string>
#include <stdexcept>
#include "Vecteur2D.h"

using namespace std;
class Forme
{
private:
	string _couleur;
	string _couleurs[6] = { "black",  "blue", "red", "green", "yellow", "cyan" };
	
public:

	Forme() {};
	~Forme() {};
	Forme(string couleur);

	void setCouleur(const string &couleur) { _couleur = couleur; };
	string getCouleur() { return _couleur; };

	virtual bool dessiner(string requete) const = 0;
	virtual bool dessinerForme(string requete) const = 0;


	virtual Forme * Homothetie()const=0;
	virtual Forme * Translation()const=0;
	virtual Forme * Rotation()const=0;
};