#pragma once
#include <string>
using namespace std;
class Forme
{
private:
	string _couleur;
	
public:

	Forme() {};
	~Forme() {};
	Forme(string couleur):_couleur(couleur) {};



	void setCouleur(const string &couleur) { _couleur = couleur; };
	string getCouleur() { return _couleur; };


	virtual bool dessiner(string requete) = 0;
	virtual bool dessinerForme(string requete) = 0;


	virtual Forme * Homothetie()const=0;
	virtual Forme * Translation()const=0;
	virtual Forme * Rotation()const=0;
};