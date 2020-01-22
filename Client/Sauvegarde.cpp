#include "Erreur.h"
#include <Windows.h>
#include "Sauvegarde.h"
#include <fstream>
#include "io.h"


void Sauvegarde::Ecriture(ostringstream &nomFichier,ostringstream &texte){
	ostringstream fichier;
	_fichier << nomFichier.str();

	if (!fexists(_fichier.str().c_str())) {
		ofstream file(_fichier.str());
	/*
		if (file.is_open()) file << texte.str();
		else throw Erreur("Impossible d'ouvrir le fichier");
	*/
	file.close();
	}
}

bool fexists(const char* filename){
	ifstream ifile(filename);
	return (bool) ifile;
}

int Sauvegarde::getFileNum(string str) {
	int i = 0;
	string str2 = str;
	while(fexists(str2.c_str())){
		i++;
		str2 = str + to_string(i);
	}
	return i;
}

bool dirExists(const char* const path)
{
	struct stat info;

	int statRC = stat(path, &info);
	if (statRC != 0)
	{
		if (errno == ENOENT) { return false; } // something along the path does not exist
		if (errno == ENOTDIR) { return false; } // something in path prefix is not a dir
		return false;
	}

	return (info.st_mode & S_IFDIR) ? true : false;
}

void Sauvegarde::visite(const FormeComposee *forme) {

	ostringstream nomFichier, texte;

	vector<Forme*> vecteurs = forme->getGroupe();
	vector<Forme*>::iterator iter;

	nomFichier << "FormeComposee," << forme->getCouleur() << "_" << _num;


	if (CreateDirectory(nomFichier.str().c_str(), NULL)) {
		/*while (iter != vecteurs.end()) {
			texte << (*iter)->Sauvegarder(new Sauvegarde());
			*/
		for (unsigned int i = 0; i < vecteurs.size(); i++) vecteurs.at(i)->sauvegarder(this);
	}

	Sauvegarde::Ecriture(nomFichier, texte);
}

/*
void Sauvegarde::visite(const Segment *forme){
	ostringstream nomFichier, texte;

	nomFichier << "Segment;" << forme->getCouleur() << "," << forme->getA().x << "," << forme->getA().y << "," << forme->getB().x << "," << forme->getB().y << ".txt";

    Sauvegarde::Ecriture(nomFichier, texte);
}

void Sauvegarde::visite(const Cercle *forme){
	ostringstream nomFichier, texte;

	nomFichier << "Cercle;" << forme->getCouleur() << "," << forme->getCentre().x << "," << forme->getCentre().y << "," << forme->getRayon() << ".txt";

	Sauvegarde::Ecriture(nomFichier, texte);
}

void Sauvegarde::visite(const Triangle *forme){
	ostringstream nomFichier, texte;

	nomFichier << "Triangle;" << forme->getCouleur() << "," << forme->getA().x << "," << forme->getA().y << "," << forme->getB().x << "," << forme->getB().y << "," << forme->getC().x << "," << forme->getC().y << ".txt";
	texte << 

	Sauvegarde::Ecriture(nomFichier, texte);
}

void Sauvegarde::visite(const Polygone *forme) {
	ostringstream nomFichier, texte;
	nomFichier << "Polygone;" << forme->getCouleur();
	
	for (unsigned int i = 0; i < forme->getVecteurs().size(); i++) {
		nomFichier << "," << forme->getVecteurs().at(i).x << "," <<forme->getVecteurs().at(i).y;
	}
	nomFichier << ".txt";

	Sauvegarde::Ecriture(nomFichier, texte);
}
*/



//version ecriture dans le fichier et non pas dans le titre
void Sauvegarde::visite(const Segment *forme){

	ostringstream nomFichier, contenu;
	
	nomFichier << "Segment" << getFileNum("Segment") << ".txt";
	contenu << "Segment," << forme->getCouleur() << "," << forme->getA().x << "," << forme->getA().y << "," << forme->getB().x << "," << forme->getB().y ;
	
	Sauvegarde::Ecriture(nomFichier, contenu);
}

void Sauvegarde::visite(const Cercle* forme) {
	ostringstream nomFichier, contenu;

	nomFichier << "Cercle" << getFileNum("Cercle") << ".txt";
	contenu << "Cercle," << forme->getCouleur() << "," << forme->getCentre().x << "," << forme->getCentre().y << "," << forme->getRayon();

	Sauvegarde::Ecriture(nomFichier, contenu);
}

void Sauvegarde::visite(const Triangle* forme) {
	ostringstream nomFichier, contenu;

	nomFichier << "Triangle" << getFileNum("Triangle") << ".txt";
	contenu << "Triangle," << forme->getCouleur() << "," << forme->getA().x << "," << forme->getA().y << "," << forme->getB().x << "," << forme->getB().y << "," << forme->getC().x << "," << forme->getC().y;

	Sauvegarde::Ecriture(nomFichier, contenu);
}

void Sauvegarde::visite(const Polygone* forme) {
	ostringstream nomFichier, contenu;

	nomFichier << "Polygone" << getFileNum("Polygone");
	contenu << "Polygone," << forme->getCouleur();

	for (int i = 0; i < forme->getVecteurs().size(); i++) {
		contenu << "," << forme->getVecteurs().at(i).x << "," << forme->getVecteurs().at(i).y;
	}
	Sauvegarde::Ecriture(nomFichier, contenu);
}

/*
void Sauvegarde::visite(const FormeComposee *forme){
	ostringstream nomFichier, contenu;
	nomFichier << "./Sauvegardes/" << "FormeComposee" << getFileNum("FormeComposee") << ".txt";

	vector<Forme*> vecteurs = forme->getGroupe();
	vector<Forme*>::iterator it;

	contenu << "Forme Composee," << forme->getCouleur() << "," << endl;
	it = vecteurs.begin();
	while (it != vecteurs.end()) {
		(*it)->sauvegarder(new Sauvegarde());
		it++;
	}
	return Sauvegarde::Ecriture(nomFichier, contenu);
}
*/