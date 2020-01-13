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
	char adresseServeur[L] = "192.168.1.100";
	short portServeur = 6666;


	Vecteur2D a(1, 1);
	Vecteur2D b(2, 2);
	Vecteur2D c(3, 3);
	Vecteur2D d(4, 4);
	
//	Connexion Co(adresseServeur, portServeur);

//	Co.requete("Segment;blue,10,10,10,10");

	VisiteurServeur V(adresseServeur, portServeur);

	Segment G(a, b);
	G.dessiner(V);


	WSACleanup();

	system("PAUSE");


	return 0;
}
