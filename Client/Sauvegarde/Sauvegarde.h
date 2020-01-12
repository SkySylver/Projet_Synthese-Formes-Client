#pragma once
#include "../VisiteurSauvegarde.h"
using namespace std;

class Sauvegarde : public VisiteurSauvegarde{
	static int _incrementation;
public:
    /**Constructeur
	 * @param envoi de type bool : Verifie et indique si la chaine d�sirant �tre sauvegard� est a envoyer*/
	Sauvegarde(bool envoi = true) : VisiteurSauvegarde(envoi)  {
	    _incrementation = _incrementation + 1;
    }
    /**Evite la redondance de code dans les visiteurs, retourne un string et �crit dans un fichier*/
    const string Ecriture(bool sauvegarde,ostringstream &nomFichier,ostringstream &texte) const;
    /** Sauvegarde un cercle
	 * @param Forme de type cercle.
	 * @return Nom du fichier ou l'objet sous forme de string si l'envoi est inscrit comme faux*/
	const string visiteCercle(const Cercle * forme) const;
	/**M�me d�marche que pour le cercle*/
	const string visiteSegment(const Segment * forme) const;
	const string visiteTriangle(const Triangle * forme) const;
	const string visitePolygone(const Polygone * forme) const;
	const string visiteFormeComposee(const FormeComposee * forme) const;
	/** Stocke les valeurs d'une forme selon le type de forme */
	template<class T>
	const void StockageTriPoly(ostringstream &nomFichier,ostringstream &texte,const T *forme)const;
};
