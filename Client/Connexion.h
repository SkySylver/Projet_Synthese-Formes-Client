#pragma once
#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>

#pragma comment(lib, "ws2_32.lib") // sp�cifique � VISUAL C++

using namespace std;

#define L 200 // longueur max d'une cha�ne de caract�res

class Connexion
{
private:
	int r;
	WSADATA wsaData;        // structure contenant les donn�es de la librairie winsock � initialiser
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

