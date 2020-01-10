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
	int r;
	SOCKET sock;
	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer
public:
	Connexion();
	~Connexion();
	void initWinsockLib(WSADATA wsaData);
	void creerSocket(int familleAdresse, int typeSocket, int protocole);
	void creerRepresentantServeur(char adresseServeur[L], short portServeur);
	void connexionAuServeur();
};

