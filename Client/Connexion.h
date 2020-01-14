#pragma once
/**
 * Classe Connexion
 */

#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") // sp�cifique � VISUAL C++

using namespace std;

#define L 200 /// longueur max d'une cha�ne de caract�res

class Connexion
{
private:
	int _familleAdresse = AF_INET;
	int _typeSocket = SOCK_STREAM;
	int _protocole = IPPROTO_TCP;
	char _adresseServeur[L] = "192.168.1.100";
	short _portServeur = 6666;

	SOCKET _sock;
	SOCKADDR_IN _sockaddr; // informations concernant le serveur avec lequel on va communiquer
public:
	Connexion() {};

	/**
	 * Constructeur par d�faut
	 */
	Connexion(char adresseServeur[L], short portServeur);
	
	/**
	 * Constructeur avec param�trage sp�cifique
	 *
	 */
	Connexion(int familleAdresse, int typeSocket, int protocole, char adresseServeur[L], short portServeur);

	/**
	 * Destructeur
	 */
	void arreter();

	/**
	 * Initialise la librairie winsock
	 *
	 */
	void initWinsockLib(WSADATA & wsaData);
	
	/**
	 * Creer un socket pour ce client
	 * @param familleAdresse :
	 * @param typeSocket : Type du socket
	 * @param protocole : Protocole
	 *
	 */
	void creerSocket(int familleAdresse, int typeSocket, int protocole);
	
	/**
	 * Lance une connexion entre le client et le serveur
	 * @param adresseServeur : Adresse du serveur en format char *
	 * @param portServeur : Port sur lequel la connexion est lanc�e
	 */
	void lancer(char adresseServeur[L], short portServeur);
	
	/**
	 * Envoie une requete au serveur
	 * @param requete : Requete a envoyer
	 */
	void requete(string requete)const;

	/**
	 * Utilise pour la creation de Fenetre (S'utilise uniquement une fois dans le constructeur)
	 */
	void Fenetre();
};