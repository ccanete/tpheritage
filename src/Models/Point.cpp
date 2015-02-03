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
// type Point::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

Point Point::Move(signed long dx, signed long dy) 
{
// Algorithme :
//
    x += dx;
    y += dy;
    return *this;
}
//----- Fin de M�thode

bool Point::IsInSelection(const Point &a, const Point &b)
{
// Algorithme :
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
// Algorithme :
//
    return x;
}
//----- Fin de M�thode

signed long Point::GetY() const
{
// Algorithme :
//
    return y;
}
//----- Fin de M�thode
//------------------------------------------------- Surcharge d'op�rateurs
/*Point & Point::operator = ( const Point & unPoint )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & unPoint )
// Algorithme :
//
{
    x = unPoint.x;
    y = unPoint.y;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
} //----- Fin de Point (constructeur de copie)


Point::Point ( const signed long &a, const signed long &b )
// Algorithme :
//
{
    x = a;
    y = b;
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
