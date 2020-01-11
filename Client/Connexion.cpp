#include "Connexion.h"
#include "Erreur.h"

//#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma warning(disable:4996)

/**
 * Constructeur par défaut
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
	r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2

	if (r) throw Erreur("L'initialisation a échoué");
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
		oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
		throw Erreur(oss.str().c_str());
	}
}

/**
 * Lance une connexion entre le client et le serveur
 * @param adresseServeur : Adresse du serveur en format char *
 * @param portServeur : Port sur lequel la connexion est lancée
 */
void Connexion::lancer(char adresseServeur[L], short portServeur) {
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
	sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

	r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
																			// Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
	if (r == SOCKET_ERROR) throw Erreur("La connexion a échoué");
}


/**
 * Envoie une requete au serveur
 * @param requete : Requete a envoyer
 */
void Connexion::requete(char * requete) {

	strcat(requete, "\r\n");     // pour que le serveur réceptionne bien le message
	int l = strlen(requete);

	r = send(sock, requete, l, 0);             //------------------ envoi de la requête au serveur -------------------------------
												// envoie au plus  l octets
	if (r == SOCKET_ERROR)
		throw Erreur("échec de l'envoi de la requête");
}

/*
 * Arrete la connexion
 */
void Connexion::arreter() {
	r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la réception
													// renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
	if (r == SOCKET_ERROR)
		throw Erreur("la coupure de connexion a échoué");

	r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
	if (r) throw Erreur("La fermeture du socket a échoué");

	WSACleanup();
	cout << "Arrêt du client" << endl;
}