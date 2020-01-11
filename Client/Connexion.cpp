#include "Connexion.h"
#include "Erreur.h"

//#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma warning(disable:4996)

/**
 * Constructeur par d�faut
 * 
 */
Connexion::Connexion(WSADATA &wsaData, int familleAdresse, int typeSocket, int protocole, char adresseServeur[L], short portServeur) {
	initWinsockLib(wsaData);
	creerSocket(familleAdresse, typeSocket, protocole);
	lancer(adresseServeur, portServeur);
}

/**
 * Initialise la librairie winsock
 *
 */
void Connexion::initWinsockLib(WSADATA & wsaData) {
	r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2

	if (r) throw Erreur("L'initialisation a �chou�");
}

/**
 * Creer un socket pour ce client
 * @param familleAdresse : 
 * @param typeSocket : Type du socket
 * @param protocole : Protocole
 * 
 */
void Connexion::creerSocket(int familleAdresse, int typeSocket, int protocole) {
	sock = socket(familleAdresse, typeSocket, protocole);

	if (sock == INVALID_SOCKET)
	{
		ostringstream oss;
		oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoy�es par WSAGetLastError() : cf. doc r�f winsock
		throw Erreur(oss.str().c_str());
	}
}

/**
 * Lance une connexion entre le client et le serveur
 * @param adresseServeur : Adresse du serveur en format char *
 * @param portServeur : Port sur lequel la connexion est lanc�e
 */
void Connexion::lancer(char adresseServeur[L], short portServeur) {
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
	sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)

	r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
																			// Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
	if (r == SOCKET_ERROR) throw Erreur("La connexion a �chou�");
}


/**
 * Envoie une requete au serveur
 * @param requete : Requete a envoyer
 */
void Connexion::requete(char * requete) {

	strcat(requete, "\r\n");     // pour que le serveur r�ceptionne bien le message
	int l = strlen(requete);

	r = send(sock, requete, l, 0);             //------------------ envoi de la requ�te au serveur -------------------------------
												// envoie au plus  l octets
	if (r == SOCKET_ERROR)
		throw Erreur("�chec de l'envoi de la requ�te");
}

/*
 * Arrete la connexion
 */
void Connexion::arreter() {
	r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la r�ception
													// renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
	if (r == SOCKET_ERROR)
		throw Erreur("la coupure de connexion a �chou�");

	r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
	if (r) throw Erreur("La fermeture du socket a �chou�");

	WSACleanup();
	cout << "Arr�t du client" << endl;
}