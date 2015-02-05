/*************************************************************************
                           Point -  description
                             -------------------
    début                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
Point Point::Move(const signed long &dx, const signed long &dy) 
{
// Algorithme : Method that move a point.
    x += dx;
    y += dy;
    return *this;
}
//----- Fin de Méthode

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
//----- Fin de Méthode

signed long Point::GetX() const
{
    return x;
}
//----- Fin de Méthode

signed long Point::GetY() const
{
    return y;
}
//----- Fin de Méthode

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

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
