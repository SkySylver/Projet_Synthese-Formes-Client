#include "../Erreur.h"
#include "Sauvegarde.h"
/*
void Sauvegarde::Ecriture(ostringstream &nomFichier,ostringstream &texte)const{
		ofstream file(nomFichier.str());
		if (file.is_open())
			file << texte.str();
		else throw Erreur("Impossible d'ouvrir le fichier");
		file.close();
}

void Sauvegarde::visite(const Segment *forme) const{
	ostringstream nomFichier, texte;
	nomFichier << "segment" << _num << ".txt";

	texte << "Segment;" << forme->getA().x << "," << forme->getA().y << ",";
	texte << forme->getB().x << "," << forme->getB().y << ",";
	texte << forme->getCouleur() << "," << endl;

    Sauvegarde::Ecriture(_sauvegarde, nomFichier, texte);
    _num++;
}

void Sauvegarde::visite(const Cercle *forme) const{
	ostringstream nomFichier, texte;
	nomFichier << "cercle" << _num << ".txt";

	texte << "Cercle;"  << forme->getCentre().x << "," << forme->getCentre().y << ",";
    texte << forme->getRayon() << ",";
    texte << forme->getCouleur() << "," << endl;

	Sauvegarde::Ecriture(_sauvegarde, nomFichier, texte);
    _num++; 
}

void Sauvegarde::visite(const Triangle *forme) const{
	ostringstream nomFichier, texte;
	nomFichier << "triangle" << _num << ".txt";

	texte << "Triangle;"  << forme->getCentre().x << "," << forme->getCentre().y << ",";
    texte << forme->getA().x << "," << forme->getA().y << ",";
    texte << forme->getB().x << "," << forme->getB().y << ",";
    texte << forme->getC().x << "," << forme->getC().y << ",";

    _num++;
}

void Sauvegarde::visite(const Polygone *forme) const{/*
	ostringstream nomFichier, texte;

    A faire

	Sauvegarde::Ecriture(_sauvegarde, nomFichier, texte);
    _num++;
}
*/
void Sauvegarde::visite(const FormeComposee *forme) const{
	/*

    A faire

    */
}