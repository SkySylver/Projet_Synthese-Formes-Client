#include "Forme.h"
#include "VisiteurServeur.h"
#include "Connexion.h"
#include "Erreur.h"
using namespace std;

int main()
{

	WSAData _wsaData;

	int _r;
	_r = WSAStartup(MAKEWORD(2, 0), &_wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2

	if (_r) throw Erreur("L'initialisation a échoué");
//	initWinsockLib(_wsaData);
	/*	WSADATA wsaData;
		int familleAdresse = AF_INET;
		int typeSocket = SOCK_STREAM;
		int protocole = IPPROTO_TCP;
		*/
	char adresseServeur[L] = "10.11.85.253";
	short portServeur = 6666;


	Vecteur2D a(100, 100);
	Vecteur2D b(200, 200);
	Vecteur2D c(200,200);
	Vecteur2D d(200, 4);
	
	//Connexion Co(adresseServeur, portServeur);

	VisiteurServeur V(adresseServeur, portServeur);

	vector<Vecteur2D> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);

	Segment G(a, b, "red");
	Triangle T(a, b, c, "blue");
	Cercle C(c, 150.00, "blue");
	Polygone P(v, "blue");
	//	Segment G(a, b, "blue");
//	Segment G(a, b, "blue");
	//P.dessiner(V);
	FormeComposee fc;
	fc.ajouterForme(&G);
	fc.dessiner(V);

//	Co.requete("Segment;blue,10,10,100,100");
//	Co.requete("Cercle;blue,10,10,100,100");
	//Co.requete("Polygone;black,100,100,100,200,300,300,400,300,500,500");


	getchar();
	return 0;
}
