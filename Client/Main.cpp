#include "Connexion.h"

int main()
{

	WSADATA wsaData;
	int familleAdresse = AF_INET;
	int typeSocket = SOCK_STREAM;
	int protocole = IPPROTO_TCP;
	char adresseServeur[L] = "192.168.1.100";
	short portServeur = 6666;


	
	bool continuer;
	Connexion co(wsaData, familleAdresse, typeSocket, protocole, adresseServeur, portServeur);
	do
	{
		char requete[L];
		cin >> requete;

		continuer = strcmp(requete, "quitter") != 0;
		if (continuer) {
			co.requete(requete);
		}
	} while (continuer);

	co.arreter();
	return 0;
}
