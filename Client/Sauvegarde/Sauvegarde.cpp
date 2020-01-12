#include "../Erreur.h"
#include "Sauvegarde.h"

void Sauvegarde::Ecriture(ostringstream &nomFichier,ostringstream &texte)const{
		ofstream file(nomFichier.str());
		if (file.is_open())
			file << texte.str();
		else throw Erreur("Impossible d'ouvrir le fichier");
		file.close();
}

void Sauvegarde::visiteSegment(const Segment *forme) const{
	ostringstream nomFichier, texte;
	nomFichier << "segment" << _num << ".txt";

	texte << "Segment;" << forme->getA().x << "," << forme->getA().y << ",";
	texte << forme->getB().x << "," << forme->getB().y << ",";
	texte << forme->getCouleur() << "," << endl;

    Sauvegarde::Ecriture(nomFichier, texte);
    _num++;
}