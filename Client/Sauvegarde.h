#pragma once
#include "VisiteurSauvegarde.h"
#define DOSSIER "./Sauvegarde/"

using namespace std;

class Sauvegarde : public VisiteurSauvegarde{
private :
	int _num; //Pour nommer les fichiers, et avoir des noms différents
	void Ecriture(ostringstream &nomFichier, ostringstream &texte);
	int getFileNum(string str);

public:
	Sauvegarde() : VisiteurSauvegarde(){}

	void visite(const Cercle * forme);
	void visite(const Segment * forme);
	void visite(const Triangle * forme);
	void visite(const Polygone * forme);
	void visite(const FormeComposee * forme);
	
};
bool fexists(const char* filename);