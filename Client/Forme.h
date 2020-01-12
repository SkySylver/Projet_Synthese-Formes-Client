#pragma once
#include "stdio.h"
#include <string>
#include <stdexcept>
#include "Vecteur2D.h"
#include "VisiteurDessin.h"
#include <sstream>
#include <iostream>

using namespace std;
class Forme
{
protected:
	string _couleur;
	string _couleurs[6] = { "black",  "blue", "red", "green", "yellow", "cyan" };
	const double PI = 3.14159265;

public:
	~Forme() {};
	Forme(string couleur = "dark");

	void setCouleur(const string &couleur) { _couleur = couleur; };
	string getCouleur() { return _couleur; };

	//	virtual void dessiner(const VisiteurDessin & visiteur) const = 0;

	virtual operator string() const = 0;
	virtual double getAire() const = 0;

	virtual Forme * Translation(const Vecteur2D & v) const = 0;
	virtual Forme * Homothetie(const Vecteur2D & v, const double rapport) const = 0;
	virtual Forme * Rotation(const Vecteur2D & v, const double angle) const = 0;
};