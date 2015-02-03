/*************************************************************************
                           Circle  -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Circle> (fichier Circle.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Circle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Circle::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void Circle::Move(const signed long &dx, const signed long &dy)
// Algorithme :
//
{
	center.Move(dx, dy);
}
//----- Fin de M�thode

bool Circle::IsInSelection(const Point &a, const Point &b)
// Algorithme :
//
{
	return center.IsInSelection(Point(a).Move(radius, radius), Point(b).Move(-radius, -radius));
}
//----- Fin de M�thode

string Circle::ToString()
// Algorithme :
//
{   
    stringstream sstm;
    sstm << "C " << name << " " << center.GetX() << " " << center.GetY() << " " << radius << "\r\n";
    string result = sstm.str();
    cout << result;
    return result;
}
//----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
ostream& operator << ( ostream &flux, const Circle &c )
// Algorithme :
//
{
    cout << "OK\r\n";
    flux << "# Circle ";
    flux << c.name;
    flux << " of center (";
    flux << c.center.GetX();
    flux << ", ";
    flux << c.center.GetY();
    flux << ") and radius ";
    flux << c.radius;
    flux << " has been created.\r\n";
    return flux;
} //----- Fin de operator <<


//-------------------------------------------- Constructeurs - destructeur
/*Circle::Circle ( const Circle & unCircle )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Circle>" << endl;
#endif
} //----- Fin de Circle (constructeur de copie)
*/

Circle::Circle ( string name, signed long x, signed long y, int r ) : Figure(name), center(x, y)
// Algorithme :
//
{
    radius = r;
#ifdef MAP
    cout << "Appel au constructeur de <Circle>" << endl;
#endif
} //----- Fin de Circle


Circle::~Circle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Circle>" << endl;
#endif
} //----- Fin de ~Circle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
