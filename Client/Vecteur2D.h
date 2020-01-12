#pragma once
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
	return u + -v;
}


class Vecteur2D
{
public:
	double x, y;

	inline explicit Vecteur2D(const double & x = 0, const double & y = 0);

	/**
	 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
	 *
	 */
	//inline Vecteur2D(const char * s);
	inline const Vecteur2D operator + (const Vecteur2D & u) const;
	inline const Vecteur2D operator * (const double & a) const;
	/**
	 * - unaire (c'est-à- dire opposé d'un vecteur)
	 * */
	inline const Vecteur2D operator - () const;

	operator string() const;

	/*
	 * Translation du Vecteur par le Vecteur v
	 * @param v : Vecteur2D permettant la translation
	 */
	Vecteur2D Translation(const Vecteur2D & v)const;

	/*
	 * Homothetie du Vecteur par le Vecteur v avec rapport d'homothetie rapport
	 * @param v: Vecteur2D
	 * @param rapport: Rapport d'homothetie
	 */
	Vecteur2D Homothetie(const Vecteur2D & v, const double rapport)const;

	/*
	 *  Rotation avec pour centre v et angle angle
	 * @param v : Vecteur2D correspondant au centre
	 * @param angle : Angle de rotation
	 * @return le vecteur corrrepondant à la rotation
	 */
	Vecteur2D Rotation(const Vecteur2D & v, const double angle)const;


}; // classe Vecteur2D

inline  Vecteur2D::Vecteur2D(const double & x, const double & y) : x(x), y(y) {}

inline const Vecteur2D operator * (const double & a, const Vecteur2D & u) { return u * a; }
