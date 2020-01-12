#include "Triangle.h"


Triangle::Triangle(const Vecteur2D & a, const Vecteur2D & b, const Vecteur2D & c, const string & couleur):Forme(couleur),_a(a),_b(b),_c(c) {

}

void Triangle::setA(Vecteur2D a) {
	_a = a;
}

void Triangle::setB(Vecteur2D b){
	_b = b;
}

void Triangle::setC(Vecteur2D c){
	_c = c;
}

double Triangle::getAire()const {
	return 0.00;
}

Forme * Triangle::Translation(const Vecteur2D & v)const {
	Triangle * t = new Triangle(_a.Translation(v), _b.Translation(v), _c.Translation(v), _couleur);
	return t;
}

Forme * Triangle::Homothetie(const Vecteur2D & v, const double rapport)const {
	Triangle * t = new Triangle(_a.Homothetie(v, rapport), _b.Homothetie(v, rapport), _b.Homothetie(v, rapport), _couleur);
	return t;
}

Forme * Triangle::Rotation(const Vecteur2D & v, const double angle)const {
	Triangle * t = new Triangle(_a.Rotation(v, angle), _b.Rotation(v, angle), _b.Rotation(v, angle), _couleur);
	return t;
}
