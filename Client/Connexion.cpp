#include "Connexion.h"
#include "Erreur.h"
#include "stdio.h"

//#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma warning(disable:4996)


Connexion::Connexion(char adresseServeur[L], short portServeur) {
	WSADATA wsaData;
	initWinsockLib(wsaData);

	creerSocket(_familleAdresse, _typeSocket, _protocole);
	lancer(adresseServeur, portServeur);
	Fenetre();
}


Connexion::Connexion(int familleAdresse, int typeSocket, int protocole, char adresseServeur[L], short portServeur): _familleAdresse(familleAdresse), _typeSocket(typeSocket), _protocole(protocole) {
	WSADATA wsaData;
	initWinsockLib(wsaData);
	creerSocket(familleAdresse, typeSocket, protocole);
	lancer(adresseServeur, portServeur);
	Fenetre();
}

void Connexion::initWinsockLib(WSADATA & wsaData) {

	int _r;
	_r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2

	if (_r) throw Erreur("L'initialisation a �chou�");
}


void Connexion::creerSocket(int familleAdresse, int typeSocket, int protocole) {
	_sock = socket(familleAdresse, typeSocket, protocole);

	if (_sock == INVALID_SOCKET)
	{
		ostringstream oss;
		oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoy�es par WSAGetLastError() : cf. doc r�f winsock
		throw Erreur(oss.str().c_str());
	}
}

void Connexion::arreter() {
	int _r = shutdown(_sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la r�ception
												// renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
	if (_r == SOCKET_ERROR)
		throw Erreur("la coupure de connexion a �chou�");

	_r = closesocket(_sock);                          // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
	if (_r) throw Erreur("La fermeture du socket a �chou�");

	WSACleanup();
	cout << "Arret du client" << endl;
}


void Connexion::lancer(char adresseServeur[L], short portServeur) {
	_sockaddr.sin_family = AF_INET;
	_sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
	_sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)


	int _r = connect(_sock, (SOCKADDR *)&_sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
													// Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
	if (_r == SOCKET_ERROR) {
		throw Erreur("La connexion a �chou�");
	}
}

void Connexion::Fenetre() {
	requete("Fenetre,10,10,1000,1000");
}

void Connexion::requete(string requete)const {
	requete.append("\r\n");
	int l = strlen(requete.c_str());

	int _r = send(_sock, requete.c_str(), l, 0);             //------------------ envoi de la requ�te au serveur -------------------------------
												// envoie au plus  l octets
	if (_r == SOCKET_ERROR) {
		cout << "Erreur";
		throw Erreur("�chec de l'envoi de la requ�te");
	}
}
