/*************************************************************************
                           Point -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
Point Point::Move(const signed long &dx, const signed long &dy) 
{
// Algorithme : Method that move a point.
    x += dx;
    y += dy;
    return *this;
}
//----- Fin de M�thode

bool Point::IsInSelection(const Point &a, const Point &b)
{
// Algorithme : Method that verify if a point belongs to a selection.
//
    if ( x >= a.x && x <= b.x && y >= a.y && y <= b.y )
    {
    	return true;
    }
    else
    {
    	return false;
    }
}
//----- Fin de M�thode

signed long Point::GetX() const
{
    return x;
}
//----- Fin de M�thode

signed long Point::GetY() const
{
    return y;
}
//----- Fin de M�thode

//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & unPoint )
{
    x = unPoint.x;
    y = unPoint.y;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
} //----- Fin de Point (constructeur de copie)


Point::Point ( const signed long &a, const signed long &b )
// Algorithme : Save of x's and y's values.
//
{
    x = a;
    y = b;
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
