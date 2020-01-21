#include "Forme.h"
#include "VisiteurServeur.h"
#include "Connexion.h"
#include "Erreur.h"
#include "Polygone.h"
#include "Sauvegarde.h"

using namespace std;

bool is_number(const string& s)
{
	char* end = 0;
	double val = strtod(s.c_str(), &end);
	return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

Vecteur2D saisirPoint(string n) {

	string x, y;
	double x1, y1;
	char * end = 0;
	do {
		cout << "Veuillez saisir x" << n << endl;
		cin >> x;

		cout << "Veuillez saisir y" << n << endl;
		cin >> y;

	} while (!is_number(x) && !is_number(y));
	end = 0;
	x1 = strtod(x.c_str(), &end);
	end = 0;
	y1 = strtod(x.c_str(), &end);

	Vecteur2D v(x1, y1);
	return v;

}

int main()
{
	Vecteur2D a(100, 100);
	Vecteur2D b(200, 200);
	Vecteur2D c(200, 200);
	Vecteur2D d(200, 4);


	vector<Vecteur2D> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);

	Segment G(a, b, "red");
	Triangle T(a, b, c, "blue");
	Cercle C(c, 150.00, "blue");
	Polygone P(v, "blue");
	//	Segment G(a, b, "blue");
//	Segment G(a, b, "blue");
	//P.dessiner(V);
	/*
	FormeComposee fc;
	fc.ajouterForme(&G);
	fc.dessiner(V);
	*/


	Sauvegarde * saver = new Sauvegarde();
	saver->visite(&G);
	saver->visite(&T);
	saver->visite(&C);
	saver->visite(&P);

	//	Co.requete("Segment;blue,10,10,100,100");
	//	Co.requete("Cercle;blue,10,10,100,100");
		//Co.requete("Polygone;black,100,100,100,200,300,300,400,300,500,500");


	getchar();
	return 0;
	/*

	WSAData _wsaData;
	string reponse;

	int _r;
	_r = WSAStartup(MAKEWORD(2, 0), &_wsaData);       // MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2

	if (_r) throw Erreur("L'initialisation a �chou�");



//	initWinsockLib(_wsaData);
	/*	WSADATA wsaData;
		int familleAdresse = AF_INET;
		int typeSocket = SOCK_STREAM;
		int protocole = IPPROTO_TCP;



	Forme * forme;
	string x, y;
	double xtemp;
	char * end;
	vector<Vecteur2D> v;
	int i = 0;
	Polygone* p = new Polygone(v);

	while (true) {
		
		cout << "Que souhaitez-vous faire :" << endl;
		cout << "1 : Creer FormeComposee" << endl;
		cout << "2 : Creer Segment" << endl;
		cout << "3 : Creer Polygone" << endl;
		cout << "4 : Creer Cercle" << endl;
		cout << "5 : Creer Triangle" << endl;

		cout << "6 : Creer Connexion" << endl;
		cout << "7 : Creer VisiteurServeur" << endl;

		cin >> reponse;

		switch (stoi(reponse)) {
		case 1:
			forme = new FormeComposee();
			break;
		case 2:
			forme = new Segment(saisirPoint("1"), saisirPoint("2"));
			break;
		case 3:			
			while(true) {
				cout << "Voulez-vous ajouter un point au vecteur ? (o/n)";
				cin >> reponse;
				
				if (strcmp(reponse.c_str(), "o")) break;

				p->ajouterVecteur(saisirPoint(to_string(i)));				
			}
			forme = p;
			break;
		case 4:
			cin >> reponse;
			xtemp = stoi(reponse);
			forme = new Cercle(saisirPoint("Centre"), xtemp);

//			saisirPoint

		}


			



	}



	char adresseServeur[L] = "10.11.85.253";
	short portServeur = 6666;


	Vecteur2D a(100, 100);
	Vecteur2D b(200, 200);
	Vecteur2D c(200,200);
	Vecteur2D d(200, 4);
	
	//Connexion Co(adresseServeur, portServeur);

	VisiteurServeur V(adresseServeur, portServeur);

	vector<Vecteur2D> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);

	Segment G(a, b, "red");
	Triangle T(a, b, c, "blue");
	Cercle C(c, 150.00, "blue");
	Polygone P(v, "blue");
	//	Segment G(a, b, "blue");
//	Segment G(a, b, "blue");
	//P.dessiner(V);
	FormeComposee fc;
	fc.ajouterForme(&G);
	fc.dessiner(V);

//	Co.requete("Segment;blue,10,10,100,100");
//	Co.requete("Cercle;blue,10,10,100,100");
	//Co.requete("Polygone;black,100,100,100,200,300,300,400,300,500,500");


	getchar();
	return 0;*/
}
