#pragma once
#include "VisiteurSauvegarde.h"
using namespace std;

class Sauvegarde : public VisiteurSauvegarde{
public:
    int _num; //Pour nommer les fichiers, et avoir des noms différents
	Sauvegarde() : VisiteurSauvegarde()  {}
    void Ecriture(ostringstream &nomFichier,ostringstream &texte) const;

	void visite(const Cercle * forme) const;
	void visite(const Segment * forme) const;
	void visite(const Triangle * forme) const;
	void visite(const Polygone * forme) const;
	void visite(const FormeComposee * forme) const;
	
};
bool fexists(const char* filename);
int getFileNum(string str);