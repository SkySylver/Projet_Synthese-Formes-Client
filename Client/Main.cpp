#include "Forme.h"
#include "VisiteurServeur.h"
#include "Connexion.h"
#include "Erreur.h"
#include "Polygone.h"
#include "Sauvegarde/Sauvegarde.h"
#include "Singleton.h"
#include "Chargeur/ChargeurCercle.h"
#include "Chargeur/ChargeurSegment.h"
#include "Chargeur/ChargeurTriangle.h"
#include "Chargeur/ChargeurPolygone.h"


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
	Sauvegarde * saver = new Sauvegarde();
	vector<Vecteur2D> v;

	Vecteur2D a(100, 100);
	Vecteur2D b(100, 200);
	Vecteur2D c(200, 200);
	Vecteur2D d(200, 100);


	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);

	Triangle T(Vecteur2D(100, 300), Vecteur2D(100, 400), Vecteur2D(200, 400), "blue");
	Cercle C(c, 40, "blue");
	Polygone P(v, "blue");
	FormeComposee fc;
	fc.ajouterForme(&C);
	fc.ajouterForme(&P);
	fc.ajouterForme(&T);

	saver->visite(&T);
	saver->visite(&P);

	ChargeurCOR * charger = new ChargeurTriangle(new ChargeurCercle(new ChargeurSegment(NULL)));

	Forme * f = charger->Charger("Sauvegarde/Triangle0.txt");




	/*
	Singleton sing();
	cout << "Singleton initialisé !" << endl;


	int familleAdresse = AF_INET;
	int typeSocket = SOCK_STREAM;
	int protocole = IPPROTO_TCP;
	char adresseServeur[L] = "192.168.0.49";
	short portServeur = 6666;
	VisiteurServeur V(adresseServeur, portServeur);


	Forme * forme;
	string x, y, reponse;
	double xtemp;
	char * end;
	vector<Vecteur2D> v;
	int i = 0;
	Polygone* p = new Polygone(v);


	//EXEMPLE FORME COMPOSEE
	cout << "Requete dessin d'une forme composee." << endl;
	cout << "Forme composee dessinee." << endl;


	while (true) {
		cout << reponse;
		cout << "Que souhaitez-vous faire :" << endl;
		cout << "========= CREATIONS =========" << endl;
		cout << "1 : Cree Triangle" << endl;
		cout << "2 : Creer Segment" << endl;
		cout << "3 : Creer Polygone" << endl;
		cout << "4 : Creer Cercle" << endl;

		cin >> reponse;

		switch (stoi(reponse)) {
		case 1:
			forme = new Triangle(saisirPoint("3"), saisirPoint("2"), saisirPoint("1"));
			forme->dessiner(V);			
			break;
		case 2:
			forme = new Segment(saisirPoint("2"), saisirPoint("1"));
			forme->dessiner(V);
			break;
		case 3:

			while(true) {
				cout << "Voulez-vous ajouter un point au vecteur ? (o/n)";
				cin >> reponse;
				
				if (strcmp(reponse.c_str(), "o")) break;

				p->ajouterVecteur(saisirPoint(to_string(i)));				
			}
			forme = p;
			forme->dessiner(V);
			break;
		case 4:
			int rayon;
			cout << "Saisir le rayon du cercle";
			cin >> rayon;
			forme = new Cercle(saisirPoint("Centre"), rayon, "red");
			forme->dessiner(V);
		}
	}

		/*
		Sauvegarde * saver = new Sauvegarde();

		saver->visite(&G);
		/*
		saver->visite(&G);
		saver->visite(&T);

		//	Co.requete("Segment;blue,10,10,100,100");
		//	Co.requete("Cercle;blue,10,10,100,100");
			//Co.requete("Polygone;black,100,100,100,200,300,300,400,300,500,500");


		getchar();
		return 0;
		*/

}
