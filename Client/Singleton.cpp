#include "Singleton.h"


Singleton Singleton::instance;

Singleton::Singleton() {
	WSAData _wsaData;
	if (WSAStartup(MAKEWORD(2, 0), &_wsaData)) throw Erreur("L'initialisation a échoué");
}


Singleton::~Singleton()
{
	WSACleanup();

}

Singleton& Singleton::getInstance() {
	return instance;
}