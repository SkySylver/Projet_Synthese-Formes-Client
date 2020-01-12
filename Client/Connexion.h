#pragma once
#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>

#pragma comment(lib, "ws2_32.lib") // spécifique à VISUAL C++

using namespace std;

#define L 200 // longueur max d'une chaîne de caractères

class Connexion
{
private:
	WSADATA wsaData;
	int familleAdresse = AF_INET;
	int typeSocket = SOCK_STREAM;
	int protocole = IPPROTO_TCP;
	char adresseServeur[L] = "192.168.1.100";
	short portServeur = 6666;


	int _r;
	SOCKET _sock;
	SOCKADDR_IN _sockaddr; // informations concernant le serveur avec lequel on va communiquer
public:
	Connexion() {};
	Connexion(WSADATA & wsaData, int familleAdresse, int typeSocket, int protocole, char adresseServeur[L], short portServeur);

	~Connexion() {};
	void initWinsockLib(WSADATA & wsaData);
	void creerSocket(int familleAdresse, int typeSocket, int protocole);
	void lancer(char adresseServeur[L], short portServeur);
	void requete(char * requete);
	void arreter();
};