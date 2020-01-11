#include "Vecteur2D.h"

inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
	return Vecteur2D(x + u.x, y + u.y);
}

inline const Vecteur2D Vecteur2D::operator * (const double & a) const
{
	return Vecteur2D(x*a, y*a);
}

inline const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-x, -y);
}

Vecteur2D::operator string() const
{/*
	ostringstream os;
	os << "( " << x << ", " << y << ")";
	return os.str();*/return "eee";
}

ostream & operator << (ostream & os, const Vecteur2D & u)
{
	os << (string)u;
	return os;
}
