#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") // spécifique à VISUAL C++

using namespace std;

#define L 200 // longueur max d'une chaîne de caractères

class Connexion
{
private:
	WSAData _wsaData;
	int _familleAdresse = AF_INET;
	int _typeSocket = SOCK_STREAM;
	int _protocole = IPPROTO_TCP;
	char _adresseServeur[L] = "192.168.1.100";
	short _portServeur = 6666;

	SOCKET _sock;
	SOCKADDR_IN _sockaddr; // informations concernant le serveur avec lequel on va communiquer
public:
	/**
	 * Constructeur par défaut
	 */
	Connexion(char adresseServeur[L], short portServeur);
	
	/**
	 * Constructeur avec paramétrage spécifique
	 *
	 */
	Connexion(WSADATA & wsaData, int familleAdresse, int typeSocket, int protocole, char adresseServeur[L], short portServeur);

	/**
	 * Destructeur
	 */
	~Connexion() {};

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
	 * @param portServeur : Port sur lequel la connexion est lancée
	 */
	void lancer(char adresseServeur[L], short portServeur);
	
	/**
	 * Envoie une requete au serveur
	 * @param requete : Requete a envoyer
	 */
	void requete(const char * requete) const;


	/*
	 * Arrete la connexion
	 */
	void arreter();
};