/*************************************************************************
                           Circle  -  description
                             -------------------
    début                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Circle> (fichier Circle.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Circle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Circle::Move(const signed long &dx, const signed long &dy)
// Algorithme : Call to point's Move method.
{
    center.Move(dx, dy);
}
//----- Fin de Méthode

bool Circle::IsInSelection(const Point &a, const Point &b)
// Algorithme : Call to point's IsInSelection method.
{
    return center.IsInSelection(Point(a).Move(radius, radius), Point(b).Move(-radius, -radius));
}
//----- Fin de Méthode

string Circle::ToString()
// Algorithme : Use of a stringstream to create a string equals to
//              input user's one.
{   
    stringstream sstm;
    sstm << "C " << name << " " << center.GetX() << " " << center.GetY() << " " << radius << "\r\n";
    string result = sstm.str();
    return result;
}
//----- Fin de Méthode

string Circle::Display()
// Algorithme : Use of a stringstream to create a string to describe a circle.
{   
    return "# Circle " + name + " of center (" +
           std::to_string(center.GetX()) + ", " +
           std::to_string(center.GetY()) + ") and radius " +
           std::to_string(radius) + " has been created.\r\n";
}
//----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Circle::Circle ( string name, signed long x, signed long y, int r ) : Figure(name), center(x, y)
// Algorithme : Call to Figure's constructor and creation of circle's center.
{
    radius = r;
#ifdef MAP
    cout << "Appel au constructeur de <Circle>" << endl;
#endif
} //----- Fin de Circle


Circle::~Circle ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Circle>" << endl;
#endif
} //----- Fin de ~Circle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées