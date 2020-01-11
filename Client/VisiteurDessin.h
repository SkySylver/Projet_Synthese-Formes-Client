#pragma once
#include "Forme.h"
class VisiteurDessin
{
public:


	void visiteSegment(const Forme &);
	void visiteCercle(const Forme &);
	void visiteTriangle(const Forme &);
	void visitePolygone(const Forme &);


};

