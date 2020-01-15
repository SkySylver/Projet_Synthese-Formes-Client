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