#include "Connexion.h"
#include "Erreur.h"



Connexion::Connexion() {
	initWinsockLib();
	creerSocket();
	creerRepresentantServeur();
	connexionAuServeur();
}


Connexion::~Connexion() {

}


void Connexion::initWinsockLib(WSADATA wsaData) {
	r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2

	/* en cas de succès, wsaData a été initialisée et l'appel a renvoyé la valeur 0 */

	if (r) throw Erreur("L'initialisation a échoué");

	cout << "initialisation effectuée" << endl;
}

void Connexion::creerSocket(int familleAdresse, int typeSocket, int protocole) {
	sock = socket(familleAdresse, typeSocket, protocole);

	if (sock == INVALID_SOCKET)
	{
		ostringstream oss;
		oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
		throw Erreur(oss.str().c_str());
	}

	cout << "socket créé" << endl;
}

void Connexion::creerRepresentantServeur(char adresseServeur[L], short portServeur) {


	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
	sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)
}

void Connexion::connexionAuServeur() {
	r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
																		// Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

	if (r == SOCKET_ERROR)
		throw Erreur("La connexion a échoué");

	cout << "connexion au serveur de majuscule réussie" << endl;

	bool continuer;
	do
	{
		char requete[L];
		cout << "Tapez la chaîne à mettre en majuscule ou tapez \"quitter\" : ";
		cin >> requete;
		continuer = strcmp(requete, "quitter") != 0;
		if (continuer) {
			strcat_s(requete, "\r\n");     // pour que le serveur réceptionne bien le message
			int l = strlen(requete);

			r = send(sock, requete, l, 0);             //------------------ envoi de la requête au serveur -------------------------------
														// envoie au plus  l octets
			if (r == SOCKET_ERROR)
				throw Erreur("échec de l'envoi de la requête");
		}
	} while (continuer);

	r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la réception
														// renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

	if (r == SOCKET_ERROR)
		throw Erreur("la coupure de connexion a échoué");


	r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
	if (r) throw Erreur("La fermeture du socket a échoué");

	WSACleanup();
	cout << "arrêt normal du client" << endl;
}