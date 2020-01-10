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
	r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2

	/* en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0 */

	if (r) throw Erreur("L'initialisation a �chou�");

	cout << "initialisation effectu�e" << endl;
}

void Connexion::creerSocket(int familleAdresse, int typeSocket, int protocole) {
	sock = socket(familleAdresse, typeSocket, protocole);

	if (sock == INVALID_SOCKET)
	{
		ostringstream oss;
		oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoy�es par WSAGetLastError() : cf. doc r�f winsock
		throw Erreur(oss.str().c_str());
	}

	cout << "socket cr��" << endl;
}

void Connexion::creerRepresentantServeur(char adresseServeur[L], short portServeur) {


	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
	sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)
}

void Connexion::connexionAuServeur() {
	r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
																		// Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

	if (r == SOCKET_ERROR)
		throw Erreur("La connexion a �chou�");

	cout << "connexion au serveur de majuscule r�ussie" << endl;

	bool continuer;
	do
	{
		char requete[L];
		cout << "Tapez la cha�ne � mettre en majuscule ou tapez \"quitter\" : ";
		cin >> requete;
		continuer = strcmp(requete, "quitter") != 0;
		if (continuer) {
			strcat_s(requete, "\r\n");     // pour que le serveur r�ceptionne bien le message
			int l = strlen(requete);

			r = send(sock, requete, l, 0);             //------------------ envoi de la requ�te au serveur -------------------------------
														// envoie au plus  l octets
			if (r == SOCKET_ERROR)
				throw Erreur("�chec de l'envoi de la requ�te");
		}
	} while (continuer);

	r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la r�ception
														// renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

	if (r == SOCKET_ERROR)
		throw Erreur("la coupure de connexion a �chou�");


	r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
	if (r) throw Erreur("La fermeture du socket a �chou�");

	WSACleanup();
	cout << "arr�t normal du client" << endl;
}