#include "Erreur.h"
#include "Sauvegarde.h"
#include <fstream>
#include "Forme.h"
#include "io.h"
#include <stdio.h>

void Sauvegarde::Ecriture(ostringstream &nomFichier,ostringstream &texte)const{

	ostringstream Dossier;
	Dossier << "./Sauvegardes/";

	ofstream file(nomFichier.str());

	if (file.is_open()) file << texte.str();
	else throw Erreur("Impossible d'ouvrir le fichier");
	file.close();
}

bool fexists(const char* filename){
	ifstream ifile(filename);
	return (bool) ifile;
}

int getFileNum(string str) {
	int i = 0;
	string str2 = str;
	while(fexists(str2.c_str())){
		i++;
		str2 = str + to_string(i);
	}
	return i;
}

//version ecriture dans le fichier et non pas dans le titre
void Sauvegarde::visite(const Segment *forme) const{
	ostringstream nomFichier, contenu;
	nomFichier << "Segment" << getFileNum("Segment") << ".txt";
	contenu << "Segment," << forme->getCouleur() << "," << forme->getA().x << "," << forme->getA().y << "," << forme->getB().x << "," << forme->getB().y ;
    Sauvegarde::Ecriture(nomFichier, contenu);
}

void Sauvegarde::visite(const Cercle* forme) const {
	ostringstream nomFichier, contenu;
	nomFichier << "Cercle" << getFileNum("Cercle") << ".txt";
	contenu << "Cercle," << forme->getCouleur() << "," << forme->getCentre().x << "," << forme->getCentre().y << "," << forme->getRayon();
	Sauvegarde::Ecriture(nomFichier, contenu);
}

void Sauvegarde::visite(const Triangle* forme) const {
	ostringstream nomFichier, contenu;
	nomFichier << "Triangle" << getFileNum("Triangle") << ".txt";
	contenu << "Triangle," << forme->getCouleur() << "," << forme->getA().x << "," << forme->getA().y << "," << forme->getB().x << "," << forme->getB().y << "," << forme->getC().x << "," << forme->getC().y;
	Sauvegarde::Ecriture(nomFichier, contenu);
}

void Sauvegarde::visite(const Polygone* forme) const {
	ostringstream nomFichier, contenu;
	nomFichier << "Polygone" << getFileNum("Polygone");
	contenu << "Polygone," << forme->getCouleur();
	for (int i = 0; i < forme->getVecteurs().size(); i++) {
		contenu << "," << forme->getVecteurs().at(i).x << "," << forme->getVecteurs().at(i).y;
	}
	Sauvegarde::Ecriture(nomFichier, contenu);
}


//////////////////////////////////
/////////////////////////////////

void Sauvegarde::visite(const Segment *forme) const{
	ostringstream nomFichier, texte;

	nomFichier << "Segment;" << forme->getCouleur() << "," << forme->getA().x << "," << forme->getA().y << "," << forme->getB().x << "," << forme->getB().y << ".txt";

    Sauvegarde::Ecriture(nomFichier, texte);
}

void Sauvegarde::visite(const Cercle *forme) const{
	ostringstream nomFichier, texte;

	nomFichier << "Cercle;" << forme->getCouleur() << "," << forme->getCentre().x << "," << forme->getCentre().y << "," << forme->getRayon() << ".txt";

	Sauvegarde::Ecriture(nomFichier, texte);
}

void Sauvegarde::visite(const Triangle *forme) const{
	ostringstream nomFichier, texte;
//	nomFichier << "triangle" << _num << ".txt";

	nomFichier << "Triangle;" << forme->getCouleur() << "," << forme->getA().x << "," << forme->getA().y << "," << forme->getB().x << "," << forme->getB().y << "," << forme->getC().x << "," << forme->getC().y << ".txt";

	Sauvegarde::Ecriture(nomFichier, texte);
}

void Sauvegarde::visite(const Polygone *forme) const {
	ostringstream nomFichier, texte;
	nomFichier << "Polygone;" << forme->getCouleur();
	
	for (int i = 0; i < forme->getVecteurs().size(); i++) {
		nomFichier << "," << forme->getVecteurs().at(i).x << "," <<forme->getVecteurs().at(i).y << ".txt";
	}

	Sauvegarde::Ecriture(nomFichier, texte);
}

int majNum() {
	ostringstream Fichier;
	Fichier << "NumDossierCompose.txt";

//	ofstream()

}


void Sauvegarde::visite(const FormeComposee *forme) const{
	ostringstream nomFichier, texte;

	vector<Forme*> vecteurs = forme->getGroupe();
	vector<Forme*>::iterator iter;



	nomFichier << "./Sauvegardes/" << "FormeComposee," << forme->getCouleur() << "_" << _num << ".txt";
	iter = vecteurs.begin();

	if (_wmkdir(nomFichier.str()) == 0) {


	}
	while (iter != vecteurs.end()) {
		texte << (*iter)->Sauvegarder(new Sauvegarde(false));
		iter++;
	}

	return Sauvegarde::Ecriture(nomFichier, texte);
	
}