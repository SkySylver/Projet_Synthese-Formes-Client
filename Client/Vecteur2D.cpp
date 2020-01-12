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
{
	ostringstream os;
	os << "( " << x << ", " << y << ")";
	return os.str();
}

ostream & operator << (ostream & os, const Vecteur2D & u)
{
	os << (string)u;
	return os;
}


Vecteur2D Vecteur2D::Translation(const Vecteur2D & v) const{
	return Vecteur2D((x + v.x), (y + v.y));
}

Vecteur2D Vecteur2D::Homothetie(const Vecteur2D & v, const double rapport)const {
	return Vecteur2D((v.x + ((x - v.x) * rapport)), (v.y + ((y - v.y) * rapport)));
}

Vecteur2D Vecteur2D::Rotation(const Vecteur2D & v, const double angle)const {
	Vecteur2D vt = *this - v;

	return Vecteur2D(((vt.x * cos(angle) + vt.y * sin(angle)) + v.x), ((-vt.x * sin(angle) + vt.y * cos(angle)) + v.y));
}