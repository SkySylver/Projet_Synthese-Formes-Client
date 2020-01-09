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
	WSADATA wsaData;        // structure contenant les données de la librairie winsock à initialiser
	SOCKET sock;
	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer
public:
	Connexion();
	~Connexion();
	void initWinsockLib();
	void creerSocket();
	void creerRepresentantServeur();
	void connexionAuServeur();
};

